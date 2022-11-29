#include "ConvertExp.hpp"

ConvertExp::ConvertExp() {

}

ConvertExp::ConvertExp(string expressionBefore) {
    expression = expressionBefore;
}

string ConvertExp::postFixExpression() {
    std::vector<std::string> terms{"negate", "nand", "nxor", "xor", "nor", "and", "or"};
    std::vector<std::string> terms2{"!", "-", "#", "%", "$", "+", "|"};


    for (unsigned long i = 0; i < terms.size(); ++i)
        while (expression.find(terms.at(i)) != std::string::npos) {
            findAndReplaceAll(expression, terms.at(i), terms2.at(i));
        };

    std::vector<std::string> deleteOthers{"(", ")", ",", " "};

    for (auto &deleteOther : deleteOthers) {
        findAndRemoveAll(expression, deleteOther);
    }

    size_t pos = expression.find("="); //find location of word
    expression.erase(0, pos + 1);

    return expression;
}

void ConvertExp::findAndReplaceAll(string &data, std::string toSearch, std::string replaceStr) {
    size_t pos = data.find(toSearch);

    while (pos != std::string::npos) {

        data.replace(pos, toSearch.size(), replaceStr);

        pos = data.find(toSearch, pos + replaceStr.size());
    }
}

void ConvertExp::findAndRemoveAll(string &data, std::string toRemove) {
    for (char c: toRemove) {
        data.erase(std::remove(data.begin(), data.end(), c), data.end());
    }
}

char ConvertExp::getOutputChar() {
    char c = expression[0];
    if (isalpha(c)) { return c; }
    return ' ';
}

bool ConvertExp::checkValidityExp() {
    char comma = ',';
    char negate = '!';
    int countComma;
    int countGates = 0;
    int countNegate = 0;
    int countAlpha = 0;

    std::vector<std::string> terms{"negate", "nand", "nxor", "xor", "nor", "and", "or"};
    std::vector<std::string> terms2{"!", "-", "#", "%", "$", "+", "|"};
    for (unsigned long i = 0; i < terms.size(); ++i)
        while (expression.find(terms.at(i)) != std::string::npos) {
            findAndReplaceAll(expression, terms.at(i), terms2.at(i));
        };

    countComma = count(expression.begin(), expression.end(), comma);

    for (char i : expression) {
        if (isOperator(i)) {
            ++countGates;
        }
        if (i == negate) {
            ++countNegate;
        }
        if (isalpha(i)) {
            ++countAlpha;
        }
    }

    if (countComma != countGates || countNegate > countAlpha) {
        return true;
    }

    return false;
}

bool ConvertExp::isOperator(char x) {
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
