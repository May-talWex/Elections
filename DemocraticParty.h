#ifndef ASSIGNMENT5_DEMOCRATICPARTY_H
#define ASSIGNMENT5_DEMOCRATICPARTY_H

#include "Party.h"

/*
 * Democratic Party class - inherits from Party class
 */
class DemocraticParty: public Party {
public:
    // Constructor
    DemocraticParty(string partyName);
    // Destructor
    virtual ~DemocraticParty(){}
    // Add a democratic politician
    virtual status addDemocraticPolitician(Politician* politician);
    //add a republican politician - in this class this function always returns a FAILURE status
    virtual status addRepublicanPolitician(Politician* politician) { return FAILURE; }
    //get the size of the democratic party
    virtual int democraticPartySize() { return politicians.size();}
    //get the size of the republican party - in this class this function always returns -1
    virtual int republicanPartySize() { return -1; }
    //print the democratic party
    virtual void print() const;
};

#endif //ASSIGNMENT5_DEMOCRATICPARTY_H
