//
//  main.cpp
//  Console Application
//
//  Created by George Romas on 15.02.23.
//
//  https://github.com/MadGeorge/edu-console-application
//

#include <stdio.h>
#include <string.h>

using namespace std;

int main() {
    char str[256];

    printf("input max 255 characters: ");
    fgets(str, sizeof(str), stdin);

    printf("Input is: %s\n", str);

    for (auto i = 0; i < strlen(str); i++)
        str[i] = str[i + 1];

    printf("Remove character at 0: %s\n", str);

    return 0;
}
