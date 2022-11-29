#include <iostream>
#include <string>
#include <algorithm>
#include "dirent.h"

#include "Node.hpp"
#include "ConvertExp.hpp"
#include "SaveFile.hpp"
#include "ExpGate.hpp"

using namespace std;

/*------------------------StepByStepSimulation----------------------------*/
int choixOneStep() {
    int res;
    cout << "Faut-il changer la valeur d'une entree ? " << endl;
    cout << "1 : Oui" << endl;
    cout << "2 : Non" << endl;
    cout << "3 : Quitter" << endl;
    cin >> res;
    cout << endl;
    return res;
}

string formatExp(string exp) {
    string res = exp.substr(4, exp.length());
    string aft = "";
    unsigned int i = 0;
    while (i < res.length()) {
        if (res.at(i) == 'n' && res.at(i + 1) == 'e' && res.at(i + 2) == 'g' && i + 2 < res.length()) {
            //neg found
            aft = aft + "negate";
            i = i + 2;
        } else {
            aft = aft + res.at(i);
        }
        i++;
    }
    return aft;
}

void oneStep(vector<pair<OutputGate *, int>> v, int depth, int max_depth, ExpGate &g) {
    unsigned int indice = 0;
    Node *n = nullptr;
    string exp;
    while (indice < v.size()) {
        pair<OutputGate *, int> &p = v.at(indice);
        if (p.second == depth) {
            exp = formatExp(p.first->printName());
            ConvertExp e{exp};
            exp = e.postFixExpression();
            ExpGate g2{' ', exp};
            g2.setInput(g.getInput());
            reverse(exp.begin(), exp.end());
            cout << "Le sous-circuit :" << depth << endl << endl;
            g2.printTree(n->treeExp(exp), nullptr, false);
            cout << g2 << endl << endl;
            int choix = -1;
            choix = choixOneStep();
            switch (choix) {
                case 1 : // oui
                    g.menuInput();
                    indice = -1;
                    // Repeat the step by step with the new inputs
                    depth = max_depth;
                    break;
                case 2 : // non
                    // We do onStep on a depth below
                    // Outside the for loop
                    break;
                case 3 :
                    exit(0);
                default :
                    cout << "Choix non reconnu" << endl;
            }
        }
        indice++;
    }
    // We did all the simulations on the depth subtree
    if (depth > 1) {
        // If we are not at the root
        depth = depth - 1;
        oneStep(v, depth, max_depth, g);
    } else {
        // We are at the root
        cout << g << endl;
        g.printTree(n->treeExp(exp), nullptr, false);
        cout << endl << "Fin de simulation pas a pas" << endl << endl;
    }
}

void StepByStepSimulation(string &expInput) {
    ConvertExp e{expInput};
    char outputName = e.getOutputChar();
    string expFinal = e.postFixExpression();
    // 0 = false;
    ExpGate g{outputName, expFinal};
    vector<pair<OutputGate *, int>> outputlist = g.getOutputList();
    int max = 0;
    for (pair<OutputGate *, int> &p : outputlist) {
        if (max < p.second) { max = p.second; }
    }
    oneStep(outputlist, max, max, g);
}
/*-------------------------------------------------------------------*/

/*------------------------createFromExp-----------------------------------*/
void expTreatment(Node *n, string &expInput, string &nameSave) {
    cout << "Votre expression :";
    cout << expInput << endl << endl;
    
    ConvertExp e{expInput};

    if (e.checkValidityExp()) {
        cout << "Expression invalide" << endl;
        return;
    }

    char outputName = e.getOutputChar();
    string expFinal = e.postFixExpression();

    ExpGate g{outputName, expFinal};
    g.menuInput();

    string expForPrint = e.postFixExpression();
    reverse(expForPrint.begin(), expForPrint.end());

    cout << "Le circuit :" << endl << endl;
    g.printTree(n->treeExp(expForPrint), nullptr, false);
    cout << endl << g << endl;
}

