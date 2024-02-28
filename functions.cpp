//
// Created by Yusuf Sattar on 2/28/24.
//
#include "functions.h"
std::map<int, std::string> items;

void welcome_message(){
    //to do
}

void exit_message(){
    //to do
}

void show_items(){
    //done
    std::map<int, std::string>::iterator it = items.begin();
    //add empty map check here
    while (it != items.end()){
        std::cout << "Task #: " << it->first << ", Task: " << it->second << "\n";
        it++;
    }
}

int write_items(){
    //to do
    std::ofstream logFile("logs.txt", std::ios::trunc);
    if (!logFile.is_open()){
        std::cerr << "Error: File Not Opened \n";
        return 0;
    }
    std::map<int, std::string>::iterator it = items.begin();
    while (it != items.end()){
        logFile << it->first << ":" << it->second << "\n";
        it++;
    }
    logFile.close();
    if (logFile.is_open()){
        std::cerr << "Error: File Not Closed \n";
        return 0;
    }
    std::cout << "Write Op Successful \n";
    return 0;
}

int read_items(){
    //to do
}

