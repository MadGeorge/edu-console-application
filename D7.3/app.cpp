//
//  main.cpp
//  Console Application
//
//  Created by George Romas on 23.02.23.
//
//  https://github.com/MadGeorge/edu-console-application
//

#include <stdio.h>
#include <string.h>

using namespace std;

bool isPerfectSquare(int input) {
    for (auto i = 1; (i * i) <= input; i++)
        if (i * i == input) return true;

    return false;
}

void isPerfectSquare(int input, bool&result) {
    result = false;

    for (auto i = 1; (i * i) <= input; i++) {
        if (i * i == input) {
            result = true;
            break;
        }
    }
}

void isPerfectSquare(int input, bool*result) {
    *result = false;

    for (auto i = 1; (i * i) <= input; i++) {
        if (i * i == input) {
            *result = true;
            break;
        }
    }
}


int main() {
    int a, b, c;

    printf("Input three space separated natural numbers: ");

    if (scanf("%d %d %d", &a, &b, &c) != 3) {
        printf("Invalid input. Please, provide three natural numbers.\n");
        return 1;
    }

    printf("Checking: %d, %d and %d\n", a, b, c);

    int input[3] = {a, b, c};
    int result = 0;

    for (auto i : input) if (isPerfectSquare(i)) result++;

    printf("OP_0: number of perfect squares: %d\n", result);

    bool match;
    result = 0;
    for (auto i : input) {
        isPerfectSquare(i, match);
        if (match) result++;
    }

    printf("OP_1: number of perfect squares: %d\n", result);

    result = 0;
    for (auto i : input) {
        isPerfectSquare(i, &match);
        if (match) result++;
    }

    printf("OP_2: number of perfect squares: %d\n", result);

    return 0;
}
