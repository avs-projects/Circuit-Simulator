#ifndef NANDGATE_HPP
#define NANDGATE_HPP

#include "../Gate.hpp"
#include <iostream>

using namespace std;

class NAndGate : public Gate {
public:
    NAndGate(Gate *l, Gate *r);

    virtual ~NAndGate();

    //return result of left NAND right
    bool evaluate() override;

    string printName() override;
};

#endif // NANDGATE_HPP
