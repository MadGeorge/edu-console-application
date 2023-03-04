//
//  main.cpp
//  Console Application
//
//  Created by George Romas on 04.03.23.
//
//  https://github.com/MadGeorge/edu-console-application
//

#include <stdio.h>
#include <cmath>
#include <string>
#include <string.h>

using namespace std;

// T1 -------------------

class Figure {
public:
    virtual float area();
};

class Parallelogram: Figure {
public:
    float base, height;

    Parallelogram(float base, float height) {
        this->base = base;
        this->height = height;
    }

    float area() {
        return base * height;
    }
};

class Circle: Figure {
public:
    float radius;

    Circle(float radius) {
        this->radius = radius;
    }

    float area() {
        return M_PI * radius * radius;
    }
};

class Rectangle: Parallelogram {
public:
    float width, height;

    Rectangle(float width, float height): Parallelogram(width, height) {
        this->width = width;
        this->height = height;
    }

    float area() {
        return width * height;
    }
};

class Square: Parallelogram {
public:
    float side;

    Square(float side): Parallelogram(side, side) {
        this->side = side;
    }

    float area() {
        return side * side;
    }
};

class Rhombus: Parallelogram {
public:
    float side, dA, dB;

    Rhombus(float side, float dA, float dB): Parallelogram(side, side) {
        this->side = side;
        this->dA = dA;
        this->dB = dB;
    }

    float area() {
        return (dA * dB) / 2;
    }
};

// T2 -------------------

class Car {
public:
    string manufacturer;
    string model;

    Car(string manufacturer, string model) {
        this->manufacturer = manufacturer;
        this->model = model;

        info();
    }

    void info() {
        printf("%s: %s, %s", typeid(this).name(), this->manufacturer.c_str(), this->model.c_str());
    }
};

class PassengerCar: virtual Car {
public:
    using Car::Car;
};

class Bus: virtual Car {
public:
    using Car::Car;
};

class Minivan: Bus, PassengerCar {
public:
    Minivan(string manufacturer, string model):
    PassengerCar(manufacturer, model), Bus(manufacturer, model), Car(manufacturer, model) {
    }
};

// T3 -------------------

class Fraction {
public:
    int numerator, denominator;

    Fraction(int numerator = 0, int denominator = 1) {
        if (denominator == 0) throw "denominator can not be zero";

        this->numerator = numerator;
        this->denominator = denominator;
    }

    Fraction operator + (Fraction const &other) {
        Fraction res;
        res.numerator = (numerator * other.denominator + denominator * other.numerator);
        res.denominator = (denominator * other.denominator);
        return res;
    }

    Fraction operator - (Fraction const &other) {
        Fraction res;
        res.numerator = (numerator * other.denominator - denominator * other.numerator);
        res.denominator = (denominator * other.denominator);
        return res;
    }

    Fraction operator * (Fraction const &other) {
        Fraction res;
        res.numerator = (numerator * other.numerator);
        res.denominator = (denominator * other.denominator);
        return res;
    }

    Fraction operator / (Fraction const &other) {
        Fraction res;
        res.numerator = (numerator * other.denominator);
        res.denominator = (denominator * other.numerator);
        return res;
    }

    Fraction operator - () {
        return Fraction(numerator * -1, denominator * -1);
    }

    friend bool operator== (const Fraction &lhs, const Fraction &rhs);
    friend bool operator!= (const Fraction &lhs, const Fraction &rhs);
    friend bool operator> (const Fraction &lhs, const Fraction &rhs);
    friend bool operator>= (const Fraction &lhs, const Fraction &rhs);
    friend bool operator< (const Fraction &lhs, const Fraction &rhs);
    friend bool operator<= (const Fraction &lhs, const Fraction &rhs);

    void out() {
        printf("%d\n", numerator);
        printf("-\n");
        printf("%d\n\n", denominator);
    }

    float value() const {
        return (float)numerator / (float)denominator;
    }
};

bool operator== (const Fraction &lhs, const Fraction &rhs) {
    return lhs.value() == rhs.value();
}

bool operator!= (Fraction &lhs, Fraction &rhs) {
    return !(lhs == rhs);
}

bool operator> (Fraction &lhs, Fraction &rhs) {
    return lhs.value() > rhs.value();
}

bool operator>= (Fraction &lhs, Fraction &rhs) {
    return lhs.value() >= rhs.value();
}

bool operator< (Fraction &lhs, Fraction &rhs) {
    return !(lhs >= rhs);
}

bool operator<= (Fraction &lhs, Fraction &rhs) {
    return !(lhs > rhs);
}

// -----------------------

int main() {
    (Fraction(3, 5) + Fraction(2, 3)).out();
    (Fraction(2, 3) - Fraction(3, 5)).out();
    (Fraction(4, 7) * Fraction(2, 6)).out();
    (Fraction(2, 3) / Fraction(4, 7)).out();

    (-Fraction(1, 2)).out();

    Fraction f_a(1, 2); Fraction f_b(1, 2);
    printf("1/2 == 1/2 : %d\n", f_a == f_b);

    Fraction f_c(2, 3); Fraction f_d(1, 3);
    printf("2/3 > 1/3 : %d\n", f_c > f_d);

    Fraction f_e(1, 3); Fraction f_f(2, 3);
    printf("1/3 < 2/3 : %d\n", f_e < f_f);

    return 0;
}
