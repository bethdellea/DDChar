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
    knownLanguages = new std::string[50]; //In case new languages or visions are "invented"
    vision = new std::string[50];
    languageIdx = 0;
    visionIdx = 0;
    
    knownLanguages[0] = "Common"; //Initialize all languages and visions specific to the race
    knownLanguages[1] = "Elven";
    languageIdx += 2;
    vision[0] = "Low Light Vision";
    visionIdx++;
}

//Very rarely will there be a case where a copy constructor is needed for Race, but good to have just in case
Elf::Elf(const Elf& elfToCopy){
    speed = elfToCopy.speed;
    languageIdx = elfToCopy.languageIdx;
    visionIdx = elfToCopy.visionIdx;
    
    std::string* knownLanguages = new std::string[50];
    std::string* vision = new std::string[50];
    
    //Set known languages in new array
    for (int i = 0; i < languageIdx; i++) { //Copy all information in the existing arrays to the new ones
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

//Add to the language array when you learn a new language (unless you already know it)
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

//Cycle through array and print
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

//Like addLanguages but for vision
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


//Append to a string so it can be written to a file when saving
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


//Display all known visions
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

//Append to a string so it can be written to a file when saving

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




//Stat bonus, based on race; takes the ability array made in body as a parameter and changes the values accordingly
void Elf::changeAbilities(int* abilArr) {
    abilArr[1] = *(abilArr + 1) + 2; //+2 Dexterity
    abilArr[3] = *(abilArr + 3) + 2; //+2 Intelligence
    abilArr[2] = *(abilArr + 2) - 2; //-2 Constitution
}

