#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "Station.h"

using namespace std;

#ifdef _MSC_VER // Memory leak check
#define _CRTDBG_MAP_ALLOC
#include <crtdbg.h>
#define VS_MEM_CHECK _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
#else
#define VS_MEM_CHECK
#endif

int main(int argc, char* argv[]) {
    VS_MEM_CHECK               // Enable memory leak check

    //open input and output files
    if(argc < 3){
        cerr << "Please provide name of input and output files.";
        return 1;
    }
    cout << "Input file: " << argv[1] << endl;
    ifstream in(argv[1]);   //reading from input file
    if(!in.is_open()){
        cerr << "Unable to open " << argv[1] << " for input.";
        return 2;
    }
    cout << "Output file: " << argv[2] << endl;
    ofstream out(argv[2]);   //writing to output file
    if(!out){
        in.close();
        cerr << "Unable to open " << argv[2] << " for output.";
        return 3;
    }

    //read through the input files and output strings
    string line;
    Station<Car> myStation;

    while(getline(in, line)){
        string command;
        string location;
        string dataStr;
        int data;
        try{
            if(line.size() == 0){
                continue;
            }
            out << line << " ";
            istringstream iss(line);
            iss >> command;
            iss >> dataStr;
            if(dataStr != ""){  //converts data from string to int
                data = stoi(dataStr);
            }
            location = command.substr(command.find(':') + 1, command.find( ' ' - 1));
            command = command.substr(0, command.find(':'));

            if(command == "Add") {
                if (location == "station") {  //adds new car to turntable
                    Car car(data);
                    out << myStation.addCar(car);
                }
                else if (location == "queue") {  //moves car from turntable to queue
                    out << myStation.addQueue();
                }
                else if (location == "stack") {  //moves car from turntable to stack
                    out << myStation.addStack();
                }
            }
            else if(command == "Remove"){
                if(location == "station"){  // move car from turntable
                    out << myStation.removeCar();
                }
                else if(location == "queue"){  // move car from queue ad to turntable
                    out << myStation.removeQueue();
                }
                else if(location == "stack"){  // move car from stack and to turntable
                    out << myStation.removeStack();
                }
            }
            else if(command == "Top"){
                if (location == "station"){	 //ouputs turntable car
                    out << myStation.topCar();
                }
                else if(location == "queue"){  //outputs front of the queue
                    out << myStation.topQueue();
                }
                else if(location == "stack"){  //outputs the top of the stack
                    out << myStation.topStack();
                }
            }
            else if (command == "Size"){
                if(location == "queue"){  //outputs the size of the queue
                    out << myStation.sizeQueue();
                }
                else if(location == "stack"){  //outputs the size of the stack
                    out << myStation.sizeStack();
                }
                else if(location == "train"){  //outputs the size of the train
                    out << myStation.sizeTrain();
                }
            }
            else if(command == "Queue"){  //outputs all items in the queue
                out << myStation.printQueue();
            }
            else if(command == "Stack"){  //outputs all items in the stack
                out << myStation.printStack();
            }
            else if(command == "Train"){ //outputs all the trains in the vector
                out << myStation;
            }
            else if(command == "Find"){	//finds the location of a car and the index
                Car car(data);
                out << myStation.find(car);
            }
            else{
                throw string("Unexpected command!");
            }
        }
        catch(string & str){
            out << str;
        }
        out << endl;
    }
    return 0;
}
