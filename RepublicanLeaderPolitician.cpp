#include "RepublicanLeaderPolitician.h"

void RepublicanLeaderPolitician::addToRepublicanParty(Party* party){
    if (this->party != nullptr)
    {
        Party* oldParty = this->party;
        oldParty->removePolitician(this);
    }
    if (party->addRepublicanPolitician(this) == FAILURE)
        return;
    this->party = party;
    this->chairman = party->partyChairman();
}



void RepublicanLeaderPolitician::print() const{
    cout<< "Republican ";
    LeaderPolitician::print();
}