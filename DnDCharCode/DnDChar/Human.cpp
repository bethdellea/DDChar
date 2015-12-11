//
//  Human.cpp
//  D&D
//
//  Created by Nicole Lane on 12/6/15.
//  Copyright (c) 2015 Nicole Lane. All rights reserved.
//

#include "stdafx.h"
#include <stdio.h>
#include "Human.h"
#include <iostream>
#include <typeinfo>
#include "Body.h"

//
//  Human.cpp
//  D&D
//
//  Created by Nicole Lane on 12/6/15.
//  Copyright (c) 2015 Nicole Lane. All rights reserved.
//

Human::Human() {
    speed = 30;
    knownLanguages = new std::string[50];
    vision = new std::string[50];
    languageIdx = 0;
    visionIdx = 0;
    
    knownLanguages[0] = "Common"; //Initialize arrays to contain race specific visions and languages
    languageIdx ++;
}

//Make a deep copy of human, although it likely will not be needed
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

//Add language to the array unless it is already known
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

//Append to a string in order to write to a file while saving
std::string Human::getLangString() {
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

//Append to a string in order to write to a file while saving
std::string Human::getVisionString() {
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

//Display all known languages
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

//Add vision to the array unless it already exists there
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

//Display all current visions
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


//Stat bonus. This method is different than the other 2 races, because human takes user input and adds +2 to any one ability in the array
void Human::changeAbilities(int* abilArr) {
    //Strength = 0, dexterity = 1, constitution = 2, intelligence = 3, wisdom = 4, charisma = 5
    //+2 to any chosen abilities

    std::cout << "Choose the number of the ability you'd like to increase by 2: " << std::endl;
    std::cout << "0) Strength" << std::endl;
    std::cout << "1) Dexterity" << std::endl;
    std::cout << "2) Constitution" << std::endl;
    std::cout << "3) Intelligence" << std::endl;
    std::cout << "4) Wisdom" << std::endl;
    std::cout << "5) Charisma" << std::endl;
    
    int abil = -1;
    bool goodInput = false;
    //This checks for the correct input, which is any number from 0 to 5, but does not include strings
    while (!goodInput) { //Run this loop until it gets a valid input
        std::cin >> abil;
        if (abil < 0 || abil > 5) {
            std::cout << "Please enter a valid number." << std::endl;
            goodInput = false;
        }
        if (abil == 0 || abil == 1 || abil == 2 || abil == 3 || abil == 4 || abil == 5) { //Could have done >=0 || <=5 but weird cin errors on windows happened
            std::cout << "Selection recorded!" << std::endl;
            goodInput = true;
        }
        
        if (!std::cin >> abil) { //If the user inputs anything that isn't an int, clear and ignore it and then run the loop again
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "I'm sorry, but the key you pressed was not a valid input. Please try again." << std::endl;
            goodInput = false;
        }
        
    }
    
    abilArr[abil] =  *(abilArr + abil) + 2; //Increase chosen ability in the array by 2
    
}

