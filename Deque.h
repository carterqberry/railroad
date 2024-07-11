#ifndef RAILROAD_DEQUE_H
#define RAILROAD_DEQUE_H

#include "DequeInterface.h"
#include <algorithm>

using namespace std;

template<typename T>
class Deque : public DequeInterface<T>{
public:
    Deque(void) :
            capacity(DEFAULT_CAPACITY),
            num_items(0),
            front_index(0),
            back_index(0),
            data_ptr(new T[DEFAULT_CAPACITY]) {}
    ~Deque() { delete[] data_ptr; }

    void push_front(const T& value){  //inserts an item at the front of the deque
        if(num_items == capacity){
            reallocate();  //reallocates if DEFAULT_CAPACITY is reached
        }
        for(int i = num_items; i > 0; --i){
            data_ptr[i] = data_ptr[i - 1];
        }
        data_ptr[0] = value;
        num_items++;
        if(num_items > 1){
            back_index++;
        }
    }
    void push_back(const T& value){  //inserts an item at the back of the deque
        if(num_items == capacity){
            reallocate();  //reallocates if DEFAULT_CAPACITY is reached
        }
        data_ptr[num_items] = value;
        num_items++;
        if(num_items > 1){
            back_index++;
        }
    }
    void pop_front(){  //removes the front item at the deque
        if(num_items > 0){
            for(int i = 0; i < num_items; i++){
                data_ptr[i] = data_ptr[i + 1];  //moves all items back one
            }
            data_ptr[back_index] = NULL;
            num_items--;
            if(back_index != 0){
                back_index--;
            }
        }
    }
    void pop_back(){  //removes the back item from the deque
        if(num_items > 0){
            data_ptr[back_index] = NULL;
            num_items--;
            if(back_index != 0){
                back_index--;
            }
        }
    }
    T& front(){  //returns the front item of the deque
        return data_ptr[front_index];
    }
    T& back(){  //returns the back item of the deque
        return data_ptr[back_index];
    }
    int size(){  //returns the number of items in the deque
        return num_items;
    }
    bool empty() const {  //returns true if the deque is empty
        if(num_items == 0){
            return true;
        }
        else{
            return false;
        }
    }
    T& at(int index){  //returns the item at the index
        return data_ptr[index];
    }
    int find(T& value){  //returns the index of the value
        for(int i = 0; i < num_items; i++){
            if(data_ptr[i] == value){
                return i;
            }
        }
        return -1;
    }
    string toString() const{  //returns the items in the deque
        stringstream out;
        for(int i = 0; i < num_items; i++){
            out << data_ptr[i] << " ";
        }
        return out.str();
    }
    friend ostream& operator<<(ostream& os, Deque& r){
        return os << r.toString();
    }

private:
    int capacity;
    int num_items;
    int front_index;
    int back_index;
    T* data_ptr;

    void reallocate();
};

template<typename T>
void Deque<T>::reallocate(){
    T* new_data_ptr = new T[2 * capacity];
    for(int i = 0; i < num_items; i++){
        new_data_ptr[i] = data_ptr[front_index];
        front_index = (front_index + 1) % capacity;
    }
    front_index = 0;
    back_index = num_items - 1;
    capacity = 2 * capacity;
    swap(data_ptr, new_data_ptr);
    delete[] new_data_ptr;
}

#endif //RAILROAD_DEQUE_H
