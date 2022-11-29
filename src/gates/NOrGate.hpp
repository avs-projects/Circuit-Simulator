#ifndef NORGATE_HPP
#define NORGATE_HPP

#include "../Gate.hpp"
#include <iostream>

using namespace std;

class NOrGate : public Gate {
public:
    NOrGate(Gate *l, Gate *r);

    virtual ~NOrGate();

    //return result of left NOR right
    bool evaluate() override;

    string printName() override;
};

#endif // NORGATE_HPP
