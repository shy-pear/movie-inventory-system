/**
 * @authors manswee & skyla
 * @file HashTable.cpp
 * customer hashtable class
 */
#include "HashTable.h"
#include <iostream>
#include <list>
#include <queue>

using namespace std;

/**
 * Method that returns true if HashTable does not contain data, false otherwise.
 */
template <class Value> bool HashTable<Value>::isEmpty() const {
  int sizeSum = 0;
  for (int i = 0; i < buckets; i++) {
    sizeSum += table[i].size();
  }
  return (sizeSum == 0);
};

/**
 * Hash Function to operates on key in order to store data in array.
 * @param key Character stored as key in key-value pair.
 */
template <class Value> int HashTable<Value>::hashFunction(char key) {
  return (int)key % buckets;
};

/**
 * Inserts new key-value pair into HashTable using separate chaining and returns
 * true. If key is a duplicate, replaces original value with new value and
 * returns false.
 * @param key Key character to add.
 * @param value Value of any type (generic).
 */
template <class Value> bool HashTable<Value>::insert(char key, Value &value) {

  int hashValue = hashFunction(key);
  list<pair<char, Value>> &cell = table[hashValue];

  // checks for duplicate key
  for (auto it = begin(cell); it != end(cell); it++) {
    if (it->first == key) {
      it->second = value;
      cout << "Warning: key value has been replaced" << endl;
      return false;
    }
  }

  cell.push_back(make_pair(key, value));
  return true;
};

/**
 * Removes key-value pair from HashTable if key exists and returns true. If not,
 * returns false.
 * @param key Key character to remove.
 */
template <class Value> bool HashTable<Value>::remove(char key) {

  int hashValue = hashFunction(key);
  list<pair<char, Value>> &cell = table[hashValue];

  // checks for key in list, removes it if not
  for (auto it = begin(cell); it != end(cell); it++) {
    if (it->first == key) {
      it = cell.erase(it);
      return true;
    }
  }
  cout << "Item not found" << endl;
  return false;
};

/**
 * Returns value for given key if key is found, outputs error message if not.
 * @param key Key of value to find.
 */
template <class Value> Value &HashTable<Value>::get(char key) {
  int hashValue = hashFunction(key);
  list<pair<char, Value>> &cell = table[hashValue];

  auto it = begin(cell);
  Value returnVal;
  // checks for key in list
  for (; it != end(cell); it++) {
    if (it->first == key) {
      return it->second;
    }
  }
  cout << "Item not found" << endl;
  return it->second;
};

//----- operator overloading----//
/**
 * Overloads [] operator to return value for given key. Returns copy of value if
 * key is found, outputs error message if not.
 * @param key Key of value to find.
 */
/*template <class Value> Value HashTable<Value>::operator[](char key) {

  int hashValue = hashFunction(key);
  list<pair<char, Value>> &cell = table[hashValue];

  auto it = begin(cell);
  // checks for key in list
  for (; it != end(cell); it++) {
    if (it->first == key) {
      return it->second;
    }
  }
  cout << "Item not found" << endl;
  return it->second;
};*/