//
//  main.cpp
//  Console Application
//
//  Created by George Romas on 16.12.22.
//
//  https://github.com/MadGeorge/edu-console-application
//

#include <stdio.h>
#include <string>

using namespace std;

int main(int argc, const char * argv[]) {

    int sum = 0;
    string history = "";

    for (int i = 5; i <= 15; i++) {
        history += to_string(i);
        if (i != 15) history += " + ";

        sum += i;
    }

    printf("sum from 5 to 15 inclusive is %d\n", sum);
    printf("history: %s\n", history.c_str());

    return 0;
}
