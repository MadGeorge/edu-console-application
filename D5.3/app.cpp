//
//  main.cpp
//  Console Application
//
//  Created by George Romas on 28.01.23.
//
//  https://github.com/MadGeorge/edu-console-application
//
#include <stdio.h>
#include <random>

using namespace std;

int main(int argc, const char * argv[]) {
    int rows, columns;

    printf("Two-dimensional array visualisations.\n");
    printf("Input number of rows: ");

    if (scanf("%d", &rows) != 1) {
        printf("Invalid input. Please, provide single number.\n");
        return 1;
    }

    printf("Input number of columns: ");

    if (scanf("%d", &columns) != 1) {
        printf("Invalid input. Please, provide single number.\n");
        return 1;
    }

    int** matrix = new int*[rows];

    printf("\n");

    mt19937 generator((random_device()()));
    uniform_int_distribution<> distr(-2, 7);

    for (int r = 0; r < rows; r++) {
        matrix[r] = new int[columns];

        for (int c = 0; c < columns; c++) matrix[r][c] = distr(generator);
    }

    printf("\n");
    printf("Your matrix looks like:\n");
    printf("[\n");
    for (auto r = 0; r < rows; r++) {
        printf(" [");
        for (auto c = 0; c < columns; c++) {
            if (matrix[r][c] >= 0) printf("+");
            printf("%d", matrix[r][c]);
            if (c < (columns - 1)) printf(", ");
        }
        printf("]\n");
    }
    printf("]\n");

    for (auto r = 0; r < rows; r++) delete[] matrix[r];
    delete[] matrix;

    return 0;
}
