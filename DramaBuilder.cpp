/**
 * @authors skyla & manaswee
 * @file DramaBuilder.cpp
 * DramaBuilder, builds returns Drama objects
 * Child of MovieBuilder
 */
#include "DramaBuilder.h"
#include "Drama.h"
#include <iostream>
#include <sstream>

using namespace std;
/**
 * takes in a string, parses, and created drama movie object
 * @param line
 * @return
 */
Movie *DramaBuilder::parseLine(std::string line) {
  stringstream ss(line);
  char category = getWord(ss, ',').at(0);
  int stock = stoi(getWord(ss, ','));
  string director = getWord(ss, ',');
  string title = getWord(ss, ',');
  int year = stoi(getWord(ss));

  return new Drama(category, stock, director, title, year);
}