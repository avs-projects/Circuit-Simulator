#ifndef PROJECTC___EXPRESSION_HPP
#define PROJECTC___EXPRESSION_HPP

#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

class ConvertExp {

private:
    string expression;
    
    // finds and replaces occurrences of toSearch with replaceStr in data
    void findAndReplaceAll(std::string &data, std::string toSearch, std::string replaceStr);
		// finds and deletes occurrences of toRemove in data
    void findAndRemoveAll(std::string &data, std::string toRemove);
		// remove the spaces
    string removeSpaces(string str);
public:

    ConvertExp();

    ConvertExp(string expressionBefore);

		// Returns the postfix reading of the circuit
    string postFixExpression();
    
    char getOutputChar();
		// checks if the expression is valid
    bool checkValidityExp();
		// checks if x is an operator
    static bool isOperator(char x);
};


#endif //PROJECTC___EXPRESSION_HPP
