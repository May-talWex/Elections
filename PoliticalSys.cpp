#include <list>
#include "PoliticalSys.h"

/*************************************************************Helper class for sort function on vector*****************************************************/
class partyCompare {
public:
    bool operator()(Party *p1, Party *p2) {
        if (p1->partySize() == p2->partySize())
            return p1->partyName() > p2->partyName();
        else
            return p1->partySize() > p2->partySize();
    }
};

/*************************************************************PoliticalSys definition*****************************************************/
PoliticalSys::PoliticalSys(char *&fileName) { //constructor
    ifstream file;
    bool politicianFlag = true;
    bool partyFlag = false;
    string line;
    file.open(fileName);
    if (file.is_open()) { //read from file
        while (getline(file, line)) {
            list<string> currentLine = stringToList(line);
            list<string>::iterator it = currentLine.begin();
            if (line.rfind("Politicians", 0) == 0) {
                continue;
            }
            if (line.rfind("Parties", 0) == 0) {
                politicianFlag = false;
                partyFlag = true;
                continue;
            }
            if (politicianFlag) {
                string firstName = *it;
                it++;
                string lastName = *it;
                it++;
                int id = stoi(*it);
                it++;
                int power = stoi(*it);
                it++;
                char partyType = *it->c_str();
                it++;
                char politicianType = *it->c_str();

                /*************************************************adding politician*************************************************/

                Politician *politician;
                if (politicianType == 'L') {
                    if (partyType == 'D') {
                        politician = new DemocraticLeaderPolitician(firstName, lastName, id, power);
                        if (politician == nullptr)
                            abort;

                        for (auto &party: parties) {
                            if (politician->getParty() == nullptr ||
                                politician->getParty()->partySize() > party->partySize()) {
                                politician->addToDemocraticParty(party);
                            }
                        }
                    } else {
                        politician = new RepublicanLeaderPolitician(firstName, lastName, id, power);
                        if (politician == nullptr)
                            abort;

                        for (auto &party: parties) {
                            if (politician->getParty() == nullptr ||
                                politician->getParty()->partySize() > party->partySize()) {
                                politician->addToRepublicanParty(party);
                            }
                        }
                    }

                } else {
                    if (partyType == 'D') {
                        politician = new DemocraticSocialPolitician(firstName, lastName, id, power);
                        if (politician == nullptr)
                            abort;

                        for (auto &party: parties) {
                            if (politician->getParty() == nullptr ||
                                politician->getParty()->partySize() > party->partySize()) {
                                politician->addToDemocraticParty(party);
                            }
                        }
                    } else {
                        politician = new RepublicanSocialPolitician(firstName, lastName, id, power);
                        if (politician == nullptr)
                            abort;

                        for (auto &party: parties) {
                            if (politician->getParty() == nullptr ||
                                politician->getParty()->partySize() > party->partySize()) {
                                politician->addToRepublicanParty(party);
                            }
                        }
                    }
                }
                politicians.push_back(politician);
                sort(partiesCopy.begin(), partiesCopy.end(), partyCompare());
            }
            /****************************************************adding party***********************************************/
            if (partyFlag) {
                string partyName = *it;
                it++;
                char partyType = *it->c_str();
                Party *party;
                if (partyType == 'D') {
                    party = new DemocraticParty(partyName);
                    if (party == nullptr)
                        abort;
                } else {
                    party = new RepublicanParty(partyName);
                    if (party == nullptr)
                        abort;
                }
                parties.push_back(party);
                partiesCopy.push_back(party);
                sort(partiesCopy.begin(), partiesCopy.end(), partyCompare());

                for (auto &politician: politicians) {
                    if (politician->getParty() == nullptr || politician->getParty()->partySize() > party->partySize()) {
                        if (partyType == 'D') {
                            politician->addToDemocraticParty(party);
                        } else {
                            politician->addToRepublicanParty(party);
                        }
                    }

                }
            }
        }
    }
    file.close();
}

PoliticalSys::~PoliticalSys() { //destructor
    for (auto &politician: politicians) {
        delete (politician);
    }
    for (auto &party: parties) {
        delete (party);
    }
    politicians.clear();
    parties.clear();
    partiesCopy.clear();
}

