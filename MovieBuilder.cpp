/**
 * @authors skyla & manaswee
 * @file MovieBuilder.cpp
 * movie builder class, follows builder design pattern
 */
#include "MovieBuilder.h"
#include <iostream>
#include <sstream>

std::string MovieBuilder::getWord(std::stringstream &ss, char del) {
  std::string word;
  if (del == 0) {
    getline(ss, word);
  } else {
    getline(ss, word, del);
  }
  ss >> std::ws;
  return word;
};