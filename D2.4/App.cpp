//
//  App.cpp
//  D2.4
//
//  Created by George Romas on 02.12.22.
//

#include <stdlib.h>
#include <stdio.h>
#include <string>

using namespace std;

#include "App.hpp"

int App::Execute(int argc, vector<string> argv) {
    if (argc != 2) {
        return errorWithHelpHelp();
    }

    string arg = argv[1];

    if (arg.compare("--help") == 0) {
        return errorWithHelpHelp(0);
    }

    try {
        int d = stoi(arg);

        switch (d) {
            case 0: return inputError(zero);

            case 1: return aDay("Monday");
            case 2: return aDay("Tuesday");
            case 3: return aDay("Wednesday");
            case 4: return aDay("Thursday");
            case 5: return aDay("Friday");
            case 6: return aDay("Saturday");
            case 7: return aDay("Sunday");

            default: return inputError(outOfRange);
        }
    } catch(invalid_argument ex) {
        return inputError(input);
    } catch(out_of_range ex) {
        return inputError(overflow);
    }

    return errorWithHelpHelp();
}

// MARK: - private

int App::aDay(const char* name) {
    printf("%s\n", name);
    return 0;
}

int App::errorWithHelpHelp(int code) {
    if (code != 0) {
        printf("command argument is required\n");
    } else {
        printf("prints a day name for an integer number.\n");
    }

    printf("the number from 1 to 7 is valid argument.\n");

    return code;
}

int App::inputError(ErrorKind kind) {
    switch (kind) {
        case input:
            printf("Unexpected input. Can not parse integer from provided string.\n");
            break;

        case overflow:
            printf("Unexpected input. integer overflow.\n");
            break;

        case outOfRange:
            printf("Unexpected input. The only valid range is 1...7 inclusive\n");
            break;

        case zero:
            printf("Are you a programmer?\n");
            break;
    }

    return 1;
}
