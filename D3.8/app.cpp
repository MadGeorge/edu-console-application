//
//  main.cpp
//  Console Application
//
//  Created by George Romas on 23.12.22.
//
//  https://github.com/MadGeorge/edu-console-application
//

#include <stdio.h>
#include <string>

using namespace std;

int main(int argc, const char * argv[]) {
    string input = "";
    int min = stoi(argv[1]);
    int max = stoi(argv[1]);
    int sum = 0;
    int cnt = 0;

    for (int i = 1; i <= (argc - 1); i++) {
        int number = stoi(argv[i]);
        input += argv[i];
        input += ", ";

        if (number < min) min = number;
        if (number > max) max = number;

        sum += number;
        cnt++;
    }

    float avg = (float)sum / (float)cnt;

    printf("input is: %s\n", input.c_str());
    printf("min: %d, max: %d, sum: %d, avg: %.1f\n", min, max, sum, avg);

    return 0;
}
