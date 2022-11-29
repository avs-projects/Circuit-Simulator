#include "NAndGate.hpp"

NAndGate::NAndGate(Gate *l, Gate *r) : Gate(l, r) {
    //ctor
}

NAndGate::~NAndGate() {
    //dtor
}

bool NAndGate::evaluate() {
    bool l = left->evaluate();
    bool r = right->evaluate();
    return !(l && r);
}

string NAndGate::printName()
{
    string l = left->printName();
    string r = right->printName();
    return string{"nand("+l+","+r+")"};
}
