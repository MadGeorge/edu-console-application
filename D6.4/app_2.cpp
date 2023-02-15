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
#include <string>

using namespace std;

int main(int argc, const char * argv[]) {
    char origin[256] = "abcdefghijk";
    char flipped[strlen(origin) + 1];

    auto total = strlen(origin);

    for (auto i = 0; i < total; i++)
        flipped[i] = origin[total - 1 - i];

    printf("Origin: %s\n", origin);
    printf("Flipped: %s\n", flipped);

    return 0;
}
