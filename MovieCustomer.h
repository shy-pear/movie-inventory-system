/**
 * @authors skyla & manaswee
 * @file MovieCustomer.h
 * @date 12/03/2022
 * related to MovieCustomer.cpp, header file for the Movie Customer objects
 * stored in
 */
#ifndef MOVIE_CUSTOMER_H
#define MOVIE_CUSTOMER_H
#include "Movie.h"
#include <iostream>
#include <string>
#include <vector>


class MovieCustomer {
private:
  int ID;
  std::string firstName;
  std::string lastName;
  std::ostream &display(std::ostream &COUT) const {
    COUT << this->ID << " " << this->firstName << " " << this->lastName
         << std::endl;
    return COUT;
  }

public:
  /**
   * insertion operator overload
   * @param COUT
   * @param oh
   * @return
   */
  friend std::ostream &operator<<(std::ostream &COUT, const MovieCustomer &oh) {
    return oh.display(COUT);
  }
  /**
   * constructor
   * @param ID
   * @param first
   * @param last
   */
  MovieCustomer(int ID, std::string first, std::string last);
  /**
   * destructor
   */
  ~MovieCustomer();
  /**
   * @return string first name
   */
  std::string getFirstName() const;
  /**
   * @return string last name
   */
  std::string getLastName() const;
  /**
   * @return int ID number
   */
  int getIDNumber() const;
};
#endif
