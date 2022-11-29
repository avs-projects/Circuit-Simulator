#include "XOrGate.hpp"

XOrGate::XOrGate(Gate *l, Gate *r) : Gate(l, r) {
    //ctor
}

XOrGate::~XOrGate() {
    //dtor
}

bool XOrGate::evaluate() {
    bool l = left->evaluate();
    bool r = right->evaluate();
    return (l ^ r);
}

string XOrGate::printName()
{
    string l = left->printName();
    string r = right->printName();
    return string{"xor("+l+","+r+")"};
}
