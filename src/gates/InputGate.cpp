#include "InputGate.hpp"

InputGate::InputGate(char n, bool value)
{
    //ctor
    name = n;
    output = value;
}

InputGate::~InputGate()
{
    //dtor
}

void InputGate::changeValue()
{
    output = !output;
}

bool InputGate::evaluate()
{
    return output;
}

string InputGate::printName()
{
    char c = tolower(name);
    return string{c};
}

