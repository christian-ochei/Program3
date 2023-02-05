#include <string>
#include <iostream>
#include "p3.h"

cStringList::cStringList(int listCapacity){
    // Author : Christian Ochei and Habtamu Wario
    a = new std::string[listCapacity];
    this->listCapacity = listCapacity;
    listSize = 0;
    first = 0;
    last = 0;
}

cStringList ::~cStringList (){
    delete[] a;
}


//edited
bool cStringList ::insert(std::string text){
    bool rc = listSize < listCapacity;
    if (rc){
        //decrement the first
//        decVal()
//        first -= 1;
//        last  -= 1;
        decVal(first);
        // Last stays the same

//        if(first<0){
//            first=listCapacity-1;
//        }
        a[toCListIndex(0)] = text;
//        if(listSize==0){
//            last=first;
//        }
        listSize += 1;
    }
    return rc;
}

//edited needs check
bool cStringList ::add(std::string text){
    bool shouldAdd = listSize < listCapacity;
    if (shouldAdd){
        //increment the last index
//        last=last+1;
//        last=(last)%listCapacity;
//        a[last] = text;
//    if(listSize==0){
//        last=first;
//    }
        a[toCListIndex(listSize)] = text;
        listSize += 1;
        incVal(last);
        // First stays the same
    }
    return shouldAdd;
}

//edited but still needs check
bool cStringList ::insertAt(int index, std::string text){
//    bool shouldInsert = index >= 0 && index <= listCapacity && listSize < listCapacity;
//    if (shouldInsert){
//        if(index==0){
//            //decrement the first
//          first=first-1;
//        if(first<0){
//            first=listCapacity-1;
//        }
//        a[first] = text;
//        if(listSize==0){
//            last=first;
//        }
//        }
//        //increment the index
//        index=index+1;
//        if(index>0){
//            index=index%listCapacity;
//        }
//        a[index] = text;
//        listSize += 1;
//    }
//   //insert at the end
//    if(index==last){
//    //increment the last index
//        last=last+1;
//        last=(last)%listCapacity;
//        a[last] = text;
//    if(listSize==0){
//        last=first;
//    }
    bool shouldInsert = index >= 0 && index <= listCapacity && listSize < listCapacity;
    if (shouldInsert){
        // If so, move each item from given index one step up the list
        for (int i = listSize; i>index; i--){
            a[toCListIndex(i)] = a[toCListIndex(i-1)];
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


bool cStringList ::deleteAt(int index, std::string& text){
    bool shouldDelete = index >= 0 && index < listSize;
    if (shouldDelete){
        text = a[toCListIndex(index)];
        for (int i = index; i < listSize-1; i++){
            a[toCListIndex(i)] = a[toCListIndex(i+1)];
        }
        listSize -= 1;
        decVal(last);
    }
    return shouldDelete;
}

void cStringList ::clear(){
    // Author : Christian Ochei
    listSize = 0;
    first = 0;
    last = listCapacity-1;
}

void cStringList ::printIt() const {
    for (int i = 0; i<listSize; i++){
        std::cout << "At pos "<< i <<" there is " << a[toCListIndex(i)] << "\n";
    }
}

int cStringList ::getIndex(std::string text) const{
    int index = -1;
    for (int i = 0; i<listSize; i++){
        if (text == a[toCListIndex(i)]){
            index = i;
            break;
        }
    }
    return index;
}

bool cStringList ::readAt(int index, std::string& text) const {
    bool shouldRead = index >= 0 && index < listSize;
    if (shouldRead){
        text = a[toCListIndex(index)];
    }
    return shouldRead;
}


int cStringList ::count() const {
    return listSize;
}

int cStringList::toCListIndex(int value) const {
    return (first+value) % listCapacity;
}

bool cStringList::deleteFirst(std::string &text) {
    bool rc = listSize != 0;
    if (rc){
        text = a[first];
        incVal(first);
        listSize --;
    }
    return rc;
}

bool cStringList::deleteLast(std::string &text) {
    bool rc = listSize != 0;
    if (rc){
        text = a[last];
        decVal(last);
        listSize --;
    }
    return rc;
}


void cStringList::decVal(int &value) {
    value = (listCapacity + value - 1) % listCapacity;
}

void cStringList::incVal(int &value) {
    value = (listCapacity + value + 1) % listCapacity;
}
