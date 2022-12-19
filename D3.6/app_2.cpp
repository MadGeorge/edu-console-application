//
//  main.cpp
//  Console Application
//
//  Created by George Romas on 19.12.22.
//
//  https://github.com/MadGeorge/edu-console-application
//

#include <stdio.h>
#include <string>

using namespace std;

string compare(int a, int b) {
    return (a < b)
        ? ("is less than " + to_string(b))
        : (
           a > b
            ? ("is greater than " + to_string(b))
            : ("is equal " + to_string(b))
        );
}

string divide(int a, int b) {
    return (a % b == 0)
        ? ("is divided by " + to_string(b))
        : ("is not divided by " + to_string(b));
}

int main(int argc, const char * argv[]) {
    int exitPoint = 7;
    int i = 0;

    while (i != exitPoint) {
        printf("enter an integer: ");
        scanf("%d", &i);

        if (i == exitPoint) return 0;

        printf("%d %s\n", i, compare(i, 7).c_str());
        printf("%d %s\n", i, compare(i, 10).c_str());
        printf("%d %s\n", i, divide(i, 2).c_str());
        printf("%d %s\n", i, divide(i, 3).c_str());
    }

    return 0;
}
