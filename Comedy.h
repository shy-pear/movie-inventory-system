/**
 * @authors manaswee & skyla
 * @file Comedy.h
 * header file for Comedy class, child of Movie
 */
#ifndef COMEDY_H
#define COMEDY_H
#include "Movie.h"
#include <iostream>

class Comedy : public Movie {
private:
  int releaseYear;

public:
    /**
     * inherited display function to make insertion
     * operator work
     * @param COUT
     * @return
     */
  std::ostream &display(std::ostream &COUT) const {
    COUT << this->inStock << " " << this->outStock << " " << this->mediaType
         << " " << this->title << " " << this->releaseYear;
    return COUT;
  }

  /**
   * custom comparative function for std::sort
   * @param movie
   * @return
   */
  bool lessThan(Movie &movie) const {
    Comedy fmovie = dynamic_cast<Comedy &>(movie);
    if (this->getTitle() != fmovie.getTitle()) {
      return this->getTitle() < fmovie.getTitle();
    }
    return this->getReleaseYear() < fmovie.getReleaseYear();
  }

  Comedy() = delete;
  /**
   * constructor
   * @param type
   * @param stock
   * @param director
   * @param title
   * @param releaseYear
   */
  Comedy(char type, int stock, std::string director, std::string title,
         int releaseYear);
  /**
   * destructor
   */
  ~Comedy();
  /**
   * @return int: release year
   */
  int getReleaseYear() const;
};

#endif
