//
//  RaceADT.h
//  D&D
//
//  Created by Nicole Lane on 11/16/15.
//  Copyright (c) 2015 Nicole Lane. All rights reserved.
//

#ifndef D_D_RaceADT_h
#define D_D_RaceADT_h

#include <iostream>
#include <stdio.h>
#include <string>

class RaceADT {
private:
    
public:
    std::string vision;
    std::string knownLanguages;
    int visionIdx;
    int languageIdx;
    
    //Returns speed of character
    virtual int getSpeed()=0;
    
    //Prints speed of character
    virtual void printSpeed()=0;
    
    //Increase speed stat
    virtual int changeSpeed (int amt)=0;
    
    //Add a new known language
    virtual void addLanguage(std::string newLanguage)=0;
    
    //Print a list of known languages
    virtual void printLanguages()=0;
    
    //Add a new vision
    virtual void addVision(std::string newVision)=0;

    
    //Print a list of vision
    virtual void printVision()=0;
    
    //Give a stat bonus
    virtual void changeAbilities(int* statArr)=0;
    
    //Call all destructors
    virtual ~RaceADT() {};
    
  

    

    
};

#endif
