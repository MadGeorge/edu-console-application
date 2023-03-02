//
//  Person.hpp
//  D8.1
//
//  Created by George Romas on 02.03.23.
//

#ifndef Person_hpp
#define Person_hpp

#include <stdlib.h>
#include <string>

using namespace std;

enum Gender { Male, Female };

class Person {
private:
    string _name;
    int _age;
    Gender _gender;
    float _weight;

public:
    Person(Gender gender) {
        _gender = gender;
        _age = 1;
        _name = "";
        _weight = 1;
    }

    void setName(string value);
    string getName();
    void setAge(int value);
    void setWeight(float value);
};

#endif /* Person_hpp */
