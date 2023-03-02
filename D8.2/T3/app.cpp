//
//  main.cpp
//  Console Application
//
//  Created by George Romas on 02.03.23.
//
//  https://github.com/MadGeorge/edu-console-application
//

#include <iostream>
#include <stdio.h>
#include <string>
#include <string.h>
#include <algorithm>
#include <stdexcept>
#include <cmath>

using namespace std;

enum Operator { Add, Sub, Mul, Div, Pow };

class Operation {
private:
    Operator _operator;

public:
    Operation(Operator op) {
        _operator = op;
    }

    float execute(float left, float right);
};

float Operation::execute(float left, float right) {
    switch (_operator) {
        case Add:
            return left + right;

        case Sub:
            return left - right;

        case Mul:
            return left * right;

        case Div:
            if (right == 0) throw runtime_error("Division by zero is not allowed");
            return left / right;

        case Pow:
            return pow(left, right);
    }
}

int main(int argc, char* argv[]) {
    printf("input operation. ex: 1+2, 1-2, 1/2.\n");
    printf("supported operators +, -, /, ^.\n");
    printf("your input: ");

    string str;
    getline(cin, str);
    fflush(stdin);

    replace(str.begin(), str.end(), ',', '.');

    auto opAddCount = count(str.begin(), str.end(), '+');
    auto opSubtractCount = count(str.begin(), str.end(), '-');
    auto opDivideCount = count(str.begin(), str.end(), '/');
    auto opMultiplyCount = count(str.begin(), str.end(), '*');
    auto opPowCount = count(str.begin(), str.end(), '^');

    auto operatorsCount = opAddCount + opSubtractCount + opDivideCount + opMultiplyCount + opPowCount;

    if (operatorsCount <= 0)
        throw runtime_error("Valid operator is required");

    if (operatorsCount > 1)
        throw runtime_error("Only one operator is supported");

    char sep;
    Operation op(Add);
    if (opAddCount == 1) { sep = '+'; op = Operation(Add); }
    if (opSubtractCount == 1) { sep = '-'; op = Operation(Sub); }
    if (opDivideCount == 1) { sep = '/'; op = Operation(Div); }
    if (opMultiplyCount == 1) { sep = '*'; op = Operation(Mul); }
    if (opPowCount == 1) { sep = '^'; op = Operation(Pow); }

    float operandLeft = 0;
    float operandRight = 0;

    char* dup = strdup(str.c_str());
    char* pch = strtok(dup, &sep);
    auto column = 0;
    while (pch != NULL) {
        if (column > 2) throw runtime_error("invalid input expression");

        try {
            if (column == 0) operandLeft = stof(pch);
            if (column == 1) operandRight = stof(pch);
        } catch (invalid_argument err) {
            throw runtime_error(string("Parse float error. Cannot convert ") + pch + " to a number");
        }

        column++;
        pch = strtok(NULL, " ");
    }

    free(dup);
    free(pch);

    printf("Result: %f\n", op.execute(operandLeft, operandRight));

    return 0;
}
