//
//  Person.cpp
//  D8.1
//
//  Created by George Romas on 02.03.23.
//

#include "Person.hpp"

string Person::getName() { return _name; }

void Person::setName(string value) { _name = value; }
void Person::setAge(int value) { _age = value; }
void Person::setWeight(float value) { _weight = value; }
