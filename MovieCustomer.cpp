/**
 * @authors skyla & manaswee
 * @file MovieCustomer.cpp
 * movie customer objects class
 */
#include "MovieCustomer.h"
#include <vector>

/**
 * equality operator overload
 * @param person
 * @param otherPerson
 * @return
 */
bool operator== (const MovieCustomer& person, const MovieCustomer& otherPerson) {
    if (person.getFirstName() == otherPerson.getFirstName() &&
        person.getLastName() == otherPerson.getLastName() &&
        person.getIDNumber() == otherPerson.getIDNumber()) {
        return true;
    } else {
        return false;
    }
}
/**
 * constructor
 * @param ID
 * @param first
 * @param last
 */
MovieCustomer::MovieCustomer(int ID, std::string first, std::string last) {
    this->ID = ID;
    this->firstName = first;
    this->lastName = last;
}
/**
 * destructor
 */
MovieCustomer::~MovieCustomer() {
}
/**
 * @return string: first name
 */
std::string MovieCustomer::getFirstName() const {
    std::string name = this->firstName;
    return name;
}
/**
 * @return string: last name
 */
std::string MovieCustomer::getLastName() const {
    std::string name = this->lastName;
    return name;
}
/**
 * @return int: ID number
 */
int MovieCustomer::getIDNumber() const {
    int number = this->ID;
    return number;
}

