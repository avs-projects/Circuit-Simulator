#include "NegateGate.hpp"

NegateGate::NegateGate(Gate *l) : Gate(l, nullptr) {
    //ctor
}

NegateGate::~NegateGate() {
    //dtor
}

bool NegateGate::evaluate() {
    bool l = left->evaluate();
    return !(l);
}

string NegateGate::printName() {
    string l = left->printName();
    return string{"neg(" + l + ")"};
}