status PoliticalSys::addPolitician() { //add politician to correct party
    cout << "---Create Politician---" << endl;
    string firstName, lastName;
    int id, power;
    char partyType, politicianType;
    cout << "First name:" << endl;
    cin >> firstName;
    cout << "Last name:" << endl;
    cin >> lastName;
    cout << "ID:" << endl;
    cin >> id;
    cout << "Power:" << endl;
    cin >> power;
    cout << "Republican or Democratic person" << endl;
    cin >> partyType;
    cout << "Leader or Social" << endl;
    cin >> politicianType;
    try {
        if (!isValidName(firstName) || !isValidName(lastName) || !isValidID(id) || !isValidPower(power) || !isValidPartyType(partyType) || !isValidPoliticianType(politicianType)) {
            throw dataErr;
        }
    } catch (Error &e) {
        e.handle();
        addPolitician();
    }
    Politician *politician;
    if (politicianType == 'L') {
        if (partyType == 'D') {
            politician = new DemocraticLeaderPolitician(firstName, lastName, id, power);
            if (politician == nullptr)
                abort;

            for (auto &party: parties) {
                if (politician->getParty() == nullptr ||
                    politician->getParty()->partySize() > party->partySize()) {
                    politician->addToDemocraticParty(party);
                }
            }
        } else {
            politician = new RepublicanLeaderPolitician(firstName, lastName, id, power);
            if (politician == nullptr)
                abort;

            for (auto &party: parties) {
                if (politician->getParty() == nullptr ||
                    politician->getParty()->partySize() > party->partySize()) {
                    politician->addToRepublicanParty(party);
                }
            }
        }

    } else {
        if (partyType == 'D') {
            politician = new DemocraticSocialPolitician(firstName, lastName, id, power);
            if (politician == nullptr)
                abort;

            for (auto &party: parties) {
                if (politician->getParty() == nullptr ||
                    politician->getParty()->partySize() > party->partySize()) {
                    politician->addToDemocraticParty(party);
                }
            }
        } else {
            politician = new RepublicanSocialPolitician(firstName, lastName, id, power);
            if (politician == nullptr)
                abort;

            for (auto &party: parties) {
                if (politician->getParty() == nullptr ||
                    politician->getParty()->partySize() > party->partySize()) {
                    politician->addToRepublicanParty(party);
                }
            }
        }
    }
    politicians.push_back(politician);
    sort(partiesCopy.begin(), partiesCopy.end(), partyCompare());
    return SUCCESS;
}

status PoliticalSys::addParty() { //add new party
    cout << "----Create Party----" << endl;
    string partyName;
    char partyType;
    cout << "Party name:" << endl;
    cin >> partyName;
    cout << "Republican or Democratic party" << endl;
    cin >> partyType;
    try {
        if (!isValidName(partyName) || !isValidPartyType(partyType)) {
            throw dataErr;
        }
    } catch (Error &e) {
        e.handle();
        addParty();
    }
    Party *party;
    if (partyType == 'D') {
        party = new DemocraticParty(partyName);
        if (party == nullptr)
            abort;
    } else {
        party = new RepublicanParty(partyName);
        if (party == nullptr)
            abort;
    }
    parties.push_back(party);
    for (auto &politician: politicians) {
        if (politician->getParty() == nullptr || politician->getParty()->partySize() > party->partySize()) {
            if (partyType == 'D') {
                politician->addToDemocraticParty(party);
            } else {
                politician->addToRepublicanParty(party);
            }
        }

    }
    partiesCopy.push_back(party);
    sort(partiesCopy.begin(), partiesCopy.end(), partyCompare());
    return SUCCESS;
}

status PoliticalSys::removePolitician() { //remove politician from system
    cout << "----Remove Politician----" << endl;
    int id;
    cout << "Enter the ID:" << endl;
    cin >> id;
    try {
        if (!isValidID(id)) {
            throw dataErr;
        }
    } catch (Error &e) {
        e.handle();
        removePolitician();
    }
    Politician *pPolitician;
    for (auto & party : parties){
        for (auto & politician : politicians){
            if (politician->getId() == id){
                pPolitician = politician;
            }
        }
        if (pPolitician != nullptr){
            party->removePolitician(pPolitician);
            break;
        }
    }
    for (int k = 0; k < politicians.size(); k++) {
        if (politicians[k]->getId() == id) {
            politicians.erase(politicians.begin() + k);
            sort(partiesCopy.begin(), partiesCopy.end(), partyCompare());
            return SUCCESS;
        }
    }
    return FAILURE;
}

