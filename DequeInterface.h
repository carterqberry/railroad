#ifndef RAILROAD_DEQUEINTERFACE_H
#define RAILROAD_DEQUEINTERFACE_H

#include <string>
#define DEFAULT_CAPACITY 4

using namespace std;

template<typename T>
class DequeInterface{
public:
    DequeInterface(){}
    virtual ~DequeInterface(){}
    virtual void push_front(const T& value) = 0;  //inserts item at the front of the deque
    virtual void push_back(const T& value) = 0;  //inserts item at the back of the deque
    virtual void pop_front() = 0;  //removes the front item from the deque
    virtual void pop_back() = 0;  //removes the back item from the deque
    virtual T& front() = 0;  //returns the front item in the deque
    virtual T& back() = 0;  //returns the back item in the deque
    virtual int size() = 0;  //returns the number of items in the deque
    virtual bool empty() const = 0;  //returns true if the deque is empty
    virtual T& at(int index) = 0;  //returns item at the index in the deque
    virtual string toString() const = 0;  //returns the items in the deque
};

#endif //RAILROAD_DEQUEINTERFACE_H
