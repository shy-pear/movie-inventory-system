/**
 * @authors manaswee & skyla
 * @file Classic.h
 * header file for Classic class, child of Movie
 */
#ifndef CLASSIC_H
#define CLASSIC_H
#include "Movie.h"
#include <iostream>

class Classic : public Movie {

private:
  int releaseMonth;
  int releaseYear;
  std::string majorActor;

public:
  /**
   * display function to make the << overload work
   * with inheritance
   * @param COUT
   * @return
   */
  std::ostream &display(std::ostream &COUT) const {
    COUT << this->inStock << " " << this->outStock << " " << this->mediaType
         << " " << this->releaseMonth << " " << this->releaseYear << " "
         << this->majorActor;
    return COUT;
  };

  /**
   * custom compare function for std::sort
   * @param movie
   * @return bool:
   */
  bool lessThan(Movie &movie) const {
    Classic cmovie = dynamic_cast<Classic &>(movie);
    if (this->getReleaseYear() != cmovie.getReleaseYear()) {
      return this->getReleaseYear() < cmovie.getReleaseYear();
    }
    if (this->getReleaseMonth() != cmovie.getReleaseMonth()) {
      return this->getReleaseMonth() < cmovie.getReleaseMonth();
    }
    return this->getMajorActor() < cmovie.getMajorActor();
  }

  Classic() = delete;
  /**
   * constructor for Classic movie object
   * @param type
   * @param stock
   * @param director
   * @param title
   * @param actor
   * @param month
   * @param year
   */
  Classic(char type, int stock, std::string director, std::string title,
          std::string actor, int month, int year);
  /**
   * destructor
   */
  ~Classic();
  /**
   * overloading the insertion operator
   * @param COUT
   * @param movie
   * @return
   */
  friend std::ostream &operator<<(std::ostream &COUT, const Classic &movie);
  /**
   * @return int: release month
   */
  int getReleaseMonth() const;
  /**
   * @return int: release year
   */
  int getReleaseYear() const;
  /**
   * @return string: major actor's name
   */
  std::string getMajorActor() const;
};

#endif
