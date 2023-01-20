#ifndef ASSIGNMENT5_PARTY_H
#define ASSIGNMENT5_PARTY_H

#include "Politician.h"

class Politician;

/*
 * Party class - represents a political party, inherits from Politician
 */
class Party {
    string name;
    static int counter;

protected:
    vector<Politician*> politicians;
    int maxPower;
public:
    Politician* politicianChairman;
    int id;
    // Constructor
    Party(string partyName);
    //Destructor
    virtual ~Party(){politicians.clear();};
    // Copy Constructor
    Party(const Party &other);
    //Add a politician to a democratic party - defined in the inherited classes
    virtual status addDemocraticPolitician(Politician* politician)=0;
    //Add a politician to a republican party - defined in the inherited classes
    virtual status addRepublicanPolitician(Politician* politician)=0;
    //Function that removes a politician from a party
    status removePolitician(Politician* politician);
    //Function that performs the primaries - checks which leader politician has the highest power
    status primaries();
    //Function that returns the total power of a party
    int totalPartyPower();
    //Function that returns the size of a democratic party - defined in the inherited classes
    virtual int democraticPartySize()=0;
    //Function that returns the size of a republican party - defined in the inherited classes
    virtual int republicanPartySize()=0;
    //Function that returns the name of a party
    string partyName();
    //Function that returns the size of a party
    int partySize();
    //Function that returns the chairman of the party
    Politician* partyChairman();
    //print party
    virtual void print() const=0;
    //Function that goes over all politicians and updates their chairman after primaries
    void notify();
    //Function to delete a politician from the politicians vector
    vector<Politician*> deletePolitician();


};

#endif //ASSIGNMENT5_PARTY_H
