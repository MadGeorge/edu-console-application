//
//  main.cpp
//  Console Application
//
//  Created by George Romas on 14.02.23.
//
//  https://github.com/MadGeorge/edu-console-application
//

#include <stdio.h>
#include <string.h>
#include <string>

using namespace std;

int main(int argc, const char * argv[]) {
    char str[256] = "Hello";

    printf("Input: %s\n", str);
    printf("Last character is: %c\n", str[strlen(str) - 1]);

    swap(str[0], str[2]);

    printf("Swap 0 and 2: %s\n", str);

    return 0;
}
