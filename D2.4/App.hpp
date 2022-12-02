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

enum ErrorKind { input, overflow, outOfRange, zero };

class App {
public:
    int Execute(int argc, vector<string> argv);

private:
    int aDay(const char* name);
    int errorWithHelpHelp(int code = 1);
    int inputError(ErrorKind kind);
};

#endif /* App_hpp */
