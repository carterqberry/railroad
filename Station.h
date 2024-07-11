#ifndef RAILROAD_STATION_H
#define RAILROAD_STATION_H

#include "Queue.h"
#include "Stack.h"
#include "Vector.h"
#include "Car.h"

using namespace std;

template <typename T>
class Station : public Queue<T>, public Stack<T>, public Vector<T>{
public:
    Station() :
            m_turntableCar(NULL),
            empty(true){}
    ~Station(){}

    string addCar(const T& car){  //adds a car to the turntable
        if(m_turntableCar != NULL){
            return "Turntable occupied!";
        }
        else{
            m_turntableCar = car;
            return "OK";
        }
    }
    string addQueue(){  //moves turntable car to queue
        if(m_turntableCar == NULL){
            return "Turntable empty!";
        }
        else{
            m_queue.push(m_turntableCar);
            m_turntableCar = NULL;
            return "OK";
        }
    }
    string addStack(){  //moves turntable car to stack
        if(m_turntableCar == NULL){
            return "Turntable empty!";
        }
        else{
            m_stack.push(m_turntableCar);
            m_turntableCar = NULL;
            return "OK";
        }
    }
    string removeCar(){  //moves turntable car to vector
        if(m_turntableCar == NULL){
            return "Turntable empty!";
        }
        else{
            m_train.push_back(m_turntableCar);
            m_turntableCar = NULL;
            return "OK";
        }
    }
    string removeQueue(){  //moves the head of the queue to the turntable
        if(m_turntableCar != NULL){
            return "Turntable occupied!";
        }
        else if(m_queue.empty()){
            return "Queue empty!";
        }
        else{
            m_turntableCar = m_queue.top();
            m_queue.pop();
            return "OK";
        }
    }
    string removeStack(){  //moves the head of the queue to the turntable
        if(m_turntableCar != NULL){
            return "Turntable occupied!";
        }
        else if(m_stack.empty()){
            return "Stack empty!";
        }
        else{
            m_turntableCar = m_stack.top();
            m_stack.pop();
            return "OK";
        }
    }
    string topCar(){  //outputs turntable car
        if(m_turntableCar == NULL){
            return "Turntable empty!";
        }
        else{
            return m_turntableCar.toString();
        }
    }
    string topQueue(){  //outputs front of the queue
        if(m_queue.top() == NULL){
            return "Queue empty!";
        }
        else{
            return m_queue.top().toString();
        }
    }
    string topStack(){  //outputs top of the stack
        if(m_stack.top() == NULL){
            return "Stack empty!";
        }
        else{
            return m_stack.top().toString();
        }
    }
    string sizeQueue(){  //outputs the size of the queue
        return to_string(m_queue.size());
    }
    string sizeStack(){  //outputs the size of the stack
        return to_string(m_stack.size());
    }
    string sizeTrain(){  //outputs the size of the train
        return to_string(m_train.size());
    }
    string printQueue(){  //outputs all items in the queue
        stringstream outQ;
        for(int i = 0; i < m_queue.size(); i++){
            outQ << m_queue.at(i).toString() << " ";
        }
        return outQ.str();
    }
    string printStack(){  //outputs all items in the stack
        stringstream outS;
        for(int i = 0; i < m_stack.size(); i++){
            outS << m_stack.at(i).toString() << " ";
        }
        return outS.str();
    }
    string toString(){  //outputs all the trains in the vector
        if(m_train.empty()){
            return "Train empty!";
        }
        else{
            stringstream outT;
            for(int i = 0; i < m_train.size(); i++){
                outT << m_train.at(i).toString() << " ";
            }
            return outT.str();
        }
    }
    string find(T car){  //finds the location of a car and the index
        int returnIndex;
        if(m_turntableCar == car){
            return "Turntable";
        }
        else if((returnIndex = m_queue.find(car)) >= 0){
            return "Queue[" + to_string(returnIndex) + "]";
        }
        else if((returnIndex = m_stack.find(car)) >= 0){
            return "Stack[" + to_string(returnIndex) + "]";
        }
        else if((returnIndex = m_train.find(car)) >= 0){
            return "Train[" + to_string(returnIndex) + "]";
        }
        else{
            return "Not Found!";
        }
    }
    friend ostream& operator<<(ostream& os, Station& r){
        return os << r.toString();
    }

private:
    T m_turntableCar;
    Vector<T> m_train;
    Queue<T> m_queue;
    Stack<T> m_stack;
    bool empty;
};

#endif //RAILROAD_STATION_H
