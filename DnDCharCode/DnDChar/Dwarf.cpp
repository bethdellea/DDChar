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
    int speed = 20;
    std::string* knownLanguages = new std::string[50];
    std::string* vision = new std::string[50];
    int languageIdx = 0;
    int visionIdx = 0;
    
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

int Dwarf::changeSpeed(int amt) {
    speed += amt;
    return speed;
}

void Dwarf::addLanguage(std::string newLanguage) {
    knownLanguages[languageIdx] = newLanguage;
    languageIdx++;
}

void Dwarf::printLanguages() {
    for (int i = 0; i < languageIdx; i++) {
        if (i == languageIdx - 1) { //If last in the list, don't print a comma afterwards
            std::cout << knownLanguages[i] <<std::endl;
        }
        else {
            std::cout << knownLanguages [i]<< ", " <<std::endl;
        }
    }
}

void Dwarf::addVision(std::string newVision) {
    vision[visionIdx] = newVision;
    visionIdx++;
}

void Dwarf::printVision() {
    for (int i = 0; i < visionIdx; i++) { //If last in list, don't print a comma afterwards
        if (i == visionIdx - 1) {
            std::cout << vision[i] <<std::endl;
        }
        else {
           std::cout << vision [i]<< ", " <<std::endl;
        }
    }
}

//Stat bonus
void Dwarf::changeAbilities() {
    //+2 Constitution, +2 Wisdom, –2 Charisma
}






