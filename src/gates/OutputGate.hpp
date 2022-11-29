#ifndef OUTPUTGATE_HPP
#define OUTPUTGATE_HPP

#include "../Gate.hpp"
#include <iostream>
#include <cctype>
using namespace std;


class OutputGate : public Gate
{
private :
    char name;
public:
    OutputGate(char n, Gate* g);
    virtual ~OutputGate();

    //return result of left
    bool evaluate() override;
    //print [name = left]
    string printName() override;
};

#endif // OUTPUTGATE_HPP
