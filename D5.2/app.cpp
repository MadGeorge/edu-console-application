//
//  main.cpp
//  Console Application
//
//  Created by George Romas on 24.01.23.
//
//  https://github.com/MadGeorge/edu-console-application
//
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <string>
#include <vector>

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

    int matrix[rows][columns];

    printf("\n");

    cin.ignore();

    for (int i = 0; i < rows; i++) {
        printf("Input %d space separated numbers for row %d: ", columns, (i + 1));
        string str;
        getline(cin, str);

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
    printf("Your matrix looks like:\n");
    printf("[\n");
    for (auto r = 0; r < rows; r++) {
        printf(" [");
        for (auto c = 0; c < columns; c++) {
            printf("%d", matrix[r][c]);
            if (c < (columns - 1)) printf(", ");
        }
        printf("]\n");
    }
    printf("]\n");

    return 0;
}
