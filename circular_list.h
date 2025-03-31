#ifndef CIRCULAR_LIST_H
#define CIRCULAR_LIST_H

#include <stdexcept>
#include <iostream>

using namespace std;

namespace myproject {


class MyProjectException : public runtime_error {
public:
    explicit MyProjectException(const string& msg) : runtime_error(msg) {}
};

class CircularList {
private:
    struct Implementation;
    Implementation* impl;

public:
    CircularList();
    CircularList(const CircularList& other);
    CircularList& operator=(const CircularList& other);
    ~CircularList();

    void add(int value);
    void remove(int value);
    void clear();
    void update(int oldValue, int newValue);

    CircularList& operator+=(int value);   
    CircularList& operator-=(int value);   
    bool operator==(const CircularList& other) const;
    bool operator!=(const CircularList& other) const;
    int operator[](size_t index) const;
    void operator!();

    bool contains(int value) const;
    size_t size() const;
    void print() const;
};

}

#endif