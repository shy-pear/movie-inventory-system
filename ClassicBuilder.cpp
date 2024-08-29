/**
 * @authors manaswee & skyla
 * @file ClassicBuilder.cpp
 * ClassicBuilder, builds returns Classic objects, Child of MovieBuilder
 */
#include "ClassicBuilder.h"
#include "Classic.h"
#include <iostream>
#include <sstream>

using namespace std;

/**
 * takes a line, parses it, then builds classic movie object
 * @param line
 * @return
 */
Movie *ClassicBuilder::parseLine(std::string line) {
  stringstream ss(line);
  char category = getWord(ss, ',').at(0);
  int stock = stoi(getWord(ss, ','));
  string director = getWord(ss, ',');
  string title = getWord(ss, ',');
  string majorActor = getWord(ss, ' ') + " " + getWord(ss, ' ');
  int month = stoi(getWord(ss, ' '));
  int year = stoi(getWord(ss));

  return new Classic(category, stock, director, title, majorActor, month, year);
}