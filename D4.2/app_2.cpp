//
//  main.cpp
//  Console Application
//
//  Created by George Romas on 26.12.22.
//
//  https://github.com/MadGeorge/edu-console-application
//

#include <stdio.h>
#include <string>

using namespace std;

int main(int argc, const char * argv[]) {
    // MARK - populate
    int total = stoi(argv[1]);
    int* numbers = new int[total];

    for (int i = 0; i < total; i++) {
        numbers[i] = i;
    }

    // MARK - output

    printf("[");

    for (int i = 0; i < total; i++) {
        printf("%d", numbers[i]);

        if (i < (total - 1)) printf(" ");
    }

    printf("]\n");

    delete[] numbers;

    return 0;
}
