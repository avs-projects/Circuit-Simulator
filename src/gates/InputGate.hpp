#ifndef INPUTGATE_HPP
#define INPUTGATE_HPP

#include "../Gate.hpp"
#include <iostream>

using namespace std;

class InputGate : public Gate
{
private :
    char name;
    bool output;
public:
    InputGate(char n, bool value=false);
    virtual ~InputGate();


    //if output = true then output -> false
    void changeValue();
    //return output
    bool evaluate () override;
    //print [name]
    string printName() override;
};

#endif // INPUTGATE_HPP