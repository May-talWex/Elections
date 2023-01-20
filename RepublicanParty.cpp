#include "RepublicanParty.h"

RepublicanParty::RepublicanParty(string partyName) : Party(partyName) {
}


void RepublicanParty::print() const{
    cout<< "Republican ";
    Party::print();
}

status RepublicanParty::addRepublicanPolitician(Politician* politician) {
    if (politician == nullptr) {
        return FAILURE;
    }
    else if(politician->getPower() > maxPower && politician->isSuitableForPrimaries()){
        maxPower = politician->getPower();
    }

    politicians.push_back(politician);
    return SUCCESS;
}
