#ifndef NXORGATE_HPP
#define NXORGATE_HPP

#include "../Gate.hpp"
#include <iostream>

using namespace std;

class NXOrGate : public Gate {
public:
    NXOrGate(Gate *l, Gate *r);

    virtual ~NXOrGate();

    //return result of left NXOR right
    bool evaluate() override;

    string printName() override;
};

#endif // NXORGATE_HPP
