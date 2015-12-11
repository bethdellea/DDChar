//
//  Human.h
//  D&D
//
//  Created by Nicole Lane on 11/16/15.
//  Copyright (c) 2015 Nicole Lane. All rights reserved.
//

#ifndef D_D_Human_h
#define D_D_Human_h

#include "RaceADT.h"
#include <string>
#include <iostream>
#include <stdio.h>
#include "Body.h"

class Human : public RaceADT {
private:

    
    
public:
    
    std::string* knownLanguages;
    std::string* vision;
    int languageIdx; //Keeps track of which index in the array to add to next
    int visionIdx;
    

    int speed;
    /* Creates a new Human; sets initial base speed, known languages and adds natural weapon proficiencies*/
    Human();
    //Create a deep copy of a Human parameter
    Human(const Human& humanToCopy);
    //Destructor
    ~Human();
    //Print speed of character
    void printSpeed();
    //Get speed of character
    int getSpeed();
    //Increase speed of character
    int changeSpeed (int amt);
    //Add a new known language
    void addLanguage(std::string newLanguage);
    //Prints a list of known languages
    void printLanguages();
    //Add a new vision
    void addVision(std::string newVision);
    //Append vision and language arrays to a string in order to write to a file
    std::string getLangString();
    std::string getVisionString();
    //Prints a list of visions
    void printVision();
    //Stat bonus; takes the ability array from body, asks the user for their choice, and adds 2 to their selection in the array
    void changeAbilities(int* abilArr);

    
    
};


#endif
