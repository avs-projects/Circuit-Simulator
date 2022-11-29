#ifndef NODE_HPP
#define NODE_HPP

#include "Trunk.hpp"

using namespace std;

class ExpGate;

class Node {
private:
    char expSuite;
    Node *left;
    Node *right;
public:
		// Checks if x is an operator
    static bool isOperator(char x);
		// Convert an operator x by its text
    static string switchOperator(char x);

    Node(char expSuite, Node *left = nullptr, Node *right = nullptr);
		// Build the tree using exp
    static Node *treeExp(const string &exp);

    friend ExpGate;
};

#endif // NODE_HPP
