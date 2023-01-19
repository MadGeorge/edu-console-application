//
//  main.cpp
//  Console Application
//
//  Created by George Romas on 19.01.23.
//
//  https://github.com/MadGeorge/edu-console-application
//
#include <stdio.h>
#include <string>

using namespace std;

int main(int argc, const char * argv[]) {
    int min = stoi(argv[1]);
    int max = stoi(argv[1]);
    int sum = 0;

    printf("input is: ");
    for (auto i = 1; i < argc; i++) {
        auto arg = stoi(argv[i]);

        printf("%d", arg);
        if (i < argc - 1) printf(", ");

        if (arg < min) min = arg;
        if (arg > max) max = arg;

        sum += arg;
    }
    printf("\n");

    float avg = (float)sum / (float)(argc - 1);

    printf("min: %d, max: %d, sum: %d, avg: %.1f\n", min, max, sum, avg);
    return 0;
}
