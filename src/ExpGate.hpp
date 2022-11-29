#ifndef PROJECTC___EXPGATE_HPP
#define PROJECTC___EXPGATE_HPP


#include <iostream>
#include <cctype>
#include <vector>
#include "ConvertExp.hpp"
#include "Gate.hpp"
#include "./gates/includeGate.hpp"
#include "Node.hpp"
#include "Trunk.hpp"


using namespace std;

class ExpGate {
private :
    vector<pair<InputGate *, char>> input;
    vector<pair<OutputGate *, int>> outputList;
    OutputGate *out;
    int ind;

    char name;

		// Recursively build the circuit in out
		// And fills outputList
    Gate *rec_Gate(string exp, int depth);

		// Build the list of inputs from the expression
    vector<pair<InputGate *, char>> getAllInput(string exp);
    // Affiche la liste des inputs du circuit
    void printInput();
    // Execute menu choice
    void choixInput(int x);

public :
    ExpGate(char name, string exp);


    OutputGate *getOutput();

    string getName();

    vector<pair<InputGate *, char>> getInput();
    vector<pair<OutputGate *, int>> getOutputList();
    // Updates the value of the inputs in the input list from that of v
    void setInput(vector<pair<InputGate*, char>> v);
    // Input menu management
    // Poster - Execute the choice
    void menuInput();

    string inputValue(char x);
		
		// Displays the circuit
    void printTree(Node *root, Trunk *prev, bool isLeft);
};

ostream &operator<<(ostream &out, ExpGate &e);

#endif //PROJECTC___EXPGATE_HPP
