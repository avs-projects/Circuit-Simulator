#ifndef TRUNK_HPP
#define TRUNK_HPP

#include <iostream>

using namespace std;

class ExpGate;

class Node;

class Trunk {
private:
    Trunk *previous;
    string value;
public:

    Trunk(Trunk *previous, string value);
    
    static void showTrunks(Trunk *print);
    
    friend ExpGate;
    friend Node;
};

#endif // OUTPUTGATE_HPP
