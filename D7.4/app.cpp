//
//  main.cpp
//  Console Application
//
//  Created by George Romas on 01.03.23.
//
//  https://github.com/MadGeorge/edu-console-application
//

#include <iostream>
#include <stdio.h>
#include <string.h>
#include <string>

using namespace std;

string replaceFirstAndLast(string input, char replacement) {
    input[0] = replacement;
    input[input.length() - 1] = replacement;

    return input;
}

string trim(string input) {
    string tmp = "";

    bool isFirstNonSpaceCharacterMet = false;
    for (auto i = 0; i < input.length(); i++) {
        auto character = input[i];

        if (isFirstNonSpaceCharacterMet) {
            tmp.push_back(character);
            continue;
        }

        if (character != ' ') {
            tmp.push_back(character);
            isFirstNonSpaceCharacterMet = true;
        }
    }

    string result = "";

    isFirstNonSpaceCharacterMet = false;
    for (auto i = (tmp.length() - 1); i >= 0; i--) {
        auto character = tmp[i];

        if (isFirstNonSpaceCharacterMet || i == 0) {
            result.insert(0, 1, character);

            if (i == 0) break;
            else continue;
        }

        if (character != ' ') {
            result.insert(0, 1, character);
            isFirstNonSpaceCharacterMet = true;
        }
    }

    return result;
}


int main() {
    printf("Input some string: ");
    string inputA;
    fflush(stdin);
    getline(cin, inputA);

    printf("Input single character: ");

    char c;
    if (scanf("%c", &c) != 1) {
        printf("Invalid input.\n");
        return 1;
    }

    printf("Origin input: [%s]\n", inputA.c_str());
    printf("Replacing first and last with: [%c]: %s\n", c, replaceFirstAndLast(inputA, c).c_str());

    printf("\n\nInput string to trim: ");

    string inputB;
    fflush(stdin);
    getline(cin, inputB);

    printf("Origin input: [%s]\n", inputB.c_str());
    printf("Trimmed: [%s]\n", trim(inputB).c_str());

    return 0;
}
