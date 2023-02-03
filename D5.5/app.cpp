//
//  main.cpp
//  Console Application
//
//  Created by George Romas on 03.02.23.
//
//  https://github.com/MadGeorge/edu-console-application
//
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <string>

using namespace std;

void printMatrix(int size, int** matrix) {
    for (auto r = 0; r < size; r++) {
        printf(" [");
        for (auto c = 0; c < size; c++) {
            printf("%d", matrix[r][c]);
            if (c < (size - 1)) printf(", ");
        }
        printf("]\n");
    }
}

int** flipMatrix(int size, int** matrix) {
    int** result = new int*[size];

    for (auto r = 0; r < size; r++) result[r] = new int[size];

    for (auto r = 0; r < size; r++) {
        for (auto c = 0; c < size; c++) {
            result[c][r] = matrix[r][c];
        }
    }

    return result;
}

int main(int argc, const char * argv[]) {
    int size;

    printf("Square matrix diagonal flipper.\n");
    printf("Input number of square matrix size: ");

    if (scanf("%d", &size) != 1) {
        printf("Invalid input. Please, provide single number.\n");
        return 1;
    }

    int** matrix = new int*[size];

    printf("\n");

    cin.ignore();

    for (auto i = 0; i < size; i++) {
        printf("Input %d space separated numbers for row %d: ", size, (i + 1));
        string str;
        getline(cin, str);

        matrix[i] = new int[size];
        char* dup = strdup(str.c_str());
        char* pch = strtok(dup, " ");
        auto column = 0;
        while (pch != NULL) {
            matrix[i][column] = stoi(pch);
            column++;
            pch = strtok(NULL, " ");
        }

        free(dup);
        free(pch);

        fflush(stdin);
    }

    printf("\n");
    printf("Origin matrix:\n");
    printMatrix(size, matrix);

    printf("\n");
    printf("Flipped matrix:\n");

    printf("....\n");
    int** flipped = flipMatrix(size, matrix);

    printMatrix(size, flipped);

    delete[] matrix;
    delete[] flipped;

    return 0;
}
