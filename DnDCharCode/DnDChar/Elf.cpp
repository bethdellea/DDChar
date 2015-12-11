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
    speed = 30;
    knownLanguages = new std::string[50];
    vision = new std::string[50];
    languageIdx = 0;
    visionIdx = 0;
    
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

void Elf::printSpeed() {
    std::cout << "Your current speed is: " << speed <<std::endl;
}

int Elf::getSpeed() {
    return speed;
}

int Elf::changeSpeed(int amt) {
    speed += amt;
    return speed;
    
}

void Elf::addLanguage(std::string newLanguage) {
    for (int i = 0; i < languageIdx; i++) {
        if (newLanguage == *(knownLanguages + i)) {
            std::cout << "You already know that language." << std::endl;
            return;
        }
    }
    
    knownLanguages[languageIdx] = newLanguage;
    languageIdx++;
}

void Elf::printLanguages() {

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

void Elf::addVision(std::string newVision) {
    for (int i = 0; i < visionIdx; i++) {
        if (newVision == *(vision + i)) {
            std::cout << "You already have that vision." <<std::endl;
            return;
        }
    }
    vision[visionIdx] = newVision;
    visionIdx++;
  
}


std::string Elf::getLangString() {
    std::string toWrite = "";
    toWrite += "You know the languages: ";
    
    if (languageIdx == 1) {
        
        toWrite += knownLanguages[0];
    }
    else {
        for (int i = 0; i < languageIdx; i++) { //If last in list, don't print a comma afterwards
            if (i == languageIdx - 1) {
                toWrite += "and " + knownLanguages[i];
            }
            else {
                toWrite += knownLanguages[i] + ", ";
            }
        }
    }
    toWrite += "\n";
    return toWrite;
}


void Elf::printVision() {
    std::cout << "Your current types of vision include: ";

    if (visionIdx == 1) {
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

std::string Elf::getVisionString() {
    std::string toWrite = "";
    toWrite += "Your current types of vision are: ";
    
    if (visionIdx == 1) {
        
        toWrite += vision[0];
    }
    else {
        for (int i = 0; i < 10; i++) { //If last in list, don't print a comma afterwards
            if (i == visionIdx - 1) {
                toWrite += "and " + vision[i];
            }
            else {
                toWrite += vision[i] + ", ";
            }
        }
    }
    toWrite += "\n";
    return toWrite;
}




//Stat bonus
void Elf::changeAbilities(int* abilArr) {
    abilArr[1] = *(abilArr + 1) + 2; //+2 Dexterity
    abilArr[3] = *(abilArr + 3) + 2; //+2 Intelligence
    abilArr[2] = *(abilArr + 2) - 2; //-2 Constitution
}

