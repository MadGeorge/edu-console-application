//
//  main.cpp
//  Console Application
//
//  Created by George Romas on 03.03.23.
//
//  https://github.com/MadGeorge/edu-console-application
//

#include <stdio.h>
#include <cmath>

using namespace std;

struct Vector2 {
    float x;
    float y;

    Vector2(float x, float y) {
        this->x = x;
        this->y = y;
    }
};

class Function {
public:
    virtual float f(float x) = 0;
};

class Ellipse: public Function {
public:
    float width, height;

    Ellipse(float width, float height) {
        this->width = width;
        this->height = height;
    }

    float f(float x) {
        // (x^2)/3 + (y^2)/5 = 1
        // (x^2)/w + (y^2)/h = 1
        // y^2 / h = 1 - x^2/w
        // y^2 = h - h(x^2/w)
        // y = sqr(h - h(x^2/w))
        return sqrt(height - (height * ((x * x) / width)));
    }
};

class Hyperbola: public Function {
public:
    float factor;

    Hyperbola(float factor) {
        this->factor = factor;
    }

    float f(float x) {
        return factor / x;
    }
};

class Parabola: public Function {
public:
    float f(float x) {
        return x * x;
    }
};

void out(Function* fn, float x) {
    printf("%f\n", fn->f(x));
}

int main() {
    Function* fn;

    Ellipse el(5, 3);
    Hyperbola hy(1);
    Parabola pa;

    out(&el, 2);
    out(&hy, 2);
    out(&pa, 2);

    return 0;
}
