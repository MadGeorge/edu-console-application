//
//  main.cpp
//  Console Application
//
//  Created by George Romas on 23.01.23.
//
//  https://github.com/MadGeorge/edu-console-application
//
#include <stdio.h>
#include <string>

using namespace std;

int main(int argc, const char * argv[]) {
    int input[argc - 1];
    for (auto i = 1; i < argc; i++) input[i - 1] = stoi(argv[i]);

    int min = input[0];
    int max = input[0];
    int sum = 0;

    printf("input is: ");
    for (int n : input) {
        printf("%d ", n);

        if (n < min) min = n;
        if (n > max) max = n;

        sum += n;
    }
    printf("\n");

    float avg = (float)sum / (float)(argc - 1);

    printf("min: %d, max: %d, sum: %d, avg: %.1f\n", min, max, sum, avg);
    return 0;
}
