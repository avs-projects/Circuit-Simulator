#include "Trunk.hpp"

Trunk::Trunk(Trunk *prev, string val) {
    this->previous = prev;
    this->value = val;
}

void Trunk::showTrunks(Trunk *prt) {
    if (!prt) return;
    showTrunks(prt->previous);
    cout << prt->value;
}
