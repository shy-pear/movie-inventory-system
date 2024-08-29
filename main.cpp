/**
 * Main file to test MovieDatabase and MovieCustomerDatabase classes.
 *
 *
 */
#include "MovieCustomerDatabase.h"
#include "MovieDatabase.h"
#include <fstream>
#include <iostream>
#include <sstream>

bool readCommandFile(std::string file, MovieDatabase &md,
                     MovieCustomerDatabase &mcd) {
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
      std::stringstream ss(line);
      std::string nextWord;
      ss >> nextWord;
      char cmd = nextWord.at(0); // get the command char

      // check what command it is
      switch (cmd) {
      case 'B':
        md.lendMovie(line, mcd);
        break;
      case 'R':
        md.returnMovie(line, mcd);
        break;
      case 'I':
        md.getInventory();
        break;
      case 'H': {
        ss >> nextWord;
        int id = stoi(nextWord);
        mcd.getHistory(id);
        break;
      }
      default:
        std::cout << "ERROR: Invalid Command Type." << std::endl;
        std::cout << "Discarding Command: " << line << std::endl;
        break;
      };
    }

    input >> ws;
  }

  input.close();
  return true;
}

int originalTest() {
  std::cout << "****************************************************"
            << std::endl;
  std::cout << "TESTING MOVIE DATABASE" << std::endl;
  MovieDatabase MD("movieFile.txt");
  cout << endl;
  MD.getInventory();
  std::cout << "****************************************************"
            << std::endl;
  std::cout << "TESTING MOVIE CUSTOMERS" << std::endl;
  MovieCustomer manaswee(0001, "manaswee", "is cool");
  MovieCustomer skyla(0002, "skyla", "is cool");
  std::cout << manaswee;
  std::cout << skyla;
  std::cout << "****************************************************"
            << std::endl;
  MovieCustomerDatabase MCD;
  MCD.addCustomer("1111 Mouse Mickey");
  MCD.addCustomer("1000 Mouse Minnie");
  MCD.displayAllCustomers();
  MD.lendMovie("B 1111 D C 9 1938 Katherine Hepburn", MCD);
  MD.returnMovie("R 1111 D F You've Got Mail, 1998", MCD);
  MD.lendMovie("B 1111 D F You've Got Mail, 1998", MCD);
  MD.lendMovie("B 1111 D C 2 1975 Blah Blah", MCD);
  std::cout << "getting history of Mickey Mouse: " << std::endl;
  MCD.getHistory(1111);
  std::cout << "-----" << std::endl;
  MD.getInventory();

  return 0;
};

int main() {

  MovieDatabase MD("movieFile.txt");
  MovieCustomerDatabase MCD("customerFile.txt");

  bool success = readCommandFile("commandFile.txt", MD, MCD);
  if (success) {
    std::cout << "Success! Tests complete" << std::endl;
  } else {
    std::cout << "There was an error." << std::endl;
  }

  return 0;
}