void createFromExp(string expSubmit) {
    Node *n = nullptr;// ?
    string expInput = expSubmit;
    string nameSave;
    SaveFile save;

    if (expInput.empty()) {
        cout << "Entrez votre expression :";
        cin >> expInput;
        cout << endl;
    }

    expTreatment(n, expInput, nameSave);
    int choix = -1;
    do {
        cout << endl << "Action disponibles :" << endl << endl;
        cout << "1 : Simulation pas à pas" << endl;
        cout << "2 : Sauvegarder" << endl;
        cout << "3 : Retour Menu" << endl;
        cout << "0 : Quitter" << endl;
        cout << "Votre Choix : ";
        cin >> choix;
        cout << endl;
        switch (choix) {
            case 0 :
                exit(0);
                break;
            case 1 :
                StepByStepSimulation(expInput);
                break;
            case 2 :
                cout << "Nom du fichier : ";
                cin >> nameSave;
                if (save.checkFile(nameSave)) {
                    perror("Ce fichier existe deja !");
                } else {
                    save.inputExpression(nameSave, expInput);
                    cout << "Fichier sauvegarde : " << nameSave << ".txt" << endl;
                }
                break;
            case 3 :
                break;
            default:
                cout << "Choix non reconnu" << endl;
        }
    } while ((choix != 3 && choix != 0));
}
/*------------------------------------------------------------------------*/


/*------------------------createFromFiles-----------------------------------*/
string printBackupFiles() {
    string res;
    cout << "Liste des fichiers disponibles :" << endl;
    DIR *dir;
    struct dirent *ent;
    if ((dir = opendir("backup")) != NULL) {
        /* print all the files and directories within directory */
        while ((ent = readdir(dir)) != NULL) {
            printf("%s\n", ent->d_name);
        }
        closedir(dir);
    } else {
        /* could not open directory */
        perror("");
    }
    cout << "0 : Retour Menu" << endl;
    cout << endl << "Choix ficher :";
    cin >> res;
    cout << endl;
    return res;
}

void printActionFromFiles() {
    cout << endl << "Action disponibles :" << endl << endl;
    cout << "1 : Generation Circuit" << endl;
    cout << "2 : Suppression Fichier" << endl;
    cout << "3 : Renommer Fichier" << endl;
    cout << "4 : Retour Menu" << endl;
    cout << "0 : Quitter" << endl << endl;
    cout << "Votre Choix : ";
    cout << endl;
}

void createFromFiles() {
    cout << endl << "------------ File Generation ------------" << endl << endl;

    int menu = 0;
    SaveFile save;
    string fileSelected;
    string newNameFileSelected;
    string expressionFromFile;

    // Print list of files
    fileSelected = printBackupFiles();
    if (fileSelected == "0") { return; }
    
    if(!save.checkFile(fileSelected)){
    cout<<"fichier inexistant"<<endl;
    return;
    }

    do {
        printActionFromFiles();
        cin >> menu;
        switch (menu) {
            case 0 :
                exit(0);
                break;
            case 1 :
                expressionFromFile = save.getExpression(fileSelected);
                createFromExp(expressionFromFile);
                break;
            case 2 :
                save.removeFile(fileSelected);
                return;
                break;
            case 3 :
                cout << "Choix nom ficher :";
                cin >> newNameFileSelected;
                save.renameFile(fileSelected, newNameFileSelected);
                break;
            case 4:
                break;
            default:
                cout << "Choix non reconnu" << endl;
        }
    } while (menu != 4);
}
/*-------------------------------------------------------------------*/

/*------------------------Menu---------------------------------------*/
int printAccueil() {
    int menu = -1;
    cout << endl << "------------ MENU ------------" << endl << endl;
    cout << "1 : Generation via formule" << endl;
    cout << "2 : Fichiers sauvegardes" << endl;
    cout << "0 : Quitter" << endl << endl;
    cout << "Votre Choix : ";
    cin >> menu;
    cout << endl;
    return menu;
}

void menu() {
    int accueil = -1;
    do {
        accueil = printAccueil();
        switch (accueil) {
            case 0 :
                break;
            case 1 :
                createFromExp("");
                break;
            case 2 :
                createFromFiles();
                break;
            default:
                cout << "Choix non reconnu" << endl;
        }
    } while (accueil != 0);
}

/*-------------------------------------------------------------------*/

int main() {
    menu();
}
