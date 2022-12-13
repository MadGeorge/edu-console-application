//
//  App.cpp
//  D2.4
//
//  Created by George Romas on 02.12.22.
//

#include "App.hpp"

int App::Execute(int argc, vector<string> argv) {
    fflush(stdin);

    int day, month, year;

    printf("Input day month year (space separated integers): ");

    if (scanf("%d %d %d", &day, &month, &year) == 3) {
        isLeapYear(year)
            ? printf("%d is a leap year\n", year)
            : printf("%d is a regular (not a leap) year\n", year);

        printf("Year Chinese symbol is %s\n", chinesYearSymbol(year).c_str());
        printf("Date Chinese symbol is %s\n", chinesMonthSymbol(day, month).c_str());

        return 0;
    }

    printf("Unexpected input. Three space separated integers are expected.\n");
    return 1;
}

int App::daysInMonth(int month) {
    int days[12]{ 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

    return days[month - 1];
}

int App::daysInMonth(int month, int year) {
    if (month == 2 && isLeapYear(year)) return 29;

    return daysInMonth(month);
}

bool App::isLeapYear(int year) {
    return year % 4 == 0 && (year % 100 != 0 || year % 400 == 0);
}

string App::chinesYearSymbol(int year) {
    vector<string> symbols = {
        "Rat", "Ox", "Tiger", "Rabbit", "Dragon", "Snake",
        "Horse", "Goat", "Monkey", "Rooster", "Dog", "Pig",
    };

    int index = (year - 4) % symbols.size();

    if (index < 0 || index > symbols.size()) return "Ktulu";

    return symbols[(year - 4) % 12];
}

enum Month {
    January = 1, February, March, April, May, June,
    July, August, September, October, November, December
};

string App::chinesMonthSymbol(int day, int month) {
    switch (month) {
        case January:   return (day < 20) ? "Capricorn" : "Aquarius";
        case February:  return (day < 20) ? "Aquarius" : "Pisces";
        case March:     return (day < 20) ? "Pisces" : "Aries";
        case April:     return (day < 20) ? "Aries" : "Taurus";
        case May:       return (day < 20) ? "Taurus" : "Gemini";
        case June:      return (day < 20) ? "Gemini" : "Cancer";
        case July:      return (day < 20) ? "Cancer" : "Leo";
        case August:    return (day < 20) ? "Leo" : "Virgo";
        case September: return (day < 20) ? "Virgo" : "Libra";
        case October:   return (day < 20) ? "Libra" : "Scorpio";
        case November:  return (day < 20) ? "Scorpio" : "Sagittarius";
        case December:  return (day < 20) ? "Sagittarius" : "Capricorn";

        default: return "Batman";
    }
}
