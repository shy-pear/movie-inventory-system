/**
 * @authors skyla & manaswee
 * @file Movie.h
 * header file for Movie class, parent of Comedy, Drama, and Classic
 */
#ifndef MOVIE_H
#define MOVIE_H
#include <iostream>
#include <string>

class Movie {
protected:
  char category;
  char mediaType = 'D';
  int inStock;
  int outStock = 0;
  std::string director;
  std::string title;

public:
    /**
     * comparative operator overload
     * @param movieOne
     * @param movieTwo
     * @return
     */
  friend bool operator<(Movie &movieOne, Movie &movieTwo) {
    return movieOne.lessThan(movieTwo);
  }
  /**
   * insertion operator overload
   * @param COUT
   * @param oh
   * @return
   */
  friend std::ostream &operator<<(std::ostream &COUT, const Movie &oh) {
    return oh.display(COUT);
  }
  /**
   * constructor
   */
  Movie();
  /**
   * copy constructor
   * @param movie
   */
  Movie(Movie &movie);
  /**
   * insertion operator overload helper function
   * @param COUT
   * @return
   */
  virtual std::ostream &display(std::ostream &COUT) const = 0;
  /**
   * customer comparative function for std::sort
   * @param movie
   * @return
   */
  virtual bool lessThan(Movie &movie) const = 0;
  /**
   * @return char: type of movie (F, C, D)
   */
  char getCategory() const;
  /**
   * @return int: amount in stock
   */
  int getInStock() const;
  /**
   * @return int: amount being borrowed
   */
  int getOutStock() const;
  /**
   * @return string: name of director
   */
  std::string getDirector() const;
  /**
   * @return string: title of movie
   */
  std::string getTitle() const;
  /**
   * add to the movie stock
   * @return
   */
  int addStock();
  /**
   * remove from the movie stock
   * @return
   */
  int removeStock();
};
#endif
