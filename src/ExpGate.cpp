#include "ExpGate.hpp"

ExpGate::ExpGate(char nameF, string exp) {
    ind = -1;
    input = getAllInput(exp);
    out = new OutputGate(nameF, rec_Gate(exp, 1));
    ind = -1;
    name = nameF;
}

vector<pair<InputGate *, char>> ExpGate::getAllInput(string exp) {
    vector<pair<InputGate *, char>> res;
    for (unsigned int i = 0; i < exp.size(); i++) {
        if (isalpha(exp.at(i))) {
            bool found = false;
            for (pair<InputGate *, char> &list : res) {
                if (list.second == exp.at(i)) {
                    found = true;
                }
            }
            if (!found) {
                // If there is no input with the character then we add it
                res.push_back(make_pair(new InputGate(exp.at(i)), exp.at(i)));
            }
        }
    }
    return res;
}

Gate *ExpGate::rec_Gate(string exp, int depth) {
    ind = ind + 1;
    Gate *res;
    switch (exp.at(ind)) {
        case '!' : // negate
            res = new NegateGate(rec_Gate(exp, depth + 1));
            outputList.push_back(make_pair(new OutputGate(' ', res), depth));
            return res;
        case '-' : // nand
            res = new NAndGate(rec_Gate(exp, depth + 1), rec_Gate(exp, depth + 1));
            outputList.push_back(make_pair(new OutputGate(' ', res), depth));
            return res;
        case '#' : // nxor
            res = new NXOrGate(rec_Gate(exp, depth + 1), rec_Gate(exp, depth + 1));
            outputList.push_back(make_pair(new OutputGate(' ', res), depth));
            return res;
        case '%' : // xor
            res = new XOrGate(rec_Gate(exp, depth + 1), rec_Gate(exp, depth + 1));
            outputList.push_back(make_pair(new OutputGate(' ', res), depth));
            return res;
        case '$' : // nor
            res = new NOrGate(rec_Gate(exp, depth + 1), rec_Gate(exp, depth + 1));
            outputList.push_back(make_pair(new OutputGate(' ', res), depth));
            return res;
        case '+' : // and
            res = new AndGate(rec_Gate(exp, depth + 1), rec_Gate(exp, depth + 1));
            outputList.push_back(make_pair(new OutputGate(' ', res), depth));
            return res;
        case '|' : // or
            res = new OrGate(rec_Gate(exp, depth + 1), rec_Gate(exp, depth + 1));
            outputList.push_back(make_pair(new OutputGate(' ', res), depth));
            return res;
        default :
            if (!isalpha(exp.at(ind))) {
                // we don't have a letter or a door
                throw string("Not Supported Character" + exp.at(ind));
            } else {
                // letter
                for (pair<InputGate *, char> &list : input) {
                    if (list.second == exp.at(ind)) {
                        // If we find the corresponding input then we return it
                        res = list.first;
                    }
                }
                return res;
            }
    }
}

OutputGate *ExpGate::getOutput() {
    return out;
}

string ExpGate::getName() {
    return string(1, name);
}

vector<pair<InputGate *, char>> ExpGate::getInput() {
    return input;
}

vector<pair<OutputGate *, int>> ExpGate::getOutputList() {
    return outputList;
}

void ExpGate::setInput(vector<pair<InputGate *, char>> v) {
    for (pair<InputGate *, char> &p:input) {
        for (pair<InputGate *, char> &p2:v) {
            if (p.second == p2.second) {
                if (p.first->evaluate() != p2.first->evaluate()) {
                    p.first->changeValue();
                }
            }
        }
    }
}

void ExpGate::printInput() {
    int count = 1;
    for (pair<InputGate *, char> &list : input) {
        cout << count << " : " << list.second << " = " << list.first->evaluate() << endl;
        count++;
    }
    cout << "0 : Retour" << endl;
}

void ExpGate::menuInput() {
    int x = -1;
    do {
        cout << "------------------------------" << endl;
        cout << "------------ MENU ------------" << endl;
        cout << "--- Quelle valeur changer ----" << endl;
        printInput();
        cout << "Choix :";
        cin >> x;
        cout << "------------------------------" << endl;
        choixInput(x);
    } while (x != 0);
}

void ExpGate::choixInput(int x) {
    if (x == 0) {

    } else if (x > 0 && x <= (int) input.size()) {
        // Changer la valeur de l'input choisieChange the value of the chosen input
        // -1 car choix commence a partir de 1
        input.at(x - 1).first->changeValue();
        cout << "Valeur de " << input.at(x - 1).second << " change (" << input.at(x - 1).first->evaluate() << ")"
             << endl;
    } else {
        cout << "Choix non connue" << endl;
    }
}

void ExpGate::printTree(Node *root, Trunk *prev, bool isLeft) {

    if (!root) return; // If null return

    string prev_str = "          ";

    Trunk *trunk = new Trunk(prev, prev_str);

    printTree(root->right, trunk, true);

    if (!prev)
        trunk->value = to_string(getOutput()->evaluate()) + " : " + getName() + " -";
    else if (isLeft) {
        trunk->value = "---";
        prev_str = "         |";
    } else {
        trunk->value = "---";
        prev->value = prev_str;
    }

    Trunk::showTrunks(trunk);

    cout << " " << root->switchOperator(root->expSuite) + inputValue(root->expSuite)
         << endl; // Space between line and character

    if (prev) prev->value = prev_str;

    trunk->value = "         |";

    printTree(root->left, trunk, false);
}

string ExpGate::inputValue(char x) {

    for (unsigned int i = 0; i < getInput().size(); i++) {
        if (getInput().at(i).second == x) {
            return " : " + to_string(getInput().at(i).first->evaluate());
        }
    }
    return "";
}


ostream &operator<<(ostream &out, ExpGate &e) {
    if (e.getOutput()->printName()[0] == ' ') { out << "A"; }
    out << e.getOutput()->printName() << " = " << boolalpha << e.getOutput()->evaluate();
    return out;
}


