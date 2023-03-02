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

using namespace std;

// MARK: - LeveledEntity

class LeveledEntity {
protected:
    int _accessLevel;

public:
    LeveledEntity(int level) {
        _accessLevel = level;
    }
};

// MARK: - AccessCard

class AccessCard: public LeveledEntity {
public:
    using LeveledEntity::LeveledEntity;

    int accessLevel();
};

int AccessCard::accessLevel() { return _accessLevel; }

// MARK: - Passage

class Passage: LeveledEntity {
public:
    using LeveledEntity::LeveledEntity;

    bool canPass(AccessCard card);
};

bool Passage::canPass(AccessCard card) {
    return card.accessLevel() >= _accessLevel;
}

// MARK: - AccessController

enum Product { Food, Book, Inventory };

class AccessController {
public:
    bool canPass(AccessCard card, Passage passage);
    int discount(AccessCard card, Product product);
};

bool AccessController::canPass(AccessCard card, Passage passage) {
    return passage.canPass(card);
}

int AccessController::discount(AccessCard card, Product product) {
    switch (product) {
        case Food:
            return card.accessLevel() > 1 ? 20 : 0;

        case Book:
            return card.accessLevel() >= 1 ? 20 : 0;

        case Inventory:
            if (card.accessLevel() > 3) return 40;
            if (card.accessLevel() > 2) return 30;
            if (card.accessLevel() > 1) return 20;
            return 0;
    }
}

string boolToText(bool flag) { return flag ? "allowed" : "restricted"; }

// ----------------------------------------------------
int main() {
    AccessCard studentCard(0);
    AccessCard professorCard(1);
    AccessCard directorCard(2);

    AccessController controller;

    Passage generalAuditory(0);
    Passage teachersAuditory(1);
    Passage administrationAuditory(2);

    printf("Access of student to auditory general: %s\n", boolToText(controller.canPass(studentCard, generalAuditory)).c_str());
    printf("Access of student to auditory teachers: %s\n", boolToText(controller.canPass(studentCard, teachersAuditory)).c_str());
    printf("Access of student to auditory administration: %s\n", boolToText(controller.canPass(studentCard, administrationAuditory)).c_str());

    printf("Access of professor to auditory general: %s\n", boolToText(controller.canPass(professorCard, generalAuditory)).c_str());
    printf("Access of professor to auditory teachers: %s\n", boolToText(controller.canPass(professorCard, teachersAuditory)).c_str());
    printf("Access of professor to auditory administration: %s\n", boolToText(controller.canPass(professorCard, administrationAuditory)).c_str());

    printf("Access of director to auditory general: %s\n", boolToText(controller.canPass(directorCard, generalAuditory)).c_str());
    printf("Access of director to auditory teachers: %s\n", boolToText(controller.canPass(directorCard, teachersAuditory)).c_str());
    printf("Access of director to auditory administration: %s\n", boolToText(controller.canPass(directorCard, administrationAuditory)).c_str());

    return 0;
}
