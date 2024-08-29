/**
 * @authors manaswee & skyla
 * @file HashTable.h
 * header file for hashtable.cpp
 */
#ifndef HASH_TABLE_H
#define HASH_TABLE_H

#include <iostream>
#include <list>
#include <queue>

using namespace std;

template <class Value>
// Hashtable for key: char, value: generic
class HashTable {
public:
  // overloading [] operator to return the value at given key
  // returns copy of the value
  // Value operator[](char key);

  //---- Functions -----
  bool isEmpty() const;
  bool insert(char key, Value &value);
  bool remove(char key);
  Value &get(char key);

private:
  static const int buckets = 10;
  // primitive array of lists<pair>
  list<pair<char, Value>> table[buckets];

  int hashFunction(char key);
};

#endif