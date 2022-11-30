//
//  main.cpp
//  Console Application
//
//  Created by George Romas on 28.11.22.
//
//  https://github.com/MadGeorge/edu-console-application
//

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

// infinitely recursive
int getInput() {
    fflush(stdin);

    float a,b;

    printf("You input is: ");

    if (scanf("%f %f", &a, &b) == 2) {
        printf("Comparing: %f > %f\n", a, b);

        if (a == b) {
            printf("Numbers are EQUALS\n");
        } else if (a > b) {
            printf("First number is GREATER\n");
        } else {
            printf("First number is SMALLER\n");
        }

        printf("\nInput next pair of numbers or press CNTRL+C to exit\n");

        return getInput();
    }

    printf("Invalid input. Please, try again.\n");

    return getInput();
}

int main(int argc, const char * argv[]) {
    printf("Input two numbers separated by the space.\n");
    printf("Use dot as decimal separator.\n");
    printf("Example input: '9.4 54.034' and not '9,4 54,034'\n");

    return getInput();
}
