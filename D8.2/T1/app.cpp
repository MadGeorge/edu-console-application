//
//  main.cpp
//  Console Application
//
//  Created by George Romas on 02.03.23.
//
//  https://github.com/MadGeorge/edu-console-application
//

#include <stdio.h>
#include <stdexcept>

using namespace std;

float divide(int input) {
    if (input == 0) throw runtime_error("Divide by zero exception");
    return 1024 / input;
}

int main() {

    try {
        divide(0);
    } catch (runtime_error err) {
        printf("Division by zero is not predictable\n");
    }

    return 0;
}
