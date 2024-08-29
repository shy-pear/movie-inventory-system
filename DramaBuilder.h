/**
 * @authors skyla & manaswee
 * @file DramaBuilder.h
 * header file for DramaBuilder.cpp
 */
#ifndef DRAMA_BUILDER_H
#define DRAMA_BUILDER_H
#include "MovieBuilder.h"
#include <iostream>

class DramaBuilder : public MovieBuilder {
public:
  Movie *parseLine(std::string line) override;
};
#endif