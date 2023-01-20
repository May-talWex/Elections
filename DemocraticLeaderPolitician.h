#ifndef ASSIGNMENT5_DEMOCRATICLEADERPOLITICIAN_H
#define ASSIGNMENT5_DEMOCRATICLEADERPOLITICIAN_H

#include "LeaderPolitician.h"

/*
 * This class represents a Democratic Leader Politician. Inherits the LeaderPolitician class.
 */
class DemocraticLeaderPolitician : public LeaderPolitician {
public:
    // Constructor
    DemocraticLeaderPolitician(string firstName, string lastName, int ID, int power): LeaderPolitician(firstName, lastName, ID, power){}
    // Destructor
    virtual ~DemocraticLeaderPolitician(){}
    //print the politician's details
    virtual void print() const;
    //add a new politician to a democratic party
    virtual void addToDemocraticParty(Party* party);
    //add a new politician to a republican party - empty function for this class - defined in the Republican Politicians class
    virtual void addToRepublicanParty(Party* party){}
};


#endif //ASSIGNMENT5_DEMOCRATICLEADERPOLITICIAN_H
