#include "DemocraticLeaderPolitician.h"


void DemocraticLeaderPolitician::addToDemocraticParty(Party* party){
    if (this->party != nullptr)
    {
        Party* oldParty = this->party;
        oldParty->removePolitician(this);
    }
    if (party->addDemocraticPolitician(this) == FAILURE)
        return;
    this->party = party;
    this->chairman = party->partyChairman();
}



void DemocraticLeaderPolitician::print() const{
    cout<< "Democratic ";
    LeaderPolitician::print();
}