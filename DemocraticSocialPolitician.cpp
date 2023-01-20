#include "DemocraticSocialPolitician.h"

void DemocraticSocialPolitician::addToDemocraticParty(Party* party){
    if (this->party != nullptr){
        Party* oldParty = this->party;
        oldParty->removePolitician(this);
    }
    if ( party->addDemocraticPolitician(this) == FAILURE){
        return;
    }
    this->party = party;
    this->chairman = party->partyChairman();
}

void DemocraticSocialPolitician::print() const{
    cout<< "Democratic ";
    SocialPolitician::print();
}
