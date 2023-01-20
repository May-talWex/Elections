#ifndef ASSIGNMENT5_LEADERPOLITICIAN_H
#define ASSIGNMENT5_LEADERPOLITICIAN_H

#include "Politician.h"

/*
 * This class represents a leader politician. Inherits the Politician class.
 */
class LeaderPolitician: public Politician {
public:
    // Constructor
    LeaderPolitician(string firstName, string lastName, int ID, int power):Politician(firstName, lastName, ID, power){}
    // Destructor
    virtual ~LeaderPolitician(){}
    // bool function that checks if the politician is suitable for primaries (always true - only leader politicians can run for primaries)
    virtual bool isSuitableForPrimaries() { return true; }
    //print function
    virtual void print() const=0;
    //add to democratic party function - defined in inheriting classes
    virtual void addToDemocraticParty(Party* party) = 0;
    //add to republican party function - defined in inheriting classes
    virtual void addToRepublicanParty(Party* party) = 0;
};


#endif //ASSIGNMENT5_LEADERPOLITICIAN_H
