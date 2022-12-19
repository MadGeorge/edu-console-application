//
//  main.cpp
//  Console Application
//
//  Created by George Romas on 19.12.22.
//
//  https://github.com/MadGeorge/edu-console-application
//

#include <stdio.h>

int main(int argc, const char * argv[]) {

    // выводит таблицу умножения на 5 от 1 до 10.
    for (int i = 1; i <= 10; i++) {
        printf("%02d x 5 = %02d\n", i, (i * 5));
    }

    return 0;
}
