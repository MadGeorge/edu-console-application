//
//  main.cpp
//  Console Application
//
//  Created by George Romas on 28.11.22.
//
//  https://github.com/MadGeorge/edu-console-application
//

#include <stdlib.h>
#include <assert.h>
#include "App.hpp"

void tests() {
    assert(31 == App().daysInMonth(1));
    assert(28 == App().daysInMonth(2));
    assert(31 == App().daysInMonth(3));
    assert(30 == App().daysInMonth(4));
    assert(31 == App().daysInMonth(5));
    assert(30 == App().daysInMonth(6));
    assert(31 == App().daysInMonth(7));
    assert(31 == App().daysInMonth(8));
    assert(30 == App().daysInMonth(9));
    assert(31 == App().daysInMonth(10));
    assert(30 == App().daysInMonth(11));
    assert(31 == App().daysInMonth(12));

    assert(!App().isLeapYear(1));
    assert(!App().isLeapYear(2));
    assert(!App().isLeapYear(3));
    assert(App().isLeapYear(4));
    assert(!App().isLeapYear(5));
    assert(!App().isLeapYear(6));
    assert(!App().isLeapYear(7));
    assert(App().isLeapYear(8));
    assert(!App().isLeapYear(9));
    assert(!App().isLeapYear(10));
    assert(!App().isLeapYear(11));
    assert(App().isLeapYear(12));
    assert(!App().isLeapYear(1900));
    assert(!App().isLeapYear(1901));
    assert(!App().isLeapYear(1902));
    assert(!App().isLeapYear(1903));
    assert(App().isLeapYear(1904));
    assert(App().isLeapYear(2000));
    assert(!App().isLeapYear(2001));
    assert(!App().isLeapYear(2002));
    assert(!App().isLeapYear(2003));
    assert(App().isLeapYear(2004));
    assert(App().isLeapYear(2020));
    assert(App().isLeapYear(2024));


    assert(31 == App().daysInMonth(1, 1999));
    assert(28 == App().daysInMonth(2, 1999));
    assert(31 == App().daysInMonth(7, 1999));
    assert(31 == App().daysInMonth(8, 1999));
    assert(29 == App().daysInMonth(2, 2000));
    assert(29 == App().daysInMonth(2, 2024));
    assert(29 == App().daysInMonth(2, 2040));

    assert(App().chinesYearSymbol(1948).compare("Rat") == 0);
    assert(App().chinesYearSymbol(1956).compare("Monkey") == 0);
    assert(App().chinesYearSymbol(1959).compare("Pig") == 0);
    assert(App().chinesYearSymbol(1960).compare("Rat") == 0);
    assert(App().chinesYearSymbol(1986).compare("Tiger") == 0);
    assert(App().chinesYearSymbol(2023).compare("Rabbit") == 0);

    assert(App().chinesMonthSymbol(1, 5).compare("Taurus") == 0);
    assert(App().chinesMonthSymbol(28, 5).compare("Gemini") == 0);
    assert(App().chinesMonthSymbol(27, 12).compare("Capricorn") == 0);
    assert(App().chinesMonthSymbol(10, 2).compare("Aquarius") == 0);

    printf("all tests passed\n");
}

int main(int argc, char* argv[]) {
    if (argc == 2 && strcmp(argv[1], "--tests") == 0) {
        tests();
        return 0;
    }

    return (new App())->Execute(argc, vector<string>(argv, argv + argc));
}
