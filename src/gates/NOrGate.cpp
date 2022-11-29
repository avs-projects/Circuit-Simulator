#include "NOrGate.hpp"

NOrGate::NOrGate(Gate *l, Gate *r) : Gate(l, r) {
    //ctor
}

NOrGate::~NOrGate() {
    //dtor
}

bool NOrGate::evaluate() {
    bool l = left->evaluate();
    bool r = right->evaluate();
    return !(l || r);
}

string NOrGate::printName()
{
    string l = left->printName();
    string r = right->printName();
    return string{"nor("+l+","+r+")"};
}
