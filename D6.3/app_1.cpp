//
//  main.cpp
//  Console Application
//
//  Created by George Romas on 14.02.23.
//
//  https://github.com/MadGeorge/edu-console-application
//

#include <stdio.h>

using namespace std;

int main(int argc, const char * argv[]) {
    char str[256];

    printf("input max 256 characters: ");
    fgets(str, sizeof(str), stdin);

    printf("Second character is: %c\n", str[1]);

    return 0;
}
