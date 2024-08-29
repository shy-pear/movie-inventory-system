/**
 * @authors skyla & manaswee
 * @file MovieBuilder.cpp
 * header for movie builder class, follows builder design pattern
 */
#ifndef MOVIE_BUILDER_H
#define MOVIE_BUILDER_H
#include "Movie.h"
#include <iostream>
#include <sstream>

class MovieBuilder {
public:
  virtual Movie *parseLine(std::string line) = 0;

protected:
  std::string getWord(std::stringstream &ss, char del = 0);
};

#endif