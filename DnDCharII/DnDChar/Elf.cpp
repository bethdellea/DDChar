//
//  Elf.cpp
//  D&D
//
//  Created by Nicole Lane on 12/6/15.
//  Copyright (c) 2015 Nicole Lane. All rights reserved.
//
#include "stdafx.h"
#include <stdio.h>
#include "Elf.h"
#include <iostream>

Elf::Elf() {
    int speed = 30;
    std::string* knownLanguages = new std::string[50];
    std::string* vision = new std::string[50];
    int languageIdx = 0;
    int visionIdx = 0;
    
    knownLanguages[0] = "Common";
    knownLanguages[1] = "Elven";
    languageIdx += 2;
    vision[0] = "Low Light Vision";
    visionIdx++;
}

Elf::Elf(const Elf& elfToCopy){
    speed = elfToCopy.speed;
    languageIdx = elfToCopy.languageIdx;
    visionIdx = elfToCopy.visionIdx;
    
    std::string* knownLanguages = new std::string[50];
    std::string* vision = new std::string[50];
    
    //Set known languages in new array
    for (int i = 0; i < languageIdx; i++) {
        knownLanguages[i] = elfToCopy.knownLanguages[i];
    }
    //Set vision in new array
    for (int i = 0; i < visionIdx; i++) {
        vision[i] = elfToCopy.vision[i];
    }
}

//Get rid of all of the contained arrays
Elf::~Elf() {
    delete[] knownLanguages;
    knownLanguages = nullptr;
    delete[] vision;
    vision = nullptr;
    
}

int Elf::getSpeed() {
    return speed;
}

int Elf::changeSpeed(int amt) {
    speed += amt;
    return speed;
    
}

void Elf::addLanguage(std::string newLanguage) {
    knownLanguages[languageIdx] = newLanguage;
}

void Elf::printLanguages() {
    for (int i = 0; i < languageIdx; i++) {
        if (i == languageIdx - 1) { //If last in the list, don't print a comma afterwards
            std::cout << knownLanguages[i] <<std::endl;
        }
        else {
            std::cout << knownLanguages [i]<< ", " <<std::endl;
        }

    }
}

void Elf::addVision(std::string newVision) {
    vision[visionIdx] = newVision;
    visionIdx++;
}

void Elf::printVision() {
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
void Elf::changeAbilities() {
    //+2 Dexterity, +2 Intelligence, –2 Constitution:
}

