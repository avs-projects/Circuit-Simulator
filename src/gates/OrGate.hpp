#ifndef ORGATE_HPP
#define ORGATE_HPP

#include "../Gate.hpp"
#include <iostream>

using namespace std;

class OrGate : public Gate {
public:
    OrGate(Gate *l, Gate *r);

    virtual ~OrGate();

    //return result of left OR right
    bool evaluate() override;

    string printName() override;
};

#endif // ORGATE_HPP