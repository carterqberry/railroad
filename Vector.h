#ifndef RAILROAD_VECTOR_H
#define RAILROAD_VECTOR_H

#include "Deque.h"

template <typename T>
class Vector{
public:
    Vector(){}
    ~Vector(){}
    void push_back(const T data){ m_vector.push_back(data); }
    void pop_back(){ m_vector.pop_back(); }
    T& back(){ return m_vector.back(); }
    int size(){ return m_vector.size(); }
    T& at(int index){ return m_vector.at(index); }
    bool empty() const { return m_vector.empty(); }
    int find(T& value) { return m_vector.find(value); }
    std::string toString() const { return m_vector.toString(); }
    friend std::ostream& operator<<(std::ostream& os, Vector& r){ return os << r.toString(); }
private:
    Deque<T> m_vector;
};

#endif //RAILROAD_VECTOR_H
