//
//  App.hpp
//  D2.4
//
//  Created by George Romas on 02.12.22.
//

#ifndef App_hpp
#define App_hpp

#include <stdlib.h>
#include <string>
#include <vector>

using namespace std;

enum ErrorKind { input, zero };

class App {
public:
    int Execute(int argc, vector<string> argv);
    int daysInMonth(int month);
    int daysInMonth(int month, int year);
    bool isLeapYear(int year);
    string chinesYearSymbol(int year);
    string chinesMonthSymbol(int day, int month);
};

#endif /* App_hpp */
