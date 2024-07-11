#ifndef RAILROAD_QUEUE_H
#define RAILROAD_QUEUE_H

#include "Deque.h"

template <typename T>
class Queue{
public:
    Queue(){}
    ~Queue(){}
    void push(const T data){ m_queue.push_back(data); }
    void pop(){ m_queue.pop_front(); }
    T& top(){ return m_queue.front(); }
    int size(){ return m_queue.size(); }
    T& at(int index){ return m_queue.at(index); }
    bool empty() const { return m_queue.empty(); }
    int find(T& value) { return m_queue.find(value); }
    std::string toString() const { return m_queue.toString(); }
    friend std::ostream& operator<<(std::ostream& os, Queue& r) { return os << r.toString(); }
private:
    Deque<T> m_queue;
};

#endif //RAILROAD_QUEUE_H
