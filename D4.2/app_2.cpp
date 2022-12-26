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
    int numbers[total];

    for (int i = 0; i < total; i++) {
        numbers[i] = i;
    }

    // MARK - output

    auto count = sizeof(numbers) / sizeof(int);

    printf("[");

    for (int i = 0; i < count; i++) {
        printf("%d", numbers[i]);

        if (i < (count - 1)) printf(" ");
    }

    printf("]\n");

    return 0;
}
