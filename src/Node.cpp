#include "Node.hpp"
#include "stack"

Node::Node(char expSuite, Node *left, Node *right) : expSuite(expSuite), left(left), right(right) {
}

bool Node::isOperator(char x) {
    switch (x) {
        case '|':
        case '+':
        case '$':
        case '%':
        case '#':
        case '-':
            return true;
    }
    return false;
}

Node *Node::treeExp(const string &exp) {
    stack<Node *> stackTree;
    for (char ch: exp) {
        if (ch == '!') {
            auto n_left = stackTree.top();
            stackTree.pop();
            stackTree.push(new Node(ch, n_left, nullptr));
        } else if (isOperator(ch)) {
            auto n_left = stackTree.top();
            stackTree.pop();
            auto n_right = stackTree.top();
            stackTree.pop();
            stackTree.push(new Node(ch, n_left, n_right));
        } else
            stackTree.push(new Node(ch));
    }
    return stackTree.top();
}

string Node::switchOperator(char x) {
    switch (x) {
        case '|':
            return "OR";
        case '+':
            return "AND";
        case '$':
            return "NOR";
        case '%':
            return "XOR";
        case '#':
            return "NXOR";
        case '-':
            return "NAND";
        case '!':
            return "NEG";
    }
    return string(1, x);
}



