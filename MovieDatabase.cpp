/**
 * @authors skyla & manaswee
 * @file MovieDatabase.cpp
 * MovieDatabase class, which stores movie-related data and methods.
 */
#include "MovieDatabase.h"
#include <algorithm>
#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

/**
 * Constructor that sets up movieMap with the correct categories and
 * corresponding vectors of movies.
 */
MovieDatabase::MovieDatabase() {
  vector<Movie *> comedyMovies;
  vector<Movie *> dramaMovies;
  vector<Movie *> classicMovies;
  movieMap.insert('F', comedyMovies);
  movieMap.insert('D', dramaMovies);
  movieMap.insert('C', classicMovies);
};

/**
 * Constructor that sets up movieMap and populates it with movies read from file
 * dataFile.
 * @param dataFile File of movies data correctly formatted with one movie per
 * line.
 */
MovieDatabase::MovieDatabase(string dataFile) : MovieDatabase() {
  readMovieFile(dataFile);
};

/**
 * Method to read movie file and input data into movieMap container.
 * @param file File of movies data correctly formatted with one movie per line.
 */
bool MovieDatabase::readMovieFile(string file) {
  ifstream input;
  input.open(file);

  if (!input.is_open()) {
    cout << "ERROR: Could not open file." << endl;
    return false;
  }

  while (input) {
    string line;
    getline(input, line);
    if (line != "") {
      addMovie(line);
    }
    input >> ws;
  }

  input.close();
  return true;
}

/**
 * Method to parse information for one movie, create corresponding Movie object,
 * and input object into movieMap. If invalid data is provided, outputs error
 * message.
 * @param movieLine Line from movie data file containing information about one
 * movie.
 */
void MovieDatabase::addMovie(std::string movieLine) {
  stringstream ss(movieLine);
  MovieBuilder *builder;

  char category = getWord(ss, ',').at(0);
  switch (category) {
  case 'F':
    builder = new ComedyBuilder();
    break;
  case 'D':
    builder = new DramaBuilder();
    break;
  case 'C':
    builder = new ClassicBuilder();
    break;
  default:
    cout << "ERROR: Invalid Movie Type: " << category << ". Cannot Add Movie."
         << endl;
    return;
  }
  Movie *movie = builder->parseLine(movieLine);
  movieMap.get(category).push_back(movie); //---CHANGED---
  // sort the vector
  std::sort(movieMap.get(category).begin(), movieMap.get(category).end(),
            compareMovie);
  return;
}

/**
 * Method to process borrow command. If command is valid and movie is available,
 * reduces movie stock and adds transaction to MovieCustomerDatabase. If not,
 * outputs error message.
 * @param borrowLine Line from command data file containing information about a
 * borrow command.
 */
void MovieDatabase::lendMovie(std::string borrowLine,
                              MovieCustomerDatabase &mcd) {
  stringstream ss(borrowLine);
  getWord(ss, ' '); // discard command

  // check valid customer
  int customerID = stoi(getWord(ss, ' '));
  if (!mcd.customerExist(customerID)) {
    cout << "ERROR: Customer does not exist." << endl;
    cout << "Discarding Command: " << borrowLine << endl;
    return;
  }

  getWord(ss, ' ');                       // discard media type
  char category = getWord(ss, ' ').at(0); // get category

  Movie *movieToLend = getMovie(ss, category);
  if (movieToLend == nullptr) {
    cout << "Discarding Command: " << borrowLine << endl;
    return;
  }

  int isInStock = movieToLend->removeStock();
  if (isInStock != 0) {
    mcd.addTransaction(customerID, 'B', movieToLend);
  } else {
    cout << "Discarding Command: " << borrowLine << endl;
  }

  return;
}

/**
 * Method to process return command. If command is valid,
 * increases movie stock and adds transaction to MovieCustomerDatabase. If not,
 * outputs error message.
 * @param returnLine Line from command data file containing information about a
 * return command.
 */
