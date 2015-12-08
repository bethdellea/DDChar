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
    speed = 30;
    knownLanguages = new std::string[50];
    vision = new std::string[50];
    languageIdx = 0;
    visionIdx = 0;
    
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

void Human::printSpeed() {
    std::cout << "Your current speed is: " << speed <<std::endl;
}

int Human::getSpeed() {
    return speed;
}

int Human::changeSpeed(int amt) {
    speed += amt;
    return speed;
    
}

void Human::addLanguage(std::string newLanguage) {
    for (int i = 0; i < languageIdx; i++) {
        if (newLanguage == *(knownLanguages + i)) {
            std::cout << "You already know that language." << std::endl;
            return;
        }
    }
    
    knownLanguages[languageIdx] = newLanguage;
    languageIdx++;

}

void Human::printLanguages() {
    std::cout << "You know the languages: ";
    if (languageIdx == 1) {
        std::cout << knownLanguages[0] << std::endl;
    }
    else {
        for (int i = 0; i < languageIdx; i++) {
            
            if (i == languageIdx - 1) { //If last in the list, don't print a comma afterwards
                std::cout <<"and " << knownLanguages[i] <<std::endl;
            }
            else {
                std::cout << knownLanguages [i]<< ", ";
            }
            
        }
        
    }
}

void Human::addVision(std::string newVision) {
    for (int i = 0; i < visionIdx; i++) {
        if (newVision == *(vision + i)) {
            std::cout << "You already have that vision." <<std::endl;
            return;
        }
    }
    vision[visionIdx] = newVision;
    visionIdx++;

}


void Human::printVision() {
    std::cout << "Your current types of vision include: ";
    if (visionIdx == 1) {
        std::cout << vision[0] << std::endl;
    }
    else {
        for (int i = 0; i < visionIdx; i++) { //If last in list, don't print a comma afterwards
            if (i == visionIdx - 1) {
                std::cout << "and " << vision[i]<<std::endl;;
            }
            else {
                std::cout << vision [i]<< ", ";
            }
        }
    }
}


//Stat bonus
void Human::changeAbilities() {
    //+2 to any chosen abilities
}

