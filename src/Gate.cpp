#include "Gate.hpp"

Gate::Gate()
{
    right = nullptr;
    left = nullptr;
}

Gate::Gate(Gate* l, Gate* r)
{
    //ctor
    right = r;
    left = l;
}


Gate::~Gate()
{
    //dtor
}

bool Gate::evaluate()
{
    throw string("Gate Operator Not Defined");
    //std::cout<<"Gate Operator Not Defined"<<std::endl;
}
string Gate::printName()
{
    throw string("Gate can't be printed");
}

