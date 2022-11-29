#include "OutputGate.hpp"

OutputGate::OutputGate(char n, Gate* g) : Gate(g, nullptr)
{
    //ctor
    name = n;
}

OutputGate::~OutputGate()
{
    //dtor
}

bool OutputGate::evaluate()
{
    return left->evaluate();
}

string OutputGate::printName()
{
    string l = left->printName();

    char c = toupper(name);
    string s{string{c}+" = "+l};
    return s;
}

