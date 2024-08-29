/**
 * @authors manaswee & skyla
 * @file MovieDatabase.h
 * Header file for MovieDatabase class, which stores movie-related data and
 * methods.
 */

#ifndef MOVIE_DATABASE_H
#define MOVIE_DATABASE_H

#include "Classic.h"
#include "ClassicBuilder.h"
#include "Comedy.h"
#include "ComedyBuilder.h"
#include "Drama.h"
#include "DramaBuilder.h"
#include "HashTable.cpp"
#include "MovieCustomerDatabase.h"
#include <iostream>
#include <sstream>
#include <vector>

class MovieDatabase {
private:
  HashTable<std::vector<Movie *>> movieMap; // Char represents the type of movie

  std::string getWord(std::stringstream &ss, char del = 0);
  Movie *getMovie(std::stringstream &ss, char type);

  static bool compareMovie(Movie *cmovie1, Movie *cmovie2) {
    return (*cmovie1 < *cmovie2);
  };

public:
  /**
   * constructors
   */
  MovieDatabase();
  MovieDatabase(std::string dataFile);
  /**
   * return inventory of the movie store
   */
  void getInventory();
  /**
   * lend a movie out to a customer, reduces stock
   * @param borrowLine
   * @param mcd
   */
  void lendMovie(std::string borrowLine, MovieCustomerDatabase &mcd);
  /**
   * get a movie back, adds to stock
   * @param returnLine
   * @param mcd
   */
  void returnMovie(std::string returnLine, MovieCustomerDatabase &mcd);
  /**
   * process movieInfo file, fills the movie database
   * @param file
   * @return
   */
  bool readMovieFile(std::string file);
  /**
   * add a movie manually through a string
   * @param movieLine
   */
  void addMovie(std::string movieLine);
};

#endif