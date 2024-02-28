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
 DONE * 1. Add Parameter to clear screen function to handle the time
 * 2. Welcome Messages with Delay
 * 3. Exit Message with Delay
 * 4. Deleting Task Functionality
 * 5. Ensure no duplicate Task numbers
 * 6. If Map is empty, print a message saying that if user chooses show items
 */