#include <string>
#include <iostream>
#include "p1.h"

stringList::stringList(int listCapacity){
    a = new std::string[listCapacity];
    this->listCapacity = listCapacity;
    listSize = 0;
}

stringList::~stringList(){
    delete[] a;
}
//edited
bool stringList::insert(std::string text){
    bool rc = listSize < listCapacity;
    if (rc){
        //decrement the first
          first=first-1;
        if(first<0){
            first=listCapacity-1;
        }
        a[first] = text;
        if(listSize==0){
            last=first;
        }
        listSize += 1;
    }
    return rc;
}

//edited needs check
bool stringList::add(std::string text){
    bool shouldAdd = listSize < listCapacity;
    if (shouldAdd){
        //increment the last index
        last=last+1;
        last=(last)%listCapacity;
        a[last] = text;
    if(listSize==0){
        last=first;
    }
        listSize += 1;
    }
    return shouldAdd;
}
//edited but still needs check
bool stringList::insertAt(int index, std::string text){
    bool shouldInsert = index >= 0 && index <= listCapacity && listSize < listCapacity;
    if (shouldInsert){
        if(index==0){
            //decrement the first
          first=first-1;
        if(first<0){
            first=listCapacity-1;
        }
        a[first] = text;
        if(listSize==0){
            last=first;
        }
        }
        //increment the index
        index=index+1;
        if(index>0){
            index=index%listCapacity;
        }
        a[index] = text;
        listSize += 1;
    }
   //insert at the end 
    if(index==last){
    //increment the last index
        last=last+1;
        last=(last)%listCapacity;
        a[last] = text;
    if(listSize==0){
        last=first;
    }
    }
    return shouldInsert;
}


bool stringList::deleteAt(int index, std::string text){
    bool shouldDelete = index >= 0 && index < listSize;
    if (shouldDelete){
        for (int i = index; i < listSize-1; i++){
            a[i] = a[i+1];
        }
        listSize -= 1;
    }
    return shouldDelete;
}

void stringList::clear(){
    listSize = 0;
}

void stringList::printIt() const {
    for (int i = 0; i<listSize; i++){
        std::cout << "At pos "<< i <<" there is " << a[i] << "\n";
    }
}

int stringList::getIndex(std::string text) const{
    int index = -1;
    for (int i = 0; i<listSize; i++){
        if (text == a[i]){
            index = i;
            break;
        }
    }
    return index;
}

bool stringList::readAt(int index, std::string& text) const {
    bool shouldRead = index >= 0 && index < listCapacity;
    if (shouldRead){
        text = a[index];
    }
    return shouldRead;
}


int stringList::count() const {
    return listSize;
}
