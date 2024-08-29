/**
 * @authors skyla @ manaswee
 * @file CustomerFactory.h
 * @date 12/03/2022
 * used to create MovieCustomer objects. This class is used to follow the
 * Factory design pattern for MovieCustomer objects.
 */
#ifndef CUSTOMER_FACTORY_H
#define CUSTOMER_FACTORY_H
#include "MovieCustomer.h"
#include "MovieCustomerDatabase.h"
#include <iostream>
#include <sstream>
#include <string>


class CustomerFactory {
public:
    /**
     * takes in a string, parses and creates a customer object
     * @param line
     * @return
     */
  static MovieCustomer create(std::string line) {
    // if not already in there, create the new customer
    std::istringstream ss(line);
    std::string currInfo;
    // customer information always formatted as
    // IDNumber FirstName LastName
    ss >> currInfo;
    int number = stoi(currInfo);
    ss >> currInfo;
    std::string firstName = currInfo;
    ss >> currInfo;
    std::string lastName = currInfo;
    return MovieCustomer(number, firstName, lastName);
  }
};

#endif