#ifndef GATE_HPP
#define GATE_HPP

#include <iostream>

using namespace std;

class InputGate;

class OutputGate;

class OrGate;

class AndGate;

class NAndGate;

class NOrGate;

class NegateGate;

class XOrGate;

class NXOrGate;

class Gate {
private:
    Gate *right;
    Gate *left;
    
public:
    Gate();

    Gate(Gate *l, Gate *r);

    virtual ~Gate();

    //return result of left GateOp right
    //Here throw
    virtual bool evaluate();

    virtual string printName();

    friend InputGate;
    friend OutputGate;
    friend OrGate;
    friend AndGate;
    friend NAndGate;
    friend NOrGate;
    friend NegateGate;
    friend XOrGate;
    friend NXOrGate;
};

#endif // GATE_HPP
