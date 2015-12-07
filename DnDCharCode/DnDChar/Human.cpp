//
//  Human.cpp
//  D&D
//
//  Created by Nicole Lane on 12/6/15.
//  Copyright (c) 2015 Nicole Lane. All rights reserved.
//

#include <stdio.h>
#include "Human.h"
#include <iostream>

//
//  Human.cpp
//  D&D
//
//  Created by Nicole Lane on 12/6/15.
//  Copyright (c) 2015 Nicole Lane. All rights reserved.
//

#include <stdio.h>
#include "Human.h"
#include <iostream>

Human::Human() {
    int speed = 30;
    std::string* knownLanguages = new std::string[50];
    std::string* vision = new std::string[50];
    int languageIdx = 0;
    int visionIdx = 0;
    
    knownLanguages[0] = "Common";
    languageIdx ++;
}

Human::Human(const Human& humanToCopy){
    speed = humanToCopy.speed;
    languageIdx = humanToCopy.languageIdx;
    visionIdx = humanToCopy.visionIdx;
    
    std::string* knownLanguages = new std::string[50];
    std::string* vision = new std::string[50];
    
    //Set known languages in new array
    for (int i = 0; i < languageIdx; i++) {
        knownLanguages[i] = humanToCopy.knownLanguages[i];
    }
    //Set vision in new array
    for (int i = 0; i < visionIdx; i++) {
        vision[i] = humanToCopy.vision[i];
    }
}

//Get rid of all of the contained arrays
Human::~Human() {
    delete[] knownLanguages;
    knownLanguages = nullptr;
    delete[] vision;
    vision = nullptr;
    
}


int Human::getSpeed() {
    return speed;
}

int Human::changeSpeed(int amt) {
    speed += amt;
    return speed;
    
}

void Human::addLanguage(std::string newLanguage) {
    knownLanguages[languageIdx] = newLanguage;
    languageIdx++;
}

void Human::printLanguages() {
    for (int i = 0; i < languageIdx; i++) {
        if (i == languageIdx - 1) { //If last in the list, don't print a comma afterwards
            std::cout << knownLanguages[i] <<std::endl;
        }
        else {
            std::cout << knownLanguages [i]<< ", " <<std::endl;
        }
    }
}

void Human::addVision(std::string newVision) {
    vision[visionIdx] = newVision;
    visionIdx++;
}


void Human::printVision() {
    for (int i = 0; i < visionIdx; i++) {
        if (i == visionIdx - 1) { //If last in the list, don't print a comma afterwards
            std::cout << vision[i] <<std::endl;
        }
        else {
            std::cout << vision [i]<< ", " <<std::endl;
        }
    }
}


//Stat bonus
void Human::changeAbilities() {
    //+2 Dexterity, +2 Intelligence, –2 Constitution:
}

