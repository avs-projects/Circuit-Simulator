#include "OrGate.hpp"

OrGate::OrGate(Gate *l, Gate *r) : Gate(l, r) {
    //ctor
}

OrGate::~OrGate() {
    //dtor
}

bool OrGate::evaluate() {
    bool l = left->evaluate();
    bool r = right->evaluate();
    return (l | r);
}

string OrGate::printName()
{
    string l = left->printName();
    string r = right->printName();
    return string{"or("+l+","+r+")"};
}

