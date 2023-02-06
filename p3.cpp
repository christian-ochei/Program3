#include <string>

#include <iostream>

#include "p3.h"

cStringList::cStringList(int listCapacity) {
    // Author : Christian Ochei and Habtamu Wario
    a = new std::string[listCapacity];
    this -> listCapacity = listCapacity;
    
    // List starts empty
    listSize = 0;
    first = 0;
    last = 0;
}


cStringList::~cStringList() {
    // Author : Habtamu Wario
    delete[] a;
}

//insert in the front
bool cStringList::insert(std::string text) {
    // Author : Christian Ochei

    // check if there are items in a list
    bool rc = listSize < listCapacity;
    if (rc) {
        //decrement first 
        decVal(first);

        // assign the inserted value to the index of 0 
        a[toCListIndex(0)] = text;
        listSize += 1;
    }
    return rc;
}
//add at the end of the list
bool cStringList::add(std::string text) {
    // Author : Christian Ochei

    //check if there are items in a list
    bool shouldAdd = listSize < listCapacity;
    if (shouldAdd) {
        //if so assign value to last index;
        a[toCListIndex(listSize)] = text;
        
        //increament the list Size
        listSize += 1;
        incVal(last);
    }
    //else return false;
    return shouldAdd;
}

//
bool cStringList::insertAt(int index, std::string text) {
    // Author : Christian Ochei and Habtamu Wario

    bool shouldInsert = index >= 0 && index <= listCapacity && listSize < listCapacity;
    if (shouldInsert) {
        // If so, move each item from given index one step up the list
        for (int i = listSize; i > index; i--) {
            a[toCListIndex(i)] = a[toCListIndex(i - 1)];
        }
        
        // Available space should be left at given index
        // Assign text to given index
        a[toCListIndex(index)] = text;
        // Increment list size
        listSize += 1;
        incVal(last);
    }
    return shouldInsert;
}

//delete from the list at a given position
bool cStringList::deleteAt(int index, std::string & text) {
    // Author : Christian Ochei and Habtamu Wario

    // check if the index is between zero and index size;
    bool shouldDelete = index >= 0 && index < listSize;
    // if so
    if (shouldDelete) {
        // assign the value at index to passed value
        text = a[toCListIndex(index)];
        // iterate thought the list
        for (int i = index; i < listSize - 1; i++) {
            // shift the values to the left by one;
            a[toCListIndex(i)] = a[toCListIndex(i + 1)];
        }
        // decrease the list size by one
        listSize -= 1;
        // decreament the last 
        decVal(last);
    }
    // else return false
    return shouldDelete;
}

//Empty the list
void cStringList::clear() {
    // Author : Christian Ochei
    listSize = 0;
    first = 0;
    last = 0;
}

//print the list
void cStringList::printIt() const {
    // Author : Habtamu Wario
    for (int i = 0; i < listSize; i++) {
        std::cout << "At pos " << i << " there is " << a[toCListIndex(i)] << "\n";
    }
}

//get the specific index of the given function
int cStringList::getIndex(std::string text) const {
    // Author : Christian Ochei and Habtamu Wario

    //assign  -1 to the index 
    int index = -1;
    //iterate through the list 
    for (int i = 0; i < listSize; i++) {
        //check if the value matches 
        if (text == a[toCListIndex(i)]) {
            //if so get the index of that value
            index = i;
            break;
        }
    }
    //else return -1;
    return index;
}

bool cStringList::readAt(int index, std::string & text) const {
    // Author : Habtamu Wario

    //check if the index is greater than 0 and lees than list size
    bool shouldRead = index >= 0 && index < listSize;
    //if so
    if (shouldRead) {
        //get the passed value 
        text = a[toCListIndex(index)];
    }
    //else return false
    return shouldRead;
}

// count the number of entries 
int cStringList::count() const {
    // Author : Habtamu Wario
    return listSize;
}

//list the index value function 
int cStringList::toCListIndex(int value) const {
    // Author : Christian Ochei
    return (first + value) % listCapacity;
}

//delete the first element
bool cStringList::deleteFirst(std::string & text) {
    // Author : Christian Ochei

    //check if the first element is differ from zero
    bool rc = listSize != 0;
    //if so 
    if (rc) {
        //the value at first index is equal to passed value
        text = a[first];
        //increament the first value 
        incVal(first);
        //decreament listSize by one;
        listSize--;
    }
    return rc;
}

//delet last element in a list
bool cStringList::deleteLast(std::string & text) {
    // Author : Christian Ochei

    // check if there is anything in a last element
    bool rc = listSize != 0;
    //if so 
    if (rc) {
        //the text to the last value
        text = a[last];
        //decreament the last
        decVal(last);
        //decrease list size by one;
        listSize--;
    }
    //else return false;
    return rc;
}

//decreament value function
void cStringList::decVal(int & value) {
    // Author : Christian Ochei

    // Decrement value by 1 and make its output is of mod listCapacity 
    // and always positive
    value = (listCapacity + value - 1) % listCapacity;
}
//increament value function
void cStringList::incVal(int & value) {
        // Author : Christian Ochei

        // Increment value by 1 and make its output is of mod listCapacity 
        // and always positive
        value = (listCapacity + value + 1) % listCapacity;
