#ifndef XORGATE_HPP
#define XORGATE_HPP

#include "../Gate.hpp"
#include <iostream>

using namespace std;

class XOrGate : public Gate {
public:
    XOrGate(Gate *l, Gate *r);

    virtual ~XOrGate();

    //return result of left XOR right
    bool evaluate() override;

    string printName() override;
};

#endif // XORGATE_HPP
