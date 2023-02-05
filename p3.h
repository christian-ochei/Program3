// Project: P1B
// Christian Ochei, Habtamu Wario

#ifndef __P3_H
#define __P3_H

#include <string>

class cStringList {
private:
    std::string * a;
    int listCapacity;
    int listSize;
    int first; // to track the first entry of the list
    int last; // to track the last entry of the list

    void incVal(int &value); // increments the passed value, wrapping its value to 0 if necessary
    void decVal(int &value); // decrements the passed value, wrapping its value to capacity-1 if
    int toCListIndex(int value) const;

public:
    cStringList(int listCapacity = 100);
    bool deleteFirst(std::string &text);
    bool deleteLast(std::string &text);
    ~cStringList ();

    bool insert(std::string text);
    bool add(std::string text);
    bool insertAt(int index, std::string text);
    bool deleteAt(int index, std::string& text);
    void clear();
    void printIt() const;
    int getIndex(std::string text) const;
    bool readAt(int index,std::string& text) const;
    int count() const;
};

#endif