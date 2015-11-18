//
//  RaceADT.h
//  D&D
//
//  Created by Nicole Lane on 11/16/15.
//  Copyright (c) 2015 Nicole Lane. All rights reserved.
//

#ifndef D_D_RaceADT_h
#define D_D_RaceADT_h

Class RaceADT {
public:
    //returns the total number of bytes of memory this object is using
    virtual int calcMemUsage()=0;
    
    //returns the total amount of time used by this object (number of lines of code executed)
    virtual int getElapsedTime()=0;
    
    //Ensure that the child destructors are called
    virtual ~RaceADT();
    
    //Returns speed of character
    virtual int getSpeed()=0;
    
    //Increase speed stat
    virtual int changeSpeed (int amt)=0;
    
    //Add a new known language
    virtual void addLanguage(std::string newLanguage)=0;
    
    //Print a list of known languages
    virtual void printLanguages()=0;
    
    //Give a stat bonus
    virtual void changeAbilities()=0;
    
    //Add weapon proficiencies
    virtual void weaponProficiencies()=0;
    
    //Print a list of weapon proficiences
    virtual void printProficiencies()=0;

    
private:
    
};

#endif
