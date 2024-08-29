/**
 * @authors skyla & manaswee
 * @file Drama.cpp
 * Drama class, child of Movie
 */
#include "Drama.h"

/**
 * constructor
 * @param type
 * @param stock
 * @param director
 * @param title
 * @param releaseYear
 */
Drama::Drama(char type, int stock, std::string director, std::string title,
             int releaseYear) {
  this->category = type;
  this->inStock = stock;
  this->director = director;
  this->title = title;
  this->releaseDate = releaseYear;
}
/**
 * destructor
 */
Drama::~Drama(){};
/**
 * comparative overloading
 * @param movieOne
 * @param movieTwo
 * @return
 */
bool operator<(const Drama &movieOne, const Drama &movieTwo) {
  std::cout << "Inside < operator Drama" << std::endl;
  if (movieOne.getDirector() < movieTwo.getDirector()) {
    return true;
  }
  if (movieOne.getDirector() > movieTwo.getDirector()) {
    return false;
  }
  if (movieOne.getTitle() < movieTwo.getTitle()) {
    return true;
  }
  if (movieOne.getTitle() > movieTwo.getTitle()) {
    return false;
  }
  return true;
}
/**
 * @return int: release year
 */
int Drama::getReleaseDate() {
  int year = this->releaseDate;
  return year;
}
