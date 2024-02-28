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
    //done
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
    std::cout << "Write Opp Successful \n";
    return 0;
}

int read_items(){
    //to do
    std::ifstream logFile("logs.txt");
    if (!logFile.is_open()){
        std::cerr << "Error: File Not Opened \n";
        return 0;
    }
    std::string line;
    while (std::getline(logFile, line)){
        std::istringstream iss(line);
        int key;
        std::string value;
        char delimiter;
        if (!(iss >> key >> delimiter >> value)) {
            std::cerr << "Error: Invalid line format in file \n";
            continue;
        }
        items[key] = value;
    }
    logFile.close();
    if (logFile.is_open()){
        std::cerr << "Error: File Not Closed \n";
        return 0;
    }
    std::cout << "Read Opp Successful \n";
    return 0;
}

int add_item(){
    std::cout << "Enter Task ID: \n";
    int task_id;
    std::cin >> task_id;
    std::cin.ignore();
    std::cin.clear();
    std::cout << "Enter Task Description: \n";
    std::string task;
    std::getline(std::cin, task);
    items[task_id] = task;
    return 0;
}

void print_user_choice(){
    std::cout << "Enter 1 to Add a Task: \n";
    std::cout << "Enter 2 to See Existing Tasks: \n";
    std::cout << "Enter Any Other Key to Exit: \n";
}

int run_program(){
    print_user_choice();
    int user_choice = -1;
    std::cin >> user_choice;
    if (user_choice == 1){
        add_item();
        std::cout << "Item Added! \n";
    }
    else if (user_choice == 2){
        show_items();
    }
    else{
        return -1;
    }
    return 1;
}

