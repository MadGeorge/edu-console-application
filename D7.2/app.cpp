//
//  main.cpp
//  Console Application
//
//  Created by George Romas on 17.02.23.
//
//  https://github.com/MadGeorge/edu-console-application
//

#include <stdio.h>
#include <string.h>
#include <random>

using namespace std;

void fillCollection(int size, int array[]) {
    mt19937 generator((random_device()()));
    uniform_int_distribution<> distr(-20, 20);
    
    for (auto i = 0; i < size; i++) {
        array[i] = distr(generator);
    }
}

int main() {
    auto sizeA = 05;
    auto sizeB = 15;
    int a[sizeA];
    int b[sizeB];

    fillCollection(sizeA, a);
    fillCollection(sizeB, b);

    printf("a: [");
    for (auto e : a) printf("%d, ", e);
    printf("]\n");

    printf("b: [");
    for (auto e : b) printf("%d, ", e);
    printf("]\n");

    return 0;
}
