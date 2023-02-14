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

    printf("Initial: %s\n", str);

    int indexToDelete;
    auto totalCharacters = strlen(str);

    printf("Input index to remove. min 0 max %lu: ", totalCharacters - 1);

    if (scanf("%d", &indexToDelete) != 1) {
        printf("Invalid input. Please, provide single number.\n");
        return 1;
    }

    if (indexToDelete >= totalCharacters) {
        printf("Index out of range. Max index should be < %lu\n", totalCharacters);
        return 1;
    }

    for (auto i = indexToDelete; i < totalCharacters; i++)
        str[i] = str[i + 1];

    printf("After remove char at %d: %s\n", indexToDelete, str);

    return 0;
}
