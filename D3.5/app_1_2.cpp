//
//  main.cpp
//  Console Application
//
//  Created by George Romas on 16.12.22.
//
//  https://github.com/MadGeorge/edu-console-application
//

#include <stdio.h>

int main(int argc, const char * argv[]) {

    for (int i = 0; i < 15; i++) {
        printf("%d\n", i);
    }

    printf("-------------------\n");

    for (int i = 0; i < 14; i += 2) {
        printf("%d\n", (i + 1));
    }

    return 0;
}
