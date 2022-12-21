//
//  main.cpp
//  Console Application
//
//  Created by George Romas on 21.12.22.
//
//  https://github.com/MadGeorge/edu-console-application
//

#include <stdio.h>
#include <string>

using namespace std;

int main(int argc, const char * argv[]) {
    int sum = 0;
    int lineBreakCounter = -1;
    string history = "";
    
    for (int i = 1; i <= 100; i++) {
        lineBreakCounter++;
        sum += i;
        history += to_string(i);
        if (i < 100) history += " + ";
        if (lineBreakCounter == 15) {
            history += "\n";
            lineBreakCounter = -1;
        }
    }

    printf("%s = %d\n", history.c_str(), sum);

    return 0;
}
