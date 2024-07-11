#ifndef RAILROAD_CAR_H
#define RAILROAD_CAR_H

#include <string>
#include <sstream>

struct Car{
    Car() : carNum(0){}
    Car(int number){ carNum = number; }
    ~Car(){}
    unsigned int carNum;
    bool operator == (const Car car){ return this->carNum == car.carNum; }
    bool operator != (const Car car){ return this->carNum != car.carNum; }

    std::string toString() const{
        std::stringstream out;
        out << carNum;
        return out.str();
    }
    friend std::ostream& operator<< (std::ostream& os, const Car& c){ return os << c.toString(); }
};

#endif //RAILROAD_CAR_H
