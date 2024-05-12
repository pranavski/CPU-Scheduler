/**
 * Driver.c
 *
 * Schedule is in the format
 *
 *  [name] [priority] [CPU burst]
 */

#include <fstream>
#include <sstream>
#include <iostream>

#include "task.h"
#include "schedulers.h"

using namespace std;

int main(int argc, char** argv){
    //basic error check to see if a input file has been passed in
    if (argc == 1){
        cerr << "No input file provided" << endl;
        return 0;
    }

    // Open an input stream and read the argument file
    ifstream in(argv[1]);
    if(!in){ // if file not found
        cerr << "File not found" << endl;
        return 0;
    }

    string task; // each line
    string temp; // temp string variable for getline statements

    string name;
    int priority;
    int burst;
    
    //parse each line of the file and gather relevant information
    while(getline(in, task)){
        istringstream iss(task);
        getline(iss, name, ',');
        getline(iss, temp, ',');
        priority = stoi(temp);
        getline(iss, temp, ',');
        burst = stoi(temp);
        
        add(name, priority, burst);
    }

    //close the stream
    in.close();

    //start the scheduling process
    schedule();

    return 0;
}
