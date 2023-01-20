#include "RepublicanSocialPolitician.h"

void RepublicanSocialPolitician::print() const{
    cout<< "Republican ";
    SocialPolitician::print();
}

void RepublicanSocialPolitician::addToRepublicanParty(Party* party){
    if (this->party != nullptr){
        Party* oldParty = this->party;
        oldParty->removePolitician(this);
    }
    if ( party->addRepublicanPolitician(this) == FAILURE){
        return;
    }
    this->party = party;
    this->chairman = party->partyChairman();
}
