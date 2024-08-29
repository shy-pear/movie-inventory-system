/**
 * @authors manaswee & skyla
 * @file ComedyBuilder.cpp
 * ComedyBuilder, builds returns Comedy objects
 * Child of MovieBuilder
 */
#include "ComedyBuilder.h"
#include "Comedy.h"
#include <iostream>
#include <sstream>

using namespace std;

/**
 * takes a string, parse, and create comedy movie object
 * @param line
 * @return
 */
Movie *ComedyBuilder::parseLine(std::string line) {
  stringstream ss(line);
  char category = getWord(ss, ',').at(0);
  int stock = stoi(getWord(ss, ','));
  string director = getWord(ss, ',');
  string title = getWord(ss, ',');
  int year = stoi(getWord(ss));

  return new Comedy(category, stock, director, title, year);
}