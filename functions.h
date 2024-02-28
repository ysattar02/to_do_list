//
// Created by Yusuf Sattar on 2/28/24.
//

#ifndef TO_DO_LIST_FUNCTIONS_H
#define TO_DO_LIST_FUNCTIONS_H
#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <chrono>
#include <thread>
#include <map>

extern std::map<int, std::string> items;
extern const std::string PATHNAME;

void welcome_message();
void exit_message();
void show_items();
int write_items();
int read_items();
int add_item();
int complete_item();
void print_user_choice();
int run_program();
void clear_screen(int seconds);

#endif //TO_DO_LIST_FUNCTIONS_H
