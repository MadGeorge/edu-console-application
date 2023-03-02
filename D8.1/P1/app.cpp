//
//  main.cpp
//  Console Application
//
//  Created by George Romas on 02.03.23.
//
//  https://github.com/MadGeorge/edu-console-application
//

#include <stdio.h>
#include <string>
#include "Person.hpp"
#include "Student.hpp"

using namespace std;

int main() {
    Person person(Male);
    person.setWeight(45);
    person.setAge(12);
    person.setName("Max");

    printf("Person's name is: %s\n", person.getName().c_str());

    Student student(Female);
    student.setWeight(55);
    student.setAge(17);
    student.setName("Emma");
    student.setEducationYear(2);

    printf("Student's name is: %s and education year is %d\n", student.getName().c_str(), student.getEducationYear());

    return 0;
}
