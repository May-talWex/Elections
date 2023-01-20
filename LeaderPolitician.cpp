#include "LeaderPolitician.h"

void LeaderPolitician::print() const{
    Politician::print();
    cout<< "Type:L, ";
    Politician::printChairman();
}

