#include "functions.h"

int main() {
    read_items();
    int program = run_program();
    while (program != -1){
        program = run_program();
    }
    write_items();
    return 0;
}


/*
 * To Add:
 * 1. Screen Clearing On Succesfull Add of Task
 * 2. Welcome Messages with Delay
 * 3. Exit Message with Delay
 */