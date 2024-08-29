/**
 * @authors skyla & manaswee
 * @file Drama.h
 * header file for Drama class, child of Movie
 */
#ifndef DRAMA_H
#define DRAMA_H
#include "Movie.h"
#include <iostream>

class Drama : public Movie {
private:
  int releaseDate;

public:
    /**
     * display function to let insertion operator overload
     * work with inheritance
     * @param COUT
     * @return
     */
  std::ostream &display(std::ostream &COUT) const {
    COUT << this->inStock << " " << this->outStock << " " << this->mediaType
         << " " << this->director << " " << this->title;
    return COUT;
  }
  /**
   * customer function for std::sort comparisons
   * @param movie
   * @return
   */
  bool lessThan(Movie &movie) const {
    Drama dmovie = dynamic_cast<Drama &>(movie);
    if (this->getDirector() != dmovie.getDirector()) {
      return this->getDirector() < dmovie.getDirector();
    }
    return this->getTitle() < dmovie.getTitle();
  }
/**
 * constructor
 * @param type
 * @param stock
 * @param director
 * @param title
 * @param releaseYear
 */
  Drama(char type, int stock, std::string director, std::string title,
        int releaseYear);
  /**
   * destructor
   */
  ~Drama();
  /**
   * @return int: release year
   */
  int getReleaseDate();
};

#endif
