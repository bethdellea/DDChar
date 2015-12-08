//
//  Dwarf.cpp
//  D&D
//
//  Created by Nicole Lane on 12/6/15.
//  Copyright (c) 2015 Nicole Lane. All rights reserved.
//

#include <stdio.h>
#include "Dwarf.h"
#include <iostream>

Dwarf::Dwarf() {
    speed = 20;
    knownLanguages = new std::string[50];
    vision = new std::string[50];
    languageIdx = 0;
    visionIdx = 0;
    
    knownLanguages[0] = "Common";
    knownLanguages[1] = "Dwarven";
    languageIdx += 2;
    vision[0] = "Darkvision";
    visionIdx++;
}

//Create a deep copy of a Dwarf parameter
Dwarf::Dwarf(const Dwarf& dwarfToCopy){
    speed = dwarfToCopy.speed;
    languageIdx = dwarfToCopy.languageIdx;
    visionIdx = dwarfToCopy.visionIdx;
    
    std::string* knownLanguages = new std::string[50];
    std::string* vision = new std::string[50];
    
    //Set known languages in new array
    for (int i = 0; i < languageIdx; i++) {
        knownLanguages[i] = dwarfToCopy.knownLanguages[i];
    }
    //Set vision in new array
    for (int i = 0; i < visionIdx; i++) {
        vision[i] = dwarfToCopy.vision[i];
    }
}

//Get rid of all of the contained arrays
Dwarf::~Dwarf() {
    delete[] knownLanguages;
    knownLanguages = nullptr;
    delete[] vision;
    vision = nullptr;
    
}

void Dwarf::printSpeed() {
    std::cout << "Your current speed is: " << speed <<std::endl;
}

int Dwarf::changeSpeed(int amt) {
    speed += amt;
    return speed;
}

int Dwarf::getSpeed() {
    return speed;
}

void Dwarf::addLanguage(std::string newLanguage) {
    for (int i = 0; i < languageIdx; i++) {
        if (newLanguage == *(knownLanguages + i)) {
            std::cout << "You already know that language." << std::endl;
            return;
        }
    }
    
    knownLanguages[languageIdx] = newLanguage;
    languageIdx++;
}

void Dwarf::printLanguages() {
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

void Dwarf::addVision(std::string newVision) {
    for (int i = 0; i < visionIdx; i++) {
        if (newVision == *(vision + i)) {
            std::cout << "You already have that vision." <<std::endl;
            return;
        }
    }
    vision[visionIdx] = newVision;
    visionIdx++;

}

void Dwarf::printVision() {
    std::cout << "Your current types of vision include: ";
    if (visionIdx == 1) { //If you only have one, don't go into the loop
        std::cout << vision[0] << std::endl;
    }
    else {
        for (int i = 0; i < visionIdx; i++) { //If last in list, don't print a comma afterwards
            if (i == visionIdx - 1) {
                std::cout << "and " << vision[i] <<std::endl;
            }
            else {
                std::cout << vision [i]<< ", ";
            }
        }
    }

}

//Stat bonus
void Dwarf::changeAbilities() {
    //+2 Constitution, +2 Wisdom, –2 Charisma
}






