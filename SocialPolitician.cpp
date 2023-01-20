#include "SocialPolitician.h"

void SocialPolitician::print() const{
    Politician::print();
    cout<< "Type:S, ";
    Politician::printChairman();
}
