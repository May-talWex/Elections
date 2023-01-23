#include "Politician.h"
int Politician::counter = 0;

Politician::Politician(string firstName, string lastName, int ID, int power){
    counter++;
    this->firstname = firstName;
    this->lastname = lastName;
    this->id = ID;
    this->power = power;
    this->party = nullptr;
    this->chairman = nullptr;
    this->tenure = counter;
}

Politician::Politician(const Politician &other) {
    this->firstname = other.firstname;
    this->lastname = other.lastname;
    this->id = other.id;
    this->power = other.power;
    this->party = other.party;
    this->chairman = other.chairman;
}

void Politician::printChairman() const {
    cout << "Chairman: ";
    if (chairman){
        cout << chairman->getName() << endl;
    }
    else{
        cout << "None" << endl;
    }
}

string Politician::getName() {
    return firstname;
}

int Politician::getId() {
    return id;
}

int Politician::getPower() {
    return power;
}

Party* Politician::getParty() {
    return this->party;
}

void Politician::setParty(Party* party) {
    this->party = party;
}

void Politician::updateChairman(Politician* newchair){
    chairman = newchair;
}

void Politician::print() const {
    cout << "Person:";
    cout << firstname << " ";
    cout << lastname << ", ";
    cout << "Id:" << id << ", ";
    cout << "Power:" << power << ", ";

}

Politician& Politician::operator=(const Politician &other) {
    if (this != &other){
        this->firstname = other.firstname;
        this->lastname = other.lastname;
        this->id = other.id;
        this->power = other.power;
    }
    return *this;
}
