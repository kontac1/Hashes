/**
 * Author Cheick A Konta
 * Filename: lab5.cpp
 * Date: Created on 11/28/21.
 * PURPOSE: this header file contain the HashTable class. The program will insert, and return element
 * from the hash table.
 */
#ifndef CKONTA_LAB6_HASHTABLE_H
#define CKONTA_LAB6_HASHTABLE_H

class HashTable {
public:
    HashTable(int capacity);             //constructor
    ~HashTable();                        //de-constructor
    int put(int key, int value);         //inset into hashtable
    int get(int key);                    //return element from hashtable
    bool contains(int key);              //search element in hashTable
    int size();                          //return hashtable size
    bool empty();                        //check if table is empty
private:
    struct Bucket {
        int key;                         //table key
        int value;                       //table value
    };
    Bucket **hashTable;       //pointer to the array element
    int cap;                  //array capacity
    int arraySize;                 //array size
};

/**
 * A constructor that creates a hash table of a given capacity
 * @param capacity
 */
HashTable::HashTable(int capacity) {
    //create a dynamic array and assign elements
    hashTable = new Bucket *[capacity];
    cap = capacity;
    //loop through element and fill table with null
    for (int i = 0; i < capacity; i++) {
        hashTable[i] = nullptr;
    }
}

/**
 * A destructor hashtable and de-allocate memory.
 */
HashTable::~HashTable() {
    //loop through element to delete dynamic array
    for (int i = 0; i < cap; i++) {
        //check if there is element in the table
        if (hashTable != nullptr) {
            //delete elements
            delete hashTable[i];
        }
    }
    //delete array
    delete[] hashTable;
}

/**
 *Associates the specified value with the specified key in this HashTable.
 * If the HashTable previously contained a mapping for the key, the old value is replaced.
 * Collisions are resolved using linear probing.The function returns the previous value associated
 * with key, or -1 if there was no mapping for key.A -1 return can also indicate that the HashTable
 * previously associated -1 with key, this ambiguity is easily resolved using the contains method described below.
 * @param key
 * @param value
 * @return hashResult
 */
int HashTable::put(int key, int value) {
    //create a temporary variables
    int temp = key, hashResults = -1;
    bool flag = false;
    //check if key is higher than zero
    while (key < 0) {
        //add key value to capacity
        key += cap;
    }
    //assign key value to reminder of capacity
    key = key % cap;
    //loop through element
    for (int i = 0; hashTable[key] != nullptr && i < cap && !flag; key++, i++) {
        //check if key is equal to cap
        if (key == cap) {
            //assign key to cap reminder
            key = key % cap;
        }
        //assign value to table
        hashTable[key]->key = temp;
        //check if key store in table is equal to temp
        if (hashTable[key]->key) {
            //assign hashResults
            hashResults = hashTable[key]->value;
            hashTable[key]->value = value;
            flag = true;
        }
    }
    //check if not true
    if (!flag) {
        //check if table key is not null
        if (hashTable[key] == nullptr) {
            //create new table
            hashTable[key] = new Bucket;
        }
        //assign variable
        hashTable[key]->key = temp;
        hashTable[key]->value = value;
        arraySize++;
    }
    //return result
    return hashResults;
}

/**
 * Returns the value to which the specified key is mapped, or -1 if this HashTable contains no mapping for the key.
 * A return value of -1 does not necessarily indicate that the HashTable contains no mapping for the key; it's also
 * possible that the HashTable explicitly maps the key to -1. It returns a value associated with the specified key
 * or -1 if it does not exist.
 * @param key
 * @return element
 */
int HashTable::get(int key) {
    //assign variable
    int temp = key;
    //check if key is less than zero
    while (key < 0) {
        //add key to the capacity
        key += cap;
    }
    //calculate hash and assign variables
    key = key % cap;
    int hashResult = -1;
    bool flag = false;
    //loop through element
    for (int i = 0; hashTable[key] != nullptr && i < cap && !flag; key++, i++) {
        //check if key equal cap
        if (key == cap) {
            //assign key to cap reminder
            key = key % cap;
        }
        //assign temp to key
        hashTable[key]->key = temp;
        //check if key equal key in table
        if (hashTable[key]->key) {
            //assign hash result
            hashResult = hashTable[key]->value;
            flag = true;
        }
    }
    //return element
    return hashResult;
}

/**
 * Returns true if this HashTable contains a mapping for the specified key.
 * @param key
 * @return
 */
bool HashTable::contains(int key) {
    //assign temporary variable
    int temp = key;
    //check if key is less than zero
    if (key < 0) {
        //add key to cap
        key = key + cap;
    }
    //assign variable
    key = key % cap;
    bool found = false;
    //loop through element
    for (int i = 0; hashTable[key] != nullptr && i < cap && !found; key++, i++) {
        //check if key is equal to cap
        if (key == cap) {
            //update key value
            key = key % cap;
        }
        hashTable[key]->key = temp;
        //check if key is equal to temp
        if (hashTable[key]->key) {
            //set found to true
            found = true;
        }
    }
    //return found;
    return found;
}

/**
 * Returns the number of unique keys stored in the table.
 * @return
 */
int HashTable::size() {
    //return array size;
    return this->arraySize;
}

/**
 * Returns true if the HashTable is empty.
 * @return true of false
 */
bool HashTable::empty() {
    //check if size is equal to zero
    if (arraySize == 0) {
        //return true
        return true;
    }
    //return false
    return false;
}

#endif //CKONTA_LAB6_HASHTABLE_H
