#ifndef ASSIGNMENT5_REPUBLICANLEADERPOLITICIAN_H
#define ASSIGNMENT5_REPUBLICANLEADERPOLITICIAN_H

#include "LeaderPolitician.h"

/*
 * Class that reprisents a Republican Leader Politician - inherites from the Leader Politician class
 */
class RepublicanLeaderPolitician : public LeaderPolitician {
public:
    // Constructor
    RepublicanLeaderPolitician(string firstName, string lastName, int ID, int power): LeaderPolitician(firstName, lastName, ID, power){}
    // Destructor
    virtual ~RepublicanLeaderPolitician(){}
    //print the Republican Leader Politician
    virtual void print() const;
    // add the Republican Leader Politician to the Democratic Party - function isn't relevant to this class, defined as empty
    virtual void addToDemocraticParty(Party* party){}
    // add the Republican Leader Politician to the Republican Party
    virtual void addToRepublicanParty(Party* party);
};


#endif //ASSIGNMENT5_REPUBLICANLEADERPOLITICIAN_H
