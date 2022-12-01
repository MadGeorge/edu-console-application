//
//  main.cpp
//  Console Application
//
//  Created by George Romas on 28.11.22.
//
//  https://github.com/MadGeorge/edu-console-application
//

#include <stdio.h>
#include <stdlib.h>
#include <cmath>
#include <string>
#include <vector>
#include <filesystem>

using namespace std;

// MARK: - Types

enum Mode { read, write };

class Credentials {
public:
    long long a;
    long long b;
    Credentials(long long a, long long b) {
        this->a = a;
        this->b = b;
    }
};

// MARK: - Helpers

FILE* openDBFile(Mode mode) {
    string tmpPath = std::__fs::filesystem::temp_directory_path();
    string dbPath = (tmpPath + "/nums_db");

    switch (mode) {
        case read:
            return fopen(dbPath.c_str(), "r");

        case write:
            return fopen(dbPath.c_str(), "w+");
    }
}

string makePair(Credentials* creds) {
    string strA = to_string(creds->a);
    string strB = to_string(creds->b);
    return strA + "_" + strB + "\n";
}

vector<string> readDB() {
    FILE* fp = openDBFile(read);
    if (fp == NULL) return vector<string>();

    vector<string> result;

    char* line = NULL;
    size_t length = 0;
    ssize_t read;

    while ((read = getline(&line, &length, fp)) != -1) {
        result.push_back(string(line));
    }

    fclose(fp);

    return result;
}

int writeToDB(vector<string> pairs) {
    FILE* fp = openDBFile(write);
    if (fp == NULL) return 1;

    for (int i = 0; i < pairs.size(); i++) {
        fputs(pairs[i].c_str(), fp);
    }

    fclose(fp);

    return 0;
}

// MARK: - Task 1

int login() {
    fflush(stdin);

    int a,b;

    printf("Guess combination of two integer numbers separated by space.\n");
    printf("Tip: valid combination is 42 and 36\n");
    printf("--------------------------------------------\n");
    printf("You input is: ");

    if (scanf("%d %d", &a, &b) != 2) {
        printf("Invalid input. Please, try again.\n");
        return 1;
    }

    if (a == 42 && b == 36) {
        printf("Your guess is CORRECT!\n");
        return 0;
    }

    printf("Your guess is NOT correct!\n");
    return 1;
}

// MARK: - Task 2

Credentials* getCredentials() {
    fflush(stdin);

    long long a,b;

    printf("Input two integer numbers separated by the space: ");

    if (scanf("%lld %lld", &a, &b) != 2) {
        return NULL;
    }

    return new Credentials(a, b);
}

int signIn() {
    vector<string> pairs = readDB();

    if (pairs.size() == 0) {
        printf("No credentials where stored in DB. Use 'signup' first.\n");
        return 1;
    }

    Credentials* creds = getCredentials();

    if (creds == NULL) {
        printf("Invalid input. Please, try again.\n");
        return 1;
    }

    for (int i = 0; i < pairs.size(); i++) {
        string pair = pairs[i];
        string credsPair = makePair(creds);

        if (credsPair.compare(pair) == 0) {
            printf("Credentials are matched. Sign In successful.\n");
            return 0;
        }
    }

    printf("Credentials are INVALID\n");
    return 0;
}

int signUp() {
    vector<string> pairs = readDB();
    Credentials* creds = getCredentials();

    if (creds == NULL) {
        printf("Invalid input. Please, try again.\n");
        return 1;
    }

    printf("Saving %lld and %lld...\n", creds->a, creds->b);

    pairs.push_back(makePair(creds));

    if (writeToDB(pairs) != 0) {
        printf("Failed to save DB.");
        return 1;
    }

    printf("Pair is registered. You can now use 'signin' option with this pair of integers.\n");

    return 0;
}

// MARK: - Entry point

void printHelp() {
    printf("command argument is required\n");
    printf("options:\n");
    printf("- login: guess pair of integers. Task 1.\n");
    printf("- signup: register login pair. Part of Task 2.\n");
    printf("- signin: check pair of integers if they where registered with 'signup'. Part of Task 2.\n");
}

int main(int argc, const char* argv[]) {
    if (argc != 2) {
        printHelp();
        return 1;
    }

    const char* arg = argv[1];

    if (strcmp(arg, "login") == 0) {
        return login();
    }

    if (strcmp(arg, "signin") == 0) {
        return signIn();
    }

    if (strcmp(arg, "signup") == 0) {
        return signUp();
    }

    printHelp();
    return 1;
}
