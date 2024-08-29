/**
 * @authors manaswee & skyla
 * @file ClassicBuilder.h
 * header file for classicbuilder.cpp
 */
#ifndef CLASSIC_BUILDER_H
#define CLASSIC_BUILDER_H
#include "MovieBuilder.h"
#include <iostream>

class ClassicBuilder : public MovieBuilder {
public:
  Movie *parseLine(std::string line) override;
};
#endif