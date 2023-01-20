#include "DemocraticParty.h"


DemocraticParty::DemocraticParty(string partyName) : Party(partyName) {
}

void DemocraticParty::print() const{
    cout<< "Democrat ";
    Party::print();

}

status DemocraticParty::addDemocraticPolitician(Politician* politician) {
    if (politician == nullptr) {
        return FAILURE;
    }
    else if
        ((politician->getPower()>maxPower) && (politician->isSuitableForPrimaries())){
        maxPower = politician->getPower();
    }

    politicians.push_back(politician);
    return SUCCESS;
}
