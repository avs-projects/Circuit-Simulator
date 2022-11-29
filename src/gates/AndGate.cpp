#include "AndGate.hpp"

AndGate::AndGate(Gate *l, Gate *r) : Gate(l, r) {
    //ctor
}

AndGate::~AndGate() {
    //dtor
}

bool AndGate::evaluate() {
    bool l = left->evaluate();
    bool r = right->evaluate();
    return (l && r);
}

string AndGate::printName()
{
    string l = left->printName();
    string r = right->printName();
    return string{"and("+l+","+r+")"};
}
