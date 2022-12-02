//
//  main.cpp
//  Console Application
//
//  Created by George Romas on 28.11.22.
//
//  https://github.com/MadGeorge/edu-console-application
//

#include <string>
#include "App.hpp"

int main(int argc, char* argv[]) {
    return (new App())->Execute(argc, vector<string>(argv, argv + argc));
}
