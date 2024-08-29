/**
 * @authors skyla & manaswee
 * @file Movie.cpp
 * Movie class, parent of Comedy, Drama, and Classic
 */
#include "Movie.h"
#include <iostream>
/**
 * constructor
 */
Movie::Movie() {}
/**
 * copy constructor
 * @param movie
 */
Movie::Movie(Movie &movie) {
  this->category = movie.getCategory();
  this->inStock = movie.getInStock();
  this->outStock = movie.getOutStock();
  this->director = movie.getDirector();
  this->title = movie.getTitle();
}
/**
 * @return char: type of movie (F, C, D)
 */
char Movie::getCategory() const {
  char type = this->category;
  return type;
}
/**
 * @return int: stock available
 */
int Movie::getInStock() const {
  int number = this->inStock;
  return number;
}
/**
 * @return int: number of copies currently out
 */
int Movie::getOutStock() const {
  int number = this->outStock;
  return number;
}
/**
 * @return string: director name
 */
std::string Movie::getDirector() const {
  std::string person = this->director;
  return person;
}
/**
 * @return string: title of movie
 */
std::string Movie::getTitle() const {
  std::string name = this->title;
  return name;
}
/**
 * add to the stock of this movie
 * @return int
 */
int Movie::addStock() {
  if (!(outStock <= 0)) {
    inStock++;
    outStock--;
    return 1;
  } else {
    std::cout << "ERROR: Stock is full." << std::endl;
    return 0;
  }
}
/**
 * remove from the stock of this movie
 * @return int
 */
int Movie::removeStock() {
  if (!(inStock <= 0)) {
    inStock--;
    outStock++;
    return 1;
  } else {
    std::cout << "ERROR: no more of this movie left!" << std::endl;
    return 0;
  }
}
