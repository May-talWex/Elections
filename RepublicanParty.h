#ifndef ASSIGNMENT5_REPUBLICANPARTY_H
#define ASSIGNMENT5_REPUBLICANPARTY_H

#include "Party.h"

/*
 * RepublicanParty class - inherits from Party class
 */
class RepublicanParty: public Party {
public:
    // Constructor
    RepublicanParty(string partyName);
    //Destructor
    virtual ~RepublicanParty(){}
    // Function that adds a politician to a democratic party - always returns a FAILURE status for this class
    virtual status addDemocraticPolitician(Politician* politician){return FAILURE;}
    // Function that adds a politician to a republican party
    virtual status addRepublicanPolitician(Politician* politician);
    //Function that returns the democratic parties size - in this class always set to -1
    virtual int democraticPartySize() { return -1; }
    //Function that returns the republican parties size
    virtual int republicanPartySize() { return politicians.size(); }
    //Print the Republican Party
    virtual void print() const;
};


#endif //ASSIGNMENT5_REPUBLICANPARTY_H
