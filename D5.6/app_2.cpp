//
//  main.cpp
//  Console Application
//
//  Created by George Romas on 12.02.23.
//
//  https://github.com/MadGeorge/edu-console-application
//
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <string>

using namespace std;

void printMatrix(int rowsCount, int columnsCount, int** matrix) {
    for (auto r = 0; r < rowsCount; r++) {
        printf(" [");
        for (auto c = 0; c < columnsCount; c++) {
            printf("%d", matrix[r][c]);
            if (c < (columnsCount - 1)) printf(", ");
        }
        printf("]\n");
    }
}

void swapColumnsInTheMatrix(int rowsCount, int columnsCount, int** matrix) {
    for (auto r = 0; r < rowsCount; r++) {
        swap(matrix[r][0], matrix[r][columnsCount - 1]);
    }
}

int main(int argc, const char * argv[]) {
    int rows, columns;

    printf("Square matrix rows sorter.\n");
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

    cin.ignore();

    for (auto i = 0; i < rows; i++) {
        printf("Input %d space separated numbers for row %d: ", columns, (i + 1));
        string str;
        getline(cin, str);

        matrix[i] = new int[columns];
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
    printMatrix(rows, columns, matrix);

    printf("\n");
    printf("Swapped matrix:\n");

    swapColumnsInTheMatrix(rows, columns, matrix);
    printMatrix(rows, columns, matrix);

    for (auto r = 0; r < rows; r++) {
        delete[] matrix[r];
    }

    delete[] matrix;

    return 0;
}
