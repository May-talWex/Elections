#ifndef ASSIGNMENT5_POLITICALSYS_H
#define ASSIGNMENT5_POLITICALSYS_H

#include "Error.h"
#include "Party.h"
#include "Politician.h"
#include "DemocraticParty.h"
#include "RepublicanParty.h"
#include "DemocraticLeaderPolitician.h"
#include "DemocraticSocialPolitician.h"
#include "RepublicanLeaderPolitician.h"
#include "RepublicanSocialPolitician.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <list>

/*
 * This class represents the political system.
 * There are a few functionalities that are implemented here such as:
 * adding a party, adding a politician, elections and more (see the functions below).
 */
class PoliticalSys {
    //politicians, party and a copy of parties vectors
    vector<Politician*> politicians;
    vector<Party*> parties;
    vector<Party*> partiesCopy;
public:
    //constructor
    PoliticalSys(char *&fileName);
    //destructor
    virtual ~PoliticalSys();
    //add a politician to the system
    status addPolitician();
    //add a party to the system
    status addParty();
    //remove a politician from the system
    status removePolitician();
    //remove a party from the system
    status removeParty();
    //elections, within this function the chairman of the party is chosen (Primaries) and then the winning party is chosen
    void elections();
    //print all the politicians in the system
    void printPoliticians();
    //print all the parties in the system
    void printParties();
    //print the biggest party in the system
    void BiggestParty();
    //helper function - convert string to list
    list<string> stringToList(string line);
    //validation function - check if name entered is valid
    bool isValidName(string name);
    //validation function - check if power entered is a valid int
    bool isValidPower(int num);
    //validation function - check if party name entered is valid
    bool isValidPartyType(char partyType);
    //validation function - check if politician type entered is valid
    bool isValidPoliticianType(char politicianType);
    //validation function - check if politician id entered is valid
    bool isValidID(int id);
    //helper function - check if a politician is in the system
    bool politicianExists(int id);
};

#endif //ASSIGNMENT5_POLITICALSYS_H
