#include "Party.h"

int Party::counter = 0;

Party::Party(string partyName) {
    counter++;
    this->name = partyName;
    this->id = counter++;
    this->politicianChairman = nullptr;
    this->maxPower = 0;
}

Party::Party(const Party &other) {
    this->name = other.name;
    this->id = other.id;
    this->politicianChairman = other.politicianChairman;
    this->maxPower = other.maxPower;
    this->politicians = other.politicians;
}


status Party::primaries() {
    int tempPower = 0;
    Politician* tempPolitician = nullptr;
    bool chairmanFound = false;
    for (auto &politician: politicians)
        if ((politician->getPower() > tempPower) && (politician->isSuitableForPrimaries())) {
            tempPower = politician->getPower();
            chairmanFound = true;
            tempPolitician = politician;
        }
    if (chairmanFound){
        politicianChairman = tempPolitician;
        notify();
        cout << tempPolitician->getName() << " is the chairman of " << name << endl;
        return SUCCESS;
    }
    cout << "None is the chairman of " << name << endl;
    return FAILURE;
}

int Party::totalPartyPower() {
    int totalPower = 0;
    for (auto &politician: politicians)
        if (!politician->isSuitableForPrimaries()) {
            totalPower += 2 * politician->getPower();
        } else {
            totalPower += politician->getPower();
        }
    return totalPower;
}

string Party::partyName() {
    return name;
}

int Party::partySize() {
    return politicians.size();
}

Politician *Party::partyChairman() {
    return politicianChairman;
}

void Party::notify() {
    for (auto &politician: politicians)
        politician->updateChairman(politicianChairman);
}

vector<Politician *> Party::deletePolitician() {
    for (auto & politician : politicians) {
        politicianChairman = nullptr;
        notify();
        politician->setParty(nullptr);
    }
    return politicians;
}

status Party::removePolitician(Politician *politician) {
    if (politician == nullptr) {
        return FAILURE;
    } else if (politician == politicianChairman) {
        politicianChairman = nullptr;
        notify();
    }
    for (int i = 0; i < politicians.size(); i++) {
        if (politicians[i]->getId() == politician->getId()) {
            politicians.erase(politicians.begin() + i);
            break;
        }
    }
    if (politician->getPower() == maxPower) {
        maxPower = 0;
        for (int i = 0; i < politicians.size(); i++) {
            if (politicians[i] == nullptr) {
                politicians.erase(politicians.begin() + i);
            }
            if (politicians[i]->getPower() > maxPower && politicians[i]->isSuitableForPrimaries()) {
                maxPower = politician[i].getPower();
            }

        }
    }
    return SUCCESS;
}

void Party::print() const {
    cout << "Party: " << name << ", " << "chairman:";
    if (politicianChairman)
        cout << politicianChairman->getName();
    else
        cout << "None";
    cout << ", Size:" << politicians.size() << endl;
    for (auto politician: politicians) {
        cout << "\t";
        politician->print();
    }
}

