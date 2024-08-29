/**
 * @authors skyla & manaswee
 * @file MovieCustomerDatabase.cpp
 * @date 12/03/2022
 * related to MovieCustomerDatabase.h file, manages MovieCustomer objects by
 * storing them in two seperate containers. Functions check if a customer exists
 * within the customerList (all customers are in this list), adds new customers
 * to the customerList, adds new transaction based on B:borrow and R:return to
 * the customer ID stored in the customerHistoryMap. The transaction history of
 * a certain customer can be displayed using the getHistory(ID#) method, and all
 * customer information can be displayed in ID#, First, Last format.
 */
#include "MovieCustomerDatabase.h"
#include <fstream>
#include <iostream>
#include <map>
#include <vector>

/**
 * constructors
 */
MovieCustomerDatabase::MovieCustomerDatabase(){};
MovieCustomerDatabase::MovieCustomerDatabase(std::string dataFile) {
  readCustomerFile(dataFile);
}

MovieCustomerDatabase::~MovieCustomerDatabase() {
    std::map<int, std::vector<std::pair<char, Movie *>>>::iterator it = customerHistoryMap.begin();
    while (it != customerHistoryMap.end()) {
        for (auto p: it->second) {
            delete p.second;
        }
        it->second.clear();
        customerHistoryMap.erase(it);
        it++;
    }
}

/**
 * reads the customer.txt file and creates customer objects
 * @param file
 * @return
 */
bool MovieCustomerDatabase::readCustomerFile(std::string file) {
  std::ifstream input;
  input.open(file);

  if (!input.is_open()) {
    std::cout << "ERROR: Could not open file." << std::endl;
    return false;
  }

  while (input) {
    std::string line;
    getline(input, line);
    if (line != "") {
      addCustomer(line);
    }
    input >> std::ws;
  }
  input.close();
  return true;
}

/**
 * check whether or not a customer already exists in the database,
 * since all 4 digit IDs must be unique
 * @param id: ID of customer trying to be added (names may be repeated
 * but IDs cannot since they are unique)
 * @return bool: whether or not the customer exists
 */
bool MovieCustomerDatabase::customerExist(int id) {
  // if the ID exists customer list return true
  for (int i = 0; i < customerList.size(); i++) {
    if (customerList[i].getIDNumber() == id) {
      return true;
    }
  }
  // else return false
  return false;
}

/**
 * add a new customer to the database using the CustomerFactory
 * @param customer: the string of customer information
 * @return void
 */
void MovieCustomerDatabase::addCustomer(std::string customer) {
  // check if ID already exists
  std::istringstream ss(customer);
  std::string currInfo;
  ss >> currInfo;
  int number = stoi(currInfo);
  if (this->customerExist(number)) {
    std::cout << "could not add customer profile " << customer << std::endl;
    return;
  }
  // create customer obj and put in the customerList
  MovieCustomer mc = CustomerFactory::create(customer);
  customerList.push_back(mc);
  std::vector<std::pair<char, Movie *>> transactionList;
  customerHistoryMap[mc.getIDNumber()] = transactionList;
}

/**
 * adds the transaction log to the ID's current history of transactions
 * @param id: customer ID doing transaction
 * @param type: type of transaction (B:Borrow R:Return)
 * @param movie: movie object used in the transaction
 * @return void
 */
void MovieCustomerDatabase::addTransaction(int id, char type, Movie *movie) {
  std::pair<char, Movie *> transaction = std::make_pair(type, movie);
  customerHistoryMap[id].push_back(transaction);
}

/**
 * displays the transaction history of a customer, recent most
 * being displayed on top
 * @param id: customer ID to get the transaction history of
 * @return void
 */
void MovieCustomerDatabase::getHistory(int id) {
  if (!customerExist(id)) {
    std::cout << "ERROR: Customer " << id
              << " does not exist. Cannot retrieve history." << std::endl;
    return;
  }
  std::cout << "--------HISTORY OF CUSTOMER: " << id << "---------"
            << std::endl;
  std::vector<std::pair<char, Movie *>> transactionList =
      customerHistoryMap[id];
  for (int i = transactionList.size() - 1; i >= 0; i--) {
    std::cout << "Command: " << transactionList[i].first
              << ", Movie: " << *(transactionList[i].second) << std::endl;
  }
}

/**
 * displays all customers in the database in
 * ID#, Firstname, Lastname format
 * @return void
 */
void MovieCustomerDatabase::displayAllCustomers() {
  for (int i = 0; i < customerList.size(); i++) {
    std::cout << customerList[i];
  }
}
