#ifndef ASSIGNMENT5_DEMOCRATICSOCIALPOLITICIAN_H
#define ASSIGNMENT5_DEMOCRATICSOCIALPOLITICIAN_H

#include "SocialPolitician.h"

/*
 * This class represents a Democratic Social Politician. Inherits the SocialPolitician class.
 */
class DemocraticSocialPolitician: public SocialPolitician {
public:
    // Constructor
    DemocraticSocialPolitician(string firstName, string lastName, int ID, int power): SocialPolitician(firstName, lastName, ID, power){}
    // Destructor
    virtual ~DemocraticSocialPolitician(){}
    //Print the politician's details
    virtual void print() const;
    // Add a new politician to a democratic party
    virtual void addToDemocraticParty(Party* party);
    // Add a new politician to a republican party - defined as empty function here
    virtual void addToRepublicanParty(Party* party){}

};

#endif //ASSIGNMENT5_DEMOCRATICSOCIALPOLITICIAN_H
