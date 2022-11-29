#include "NXOrGate.hpp"

NXOrGate::NXOrGate(Gate *l, Gate *r) : Gate(l, r) {
    //ctor
}

NXOrGate::~NXOrGate() {
    //dtor
}

bool NXOrGate::evaluate() {
    bool l = left->evaluate();
    bool r = right->evaluate();
    return !(l ^ r);
}

string NXOrGate::printName()
{
    string l = left->printName();
    string r = right->printName();
    return string{"nxor("+l+","+r+")"};
}
