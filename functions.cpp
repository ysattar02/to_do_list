//
// Created by Yusuf Sattar on 2/28/24.
//
#include "functions.h"
std::map<int, std::string> items;
const std::string PATHNAME = "/Users/yusufsattar/Desktop/to_do_list/logs.txt";

void welcome_message(){
    std::cout << "Initializing To Do List: \n";
    clear_screen(1);
}

void exit_message(){
    clear_screen(0);
    std::cout << "De-Initializing To Do List: \n";
    std::this_thread::sleep_for(std::chrono::seconds(1));
    std::cout << "Saving Data!: \n";
    std::this_thread::sleep_for(std::chrono::seconds(1));
    std::cout << "Shutdown Successfull! - Goodbye! \n";
    clear_screen(1);
}

void show_items(){
    std::map<int, std::string>::iterator it = items.begin();
    //add empty map check here
    std::cout << "-------------------- \n";
    while (it != items.end()){
        std::cout << "Task #: " << it->first << " - " << it->second << "\n";
        it++;
    }
    std::cout << "-------------------- \n";
}

int write_items(){
    std::ofstream logFile(PATHNAME, std::ios::trunc);
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
    return 0;
}

int read_items() {
    std::ifstream logFile(PATHNAME);
    if (!logFile.is_open()) {
        std::cerr << "Error: File Not Opened \n";
        return 0;
    }
    std::string line;
    while (std::getline(logFile, line)) {
        std::istringstream iss(line);
        std::string token;
        if (std::getline(iss, token, ':')) {
            int key = std::stoi(token);
            if (std::getline(iss, token)) {
                // Trim leading and trailing spaces from the value
                size_t start = token.find_first_not_of(" ");
                size_t end = token.find_last_not_of(" ");
                if (start != std::string::npos && end != std::string::npos)
                    items[key] = token.substr(start, end - start + 1);
            } else {
                std::cerr << "Error: Invalid line format in file \n";
            }
        } else {
            std::cerr << "Error: Invalid line format in file \n";
        }
    }
    logFile.close();
    if (logFile.is_open()) {
        std::cerr << "Error: File Not Closed \n";
        return 0;
    }
    return 0;
}

int add_item(){
    clear_screen(0);
    std::cout << "Enter Task ID: \n";
    int task_id;
    std::cin >> task_id;
    std::cin.ignore();
    std::cin.clear();
    std::cout << "Enter Task Description: \n";
    std::string task;
    std::getline(std::cin, task);
    items[task_id] = task;
    clear_screen(1);
    return 0;
}

int complete_item(){
    std::cout << "Enter Task ID to Complete: \n";
    int task_id;
    std::cin >> task_id;
    std::map<int, std::string>::iterator it = items.begin();
    while (it != items.end()){
        if (it->first == task_id){
            items.erase(it->first);
            std::cout << "Task " << task_id << " Completed! \n";
            clear_screen(1);
            return 0;
        }
        it++;
    }
    std::cerr << "Task ID Not Found \n";
    clear_screen(1);
    return -1;
}

void print_user_choice(){
    std::cout << "Enter 1 to Add a Task: \n";
    std::cout << "Enter 2 to See Existing Tasks: \n";
    std::cout << "Enter 3 to Complete a Task \n";
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
    else if (user_choice == 3){
        complete_item();
    }
    else{
        return -1;
    }
    return 1;
}

void clear_screen(int seconds){
    std::this_thread::sleep_for(std::chrono::seconds(seconds));
    system("clear");
}
