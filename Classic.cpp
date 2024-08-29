/**
 * @authors manaswee & skyla
 * @file Classic.cpp
 * Classic class, child of Movie
 */
#include "Classic.h"

/**
 * constructor
 * @param type
 * @param stock
 * @param director
 * @param title
 * @param actor
 * @param month
 * @param year
 */
Classic::Classic(char type, int stock, std::string director, std::string title,
                 std::string actor, int month, int year) {
  this->category = type;
  this->inStock = stock;
  this->director = director;
  this->title = title;
  this->majorActor = actor;
  this->releaseMonth = month;
  this->releaseYear = year;
}

/**
 * @return int: release month
 */
int Classic::getReleaseMonth() const {
  int month = this->releaseMonth;
  return month;
}

/**
 * @return int: release year
 */
int Classic::getReleaseYear() const {
  int year = this->releaseYear;
  return year;
}

/**
 * @return string: major actor's name
 */
std::string Classic::getMajorActor() const {
  std::string name = this->majorActor;
  return name;
}

/**
 * destructor
 */
Classic::~Classic(){};
