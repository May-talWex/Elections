#ifndef ASSIGNMENT5_SOCIALPOLITICIAN_H
#define ASSIGNMENT5_SOCIALPOLITICIAN_H
#include "Politician.h"

/*
 * SocialPolitician class - inherits from the Politician class
 */
class SocialPolitician: public Politician {
public:
    // Constructor
    SocialPolitician(string firstName, string lastName, int ID, int power):Politician(firstName, lastName, ID, power){}
    // Destructor
    virtual ~SocialPolitician(){}
    //Function that checks if the politician is suitable for running for a chairman position - always returns false for this class
    virtual bool isSuitableForPrimaries() { return false; }
    //print the politician
    virtual void print() const=0;
    //Function that adds a politician to a democratic party
    virtual void addToDemocraticParty(Party* party) = 0;
    //Function that adds a politician to a republican party
    virtual void addToRepublicanParty(Party* party) = 0;
};

#endif //ASSIGNMENT5_SOCIALPOLITICIAN_H
