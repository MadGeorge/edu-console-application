//
//  main.cpp
//  Console Application
//
//  Created by George Romas on 02.03.23.
//
//  https://github.com/MadGeorge/edu-console-application
//

#include <stdio.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string.h>
#include <string>
#include <exception>

using namespace std;

struct FileWasNotOpenedException : public exception {
   const char * what() const throw() {
      return "File was not opened Exception";
   }
};

string readFile(const std::string &file_path) {
    const std::ifstream input_stream(file_path, ios_base::binary);

    if (input_stream.fail()) {
        throw FileWasNotOpenedException();
    }

    stringstream buffer;
    buffer << input_stream.rdbuf();

    return buffer.str();
}

int main() {
    try {
        printf("%s", readFile("app.txt").c_str());
    } catch (FileWasNotOpenedException err) {
        printf("Error: %s\n", err.what());
    }

//    try {
//        printf("%s", readFile("./D8.2/T2/app.cpp").c_str());
//    } catch (FileWasNotOpenedException err) {
//        printf("Error: %s\n", err.what());
//    }

    return 0;
}
