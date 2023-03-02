//
//  Student.hpp
//  D8.1
//
//  Created by George Romas on 02.03.23.
//

#ifndef Student_hpp
#define Student_hpp

#include <stdio.h>
#include "Person.hpp"

class Student: public Person {
private:
    int _educationYear = 1;

public:
    using Person::Person;

    int getEducationYear();
    void setEducationYear(int value);
};

#endif /* Student_hpp */
