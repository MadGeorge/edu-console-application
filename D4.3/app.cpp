//
//  main.cpp
//  Console Application
//
//  Created by George Romas on 16.01.23.
//
//  https://github.com/MadGeorge/edu-console-application
//
#include <stdio.h>
#include <string>
#include <unistd.h>

using namespace std;

void draw(int array[], int size, int position) {
    #if defined(_WIN32)
    system("cls");
    #else
    system("clear");
    #endif

    printf("\n\n");

    printf("[");
    for (auto i = 0; i < size; i++) {
        printf("%d", array[i]);
        if (i < (size - 1)) printf(", ");
    }
    printf("]\n");

    printf(" ");
    for (int i = 0; i < position; ++i) {
        printf("   ");
    }
    printf("^\n");
    usleep(10e3);
}

int main(int argc, const char * argv[]) {
    auto max = 100;
    int total = stoi(argv[1]);

    if (total > max) {
        printf("Maximum number of items is %d\n", max);
        return 1;
    }

    int numbers[total];

    for(int i = 0; i < total; i++) numbers[i] = (rand() % 10);

    auto currentIndex = 0;

    draw(numbers, total, 0);
    usleep(10e2);

    auto wasSwapped = false;

    while (true) {
        if (currentIndex >= (total - 1)) {
            currentIndex = 0;
            wasSwapped = false;
        }

        auto nextIndex = currentIndex + 1;
        auto current = numbers[currentIndex];
        auto next = numbers[nextIndex];

        draw(numbers, total, currentIndex);

        if (current > next) {
            wasSwapped = true;
            swap(numbers[currentIndex], numbers[nextIndex]);

            draw(numbers, total, currentIndex);

            currentIndex++;
            continue;
        }

        draw(numbers, total, currentIndex);

        currentIndex++;

        if ((currentIndex == (total - 1)) && !wasSwapped) break;
    }

    printf("SORTED\n");

    return 0;
}
