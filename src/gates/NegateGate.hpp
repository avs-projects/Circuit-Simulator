#ifndef NEGATEGATE_HPP
#define NEGATEGATE_HPP

#include "../Gate.hpp"
#include <iostream>

using namespace std;

class NegateGate : public Gate {
public:
    NegateGate(Gate *l);

    virtual ~NegateGate();

    //return result of NOT left 
    bool evaluate() override;

    string printName() override;
};

#endif // NEGATEGATE_HPP
