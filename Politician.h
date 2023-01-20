#ifndef ASSIGNMENT5_POLITICIAN_H
#define ASSIGNMENT5_POLITICIAN_H

#include <vector>
#include <iostream>
#include <string>
#include "Error.h"
using namespace std;
enum status {SUCCESS, FAILURE, IDErr, nameErr, dataErr};
#include "Party.h"
class Party;

/*
 * This class represents a politician. Inherits the Party class.
 */
class Politician {
    string firstname;
    string lastname;
    int id;
    int power;
    static int counter;
    int tenure;

protected:
    Party* party;
    Politician* chairman;
public:
    // Constructor
    Politician(string firstName, string lastName, int ID, int power);
    //Destructor
    virtual ~Politician(){}
    // Copy Constructor
    Politician(const Politician &other);
    // Print the chairman of the politician
    void printChairman() const;
    // Get the name of the politician
    string getName();
    // Get the ID of the politician
    int getId();
    // Get the power of the politician
    int getPower();
    // Get the party of the politician
    Party* getParty();
    // Set the party of the politician
    void setParty(Party* party);
    //function defined in the inheriting classes of Politician - check if the politician can run for primaries
    virtual bool isSuitableForPrimaries() = 0;
    //function that updates the chairman of the politician after new chairman is elected
    void updateChairman(Politician* newchair);
    //function defined in the inheriting classes of Politician - adds a new politician to a democratic party
    virtual void addToDemocraticParty(Party* party) = 0;
    //function defined in the inheriting classes of Politician - adds a new politician to a republican party
    virtual void addToRepublicanParty(Party* party) = 0;
    //function defined in the inheriting classes of Politician - prints the politician's details
    virtual void print()const=0;
    //equal operator
    Politician& operator=(const Politician &other);

};





#endif //ASSIGNMENT5_POLITICIAN_H



