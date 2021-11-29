/**
 * Author Cheick A Konta
 * Filename: lab5.cpp
 * Date: Created on 11/28/21.
 * PURPOSE: This program will implement a hash table (HashTable) using the following hash function: h(k) = k % N
 * Process: insert elements into hash table, and check if hash table contain elements.
 * Output: print element in the hash table.
 */
#include <iostream>
#include "HashTable.h"
using namespace std;

int main() {
    //create and assign variable
    int size = 4093;
    int key = 0;
    //Create a HashTable of size 4093.
    HashTable hashTable(size);
    //Insert 4083 unique integers into the table
    for (int i = 1; i < 4083; i++) {
        //insert unique element into the table
        hashTable.put(key, key);
        key++;
    }
    //print program information on screen
    cout << "\nWelcome to the HashTable testing program.\n" << endl;
    cout << "Creating a new HashTable with capacity 4093 and inserting \n"
            "4083 random key-value pairs with unique keys.. done.\n" << endl;
    cout << "Inserting 10 additional key-values.." << endl;
    cout << "(1179 , 120)\n"
            "(9702 , 121)\n"
            "(7183 , 122)\n"
            "(50184 , 123)\n"
            "(4235 , 124)\n"
            "(644 , 125)\n"
            "(77 , 126)\n"
            "(3077 , 127)\n"
            "(23477 , 128)\n"
            "(90777 , 129)" << endl;
    //insert 10 additional elements into the hashtable
    hashTable.put(1179, 120);
    hashTable.put(9702, 121);
    hashTable.put(7183, 122);
    hashTable.put(50184, 123);
    hashTable.put(4235, 124);
    hashTable.put(644, 125);
    hashTable.put(77, 126);
    hashTable.put(3077, 127);
    hashTable.put(23477, 128);
    hashTable.put(90777, 129);
    //test contain function
    cout << "\nTesting contains.." << endl;
    cout << "contains(50184): ";
    if (hashTable.contains(50184)) {
        cout << "True";
    } else {
        cout << "False";
    }
    cout << "\ncontains(   77): ";
    if (hashTable.contains(77)) {
        cout << "True";
    } else {
        cout << "False";
    }
    cout << "\ncontains(    0): ";
    if (hashTable.contains(0)) {
        cout << "True";
    } else {
        cout << "False";
    }
    cout << "\ncontains(   -1): ";
    if (hashTable.contains(-1)) {
        cout << "True";
    } else {
        cout << "False";
    }
    //test get function
    cout << "\n\nTesting get.";
    cout << "\nget(50184): " << hashTable.get(50184) << endl;
    cout << "get(   77): " << hashTable.get(77) << endl;
    cout << "get(    0): " << hashTable.get(0) << endl;
    cout << "get(    -1): " << hashTable.get(-1) << endl;
    //closing message
    cout << "\nThanks for using the HashTable testing program. Goodbye.\n" << endl;


    return 0;
}
