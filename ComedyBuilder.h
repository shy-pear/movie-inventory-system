/**
 * @authors skyla & manaswee
 * @file ComedyBuilder.h
 * header file for comedybuilder.cpp
 */
#ifndef COMEDY_BUILDER_H
#define COMEDY_BUILDER_H
#include "MovieBuilder.h"
#include <iostream>

class ComedyBuilder : public MovieBuilder {
public:
  Movie *parseLine(std::string line) override;
};
#endif