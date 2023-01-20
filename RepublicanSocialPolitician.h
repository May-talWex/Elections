#ifndef ASSIGNMENT5_REPUBLICANSOCIALPOLITICIAN_H
#define ASSIGNMENT5_REPUBLICANSOCIALPOLITICIAN_H

#include "SocialPolitician.h"

/*
 * RepublicanSocialPolitician is a class that represents a Republican Social Politician - inherits from SocialPolitician
 */
class RepublicanSocialPolitician: public SocialPolitician {
public:
    // Constructor
    RepublicanSocialPolitician(string firstName, string lastName, int ID, int power): SocialPolitician(firstName, lastName, ID, power){}
    // Destructor
    virtual ~RepublicanSocialPolitician(){}
    //Print the politician
    virtual void print() const;
    // Add the politician to a Democratic Party - not relevant to this class
    virtual void addToDemocraticParty(Party* party) {}
    // Add the politician to a Republican Party
    virtual void addToRepublicanParty(Party* party);
};

#endif //ASSIGNMENT5_REPUBLICANSOCIALPOLITICIAN_H
