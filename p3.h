// Project: P1B
// Christian Ochei, Habtamu Wario

#ifndef __P3_H
#define __P3_H

#include <string>

class stringList{
private:
    std::string * a;
    int listCapacity;
    int listSize;

public:
    stringList(int listCapacity = 100);
    ~stringList();

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