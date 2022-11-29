#ifndef PROJECTC___ANDGATE_HPP
#define PROJECTC___ANDGATE_HPP

#include "../Gate.hpp"
#include <iostream>

using namespace std;

class AndGate : public Gate {
public:
    AndGate(Gate *l, Gate *r);

    virtual ~AndGate();

    //return result of left AND right
    bool evaluate() override;

    string printName() override;
};


#endif //PROJECTC___ANDGATE_HPP