status PoliticalSys::removeParty() { //remove party from system
    vector<Politician *> politiciansToRemove;
    cout << "---Remove Party---" << endl;
    string partyName;
    cout << "Enter party name:" << endl;
    cin >> partyName;
    try {
        if (!isValidName(partyName)) {
            throw dataErr;
        }
    } catch (Error &e) {
        e.handle();
        removeParty();
    }
    try {
        bool found = false;
        for (auto & party : parties){
            if (party->partyName() == partyName){
                found = true;
                break;
            }
        }
        if (!found){
            throw dataErr;
        }
    }catch(Error &e) {
        e.handle();
        removeParty();
    }
    int i;
    for (i = 0; i < parties.size(); i++) {
        if (parties[i]->partyName() == partyName) {
            politiciansToRemove = parties[i]->deletePolitician();
            break;
        }
    }
    for (int j = 0; j < partiesCopy.size(); j++){
        if (partiesCopy[j]->partyName() == partyName){
            partiesCopy.erase(partiesCopy.begin() + j);
        }
    }
    delete parties[i];
    parties.erase(parties.begin() + i);

    for (auto & k : politiciansToRemove){
        for (auto & party : parties){
            if (k->getParty() == nullptr || k->getParty()->partySize()){
                k->addToDemocraticParty(party);
                k->addToRepublicanParty(party);
            }
        }
    }
    sort(partiesCopy.begin(), partiesCopy.end(), partyCompare());
    politiciansToRemove.clear();
    return SUCCESS;

}

void PoliticalSys::elections(){ //elections function
    cout << "----Primaries----" << endl;
    for (auto & party : parties){
        party->primaries();
    }
    cout << "----Elections----" << endl;
    int max = 0, partyIndex = 0;
    Party *winningParty;
    for (auto & party : parties){
        cout << "Party: " << party->partyName() << ",Power: ";
        partyIndex = party->totalPartyPower();
        cout << partyIndex << endl;
        if (partyIndex > max){
            max = partyIndex;
            winningParty = party;
        }
    }
    cout << "----Elections Results----" << endl;
    cout << winningParty->partyName() << " party won the elections and ";
    if (winningParty->partyChairman()){
        cout << winningParty->partyChairman()->getName() << " is the prime minister" << endl;
    }
    else{
        cout << "None is the prime minister" << endl;
    }
}

void PoliticalSys::printPoliticians() { //print all politicians
    cout << "----Politicians----" << endl;
    for (auto & politician : politicians) {
        politician->print();
    }
}

void PoliticalSys::printParties() { //print all parties
    cout << "----Parties----" << endl;
    for (auto & party : parties) {
        party->print();
    }
}

void PoliticalSys::BiggestParty(){ //print the biggest party
    cout << "----Biggest Party----" << endl;
    if ( partiesCopy.empty() || partiesCopy[0]->partySize() == 0){
        cout << "[None,0]" << endl;
        return;
    }
    else{
        cout << "[" << partiesCopy[0]->partyName() << "," << partiesCopy[0]->partySize() << "]" << endl;
    }
}

/*****************************************************validation functions for catching errors*****************************************************/
bool PoliticalSys::isValidName(string name) {
    return name.find_first_of("0123456789") == string::npos;
}

bool PoliticalSys::isValidPower(int num) {
    return num > 0;
}

bool PoliticalSys::isValidPartyType(char partyType) {
    return partyType == 'D' || partyType == 'R';
}

bool PoliticalSys::isValidPoliticianType(char politicianType) {
    return politicianType == 'L' || politicianType == 'S';
}

bool PoliticalSys::isValidID(int id) {
    string idStr = to_string(id);
    return !politicianExists(id) && id > 0 && idStr.find_first_not_of("0123456789") == string::npos;
}

/*****************************************************helper functions*****************************************************/

bool PoliticalSys::politicianExists(int id) {
    for (auto & politician : politicians) {
        if (politician->getId() == id) {
            return true;
        }
    }
    return false;
}

list<string> PoliticalSys::stringToList(string line) {
    list<string> list;
    string word;
    for (char i : line) {
        if (i == ' ') {
            list.push_back(word);
            word = "";
        } else {
            word += i;
        }
    }
    list.push_back(word);
    return list;
}

