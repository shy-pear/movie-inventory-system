/**
 * @authors skyla & manaswee
 * @file MovieCustomerDatabase.h
 * @date 12/03/2022
 * related to MovieCustomerDatabase.cpp file, manages MovieCustomer objects by
 * storing them in two seperate containers. Functions check if a customer exists
 * within the customerList (all customers are in this list), adds new customers
 * to the customerList, adds new transaction based on B:borrow and R:return to
 * the customer ID stored in the customerHistoryMap. The transaction history of
 * a certain customer can be displayed using the getHistory(ID#) method, and all
 * customer information can be displayed in ID#, First, Last format.
 */
#ifndef MOVIE_CUSTOMER_DATABASE_H
#define MOVIE_CUSTOMER_DATABASE_H

#include "Classic.h"
#include "Comedy.h"
#include "CustomerFactory.h"
#include "Drama.h"
#include "MovieCustomer.h"
#include <map>
#include <vector>

class MovieCustomerDatabase {
private:
  std::vector<MovieCustomer> customerList;
  std::map<int, std::vector<std::pair<char, Movie *>>> customerHistoryMap;

public:
  /**
   * constructors
   */
  MovieCustomerDatabase();
  MovieCustomerDatabase(std::string dataFile);
  ~MovieCustomerDatabase();
  /**
   * processes customerFile data
   * @param dataFile
   * @return
   */
  bool readCustomerFile(std::string dataFile);
  /**
   * add a customer to the database
   * @param customer
   */
  void addCustomer(std::string customer);
  /**
   * add a transaction to customer history
   * @param id
   * @param type
   * @param movie
   */
  void addTransaction(int id, char type, Movie *movie);
  /**
   * does the customer exist???
   * @param id
   * @return
   */
  bool customerExist(int id);
  /**
   * retrive history of a customer through ID
   * @param id
   */
  void getHistory(int id);
  /**
   * display all customers in the database
   */
  void displayAllCustomers();
};

#endif