void MovieDatabase::returnMovie(std::string returnLine,
                                MovieCustomerDatabase &mcd) {
  stringstream ss(returnLine);
  getWord(ss, ' '); // discard command

  // check valid customer
  int customerID = stoi(getWord(ss, ' '));
  if (!mcd.customerExist(customerID)) {
    cout << "ERROR: Customer does not exist." << endl;
    cout << "Discarding Command: " << returnLine << endl;
    return;
  }

  getWord(ss, ' ');                       // discard media type
  char category = getWord(ss, ' ').at(0); // get type

  Movie *movieToReturn = getMovie(ss, category);
  if (movieToReturn == nullptr) {
    cout << "Discarding Command: " << returnLine << endl;
    return;
  }

  // if the movie is already at full stock, do nothing
  int isNotFullStock = movieToReturn->addStock();
  if (isNotFullStock != 0) {
    mcd.addTransaction(customerID, 'R', movieToReturn);
  } else {
    cout << "Discarding Command: " << returnLine << endl;
  }

  return;
}

/**
 * Method to output movie inventory. Ouputs all Comedy movies, then Dramas, then
 * Classics in sorted order. Information includes movies in stock and out of
 * stock (borrowed).
 */
void MovieDatabase::getInventory() {
  cout << "------CATEGORY: Comedy-----" << endl;
  for (auto movie : movieMap.get('F')) {
    cout << *movie << endl;
  }
  cout << endl;
  cout << "------CATEGORY: Drama-----" << endl;
  for (auto movie : movieMap.get('D')) {
    cout << *movie << endl;
  }
  cout << endl;
  cout << "------CATEGORY: Classic-----" << endl;
  for (auto movie : movieMap.get('C')) {
    cout << *movie << endl;
  }
  cout << endl;
  return;
}

/**
 * Method to get Movie object from movieMap that corresponds to a command. Uses
 * movie sorting data to find movie.
 * @param ss Stringsteam containing command data.
 * @param type Type (category) of movie.
 */
Movie *MovieDatabase::getMovie(stringstream &ss, char type) {
  //----CHANGED----
  switch (type) {
  case 'F': {
    string title = getWord(ss, ',');
    int year = stoi(getWord(ss));

    for (auto movie : movieMap.get('F')) {
      Comedy *fmovie = dynamic_cast<Comedy *>(movie);
      if (fmovie->getTitle() == title && fmovie->getReleaseYear() == year) {
        return movie;
      }
    }
    cout << "ERROR: Movie not available in system." << endl;
    break;
  }

  case 'D': {
    string director = getWord(ss, ',');
    string title = getWord(ss);

    for (auto movie : movieMap.get('D')) {
      Drama *dmovie = dynamic_cast<Drama *>(movie);
      if (dmovie->getTitle() == title && dmovie->getDirector() == director) {
        return movie;
      }
    }
    cout << "ERROR: Movie not available in system." << endl;
    break;
  }

  case 'C': {
    int month = stoi(getWord(ss, ' '));
    int year = stoi(getWord(ss, ' '));
    string majorActor = getWord(ss, ' ') + " " + getWord(ss);

    for (auto movie : movieMap.get('C')) {
      Classic *cmovie = dynamic_cast<Classic *>(movie);
      if (cmovie->getReleaseMonth() == month &&
          cmovie->getReleaseYear() == year &&
          cmovie->getMajorActor() == majorActor) {
        return movie;
      }
    }
    cout << "ERROR: Movie not available in system." << endl;
    break;
  }
  default:
    cout << "ERROR: Movie type not valid." << endl;
  }
  return nullptr;
}

/**
 * Returns next word from stringstream ss. Uses delimiter if given.
 * @param ss Stringsteam containing data.
 * @param del Optional delimiter character.
 */
string MovieDatabase::getWord(stringstream &ss, char del) {
  string word;
  if (del == 0) {
    getline(ss, word);
  } else {
    getline(ss, word, del);
  }
  ss >> ws;
  return word;
}