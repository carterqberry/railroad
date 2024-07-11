#ifndef RAILROAD_STACK_H
#define RAILROAD_STACK_H

#include "Deque.h"

template <typename T>
class Stack{
public:
    Stack(){}
    ~Stack(){}
    void push(const T data){ m_stack.push_back(data); }
    void pop(){ m_stack.pop_back(); }
    T& top(){ return m_stack.back(); }
    int size(){ return m_stack.size(); }
    T& at(int index){ return m_stack.at(index); }
    bool empty() const { return m_stack.empty(); }
    int find(T& value) { return m_stack.find(value); }
    std::string toString() const { return m_stack.toString(); }
    friend std::ostream& operator<< (std::ostream& os, Stack& r) { return os << r.toString(); }
private:
    Deque<T> m_stack;
};
#endif //RAILROAD_STACK_H
