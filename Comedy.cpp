/**
 * @authors skyla & manaswee
 * @file Comedy.cpp
 * Comedy class, child of Movie
 */
#include "Comedy.h"

/**
 * constructor
 * @param type
 * @param stock
 * @param director
 * @param title
 * @param releaseYear
 */
Comedy::Comedy(char type, int stock, std::string director, std::string title,
               int releaseYear) {
  this->category = type;
  this->inStock = stock;
  this->director = director;
  this->title = title;
  this->releaseYear = releaseYear;
}

/**
 * overloading the comparative operator
 * @param movieOne
 * @param movieTwo
 * @return
 */
bool operator<(const Comedy &movieOne, const Comedy &movieTwo) {
  std::cout << "Inside < operator Comedy" << std::endl;
  if (movieOne.getTitle() < movieTwo.getTitle()) {
    return true;
  }
  if (movieOne.getTitle() > movieTwo.getTitle()) {
    return false;
  }
  if (movieOne.getReleaseYear() < movieTwo.getReleaseYear()) {
    return true;
  }
  if (movieOne.getReleaseYear() > movieTwo.getReleaseYear()) {
    return false;
  }
  return true;
}

/**
 * destructor
 */
Comedy::~Comedy(){};

/**
 * @return int: release date
 */
int Comedy::getReleaseYear() const {
  int year = this->releaseYear;
  return year;
}
