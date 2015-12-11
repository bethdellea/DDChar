//
//  Character.cpp
//  D&DFinal
//
//  Created by Nicole Lane on 12/10/15.
//  Copyright (c) 2015 Nicole Lane. All rights reserved.
//

#include "stdafx.h"
#include <iostream>
#include "ItemWeapon.h"
#include "ItemArmor.h"
#include "Inventory.h"
#include "Fighter.h"
#include <string>
#include "RaceADT.h"
#include "Elf.h"
#include "Dwarf.h"
#include "Human.h"
#include "Character.h"

using namespace std;


Character::Character() {
    Body* body = new Body();
    
    RaceADT* race;
    ClassADT* classType;
    Inventory* inventory;
    int HP;
    
    //Selection of race
    cout << "Hello! You are here to make a Dungeons and Dragons character. Luckily, I am here to help!" << endl;
    cout << "First, you must select your race. Choose a number from the list below." <<endl;
    cout << "1) Dwarf" << endl;
    cout << "2) Elf" << endl;
    cout << "3) Human" << endl;
    
    int choice = -1;
    bool goodInput = false;
    //This checks for the correct input, which is any number from 1 to 3, but does not include strings
    while (!goodInput) {
        cin >> choice;
        if (!cin >> choice) {
            cin.clear();
            cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
            cout << "I'm sorry, but the key you pressed was not a valid input. Please try again." << endl;
            goodInput = false;
        }

        else if (choice < 1 || choice > 3) {
            cout << "Please enter a valid number." << endl;
            goodInput = false;
        }
        
        if (choice == 1 || choice == 2 || choice == 3) {
            cout << "Selection recorded!" << endl;
            goodInput = true;
        }
        
    }
    
    
    //Change the abilities array in body according to selected race
    if (choice == 1) {
        cout << "Chose race type 'Dwarf." << endl;
        race = new Dwarf();
        race->changeAbilities(body->abilities);
    }
    else if (choice == 2) {
        cout << "Chose race type 'Elf." << endl;
        race = new Elf();
        race->changeAbilities(body->abilities);
    }
    
    else if (choice == 3) {
        cout << "Chose race type 'Human." << endl;
        race = new Human();
        race->changeAbilities(body->abilities);
    }
    
    
    
    //Decide which class (right now, we only have Fighter, but we can add more conditions
    cout << "And now to choose your class. Choose a number from the list below." << endl;
    cout << "1) Fighter" << endl;
    
    int classChoice = -1;
    bool goodInputClass = false;
    
    //This checks for the correct input, which right now is only number 1, but does not include strings
    while (!goodInputClass) {
        cin >> classChoice;
        if (classChoice > 1 || classChoice < 1) {
            cout << "Please enter a valid number." << endl;
            goodInputClass = false;
        }
        if (classChoice == 1) {
            cout << "Selection recorded!" << endl;
            goodInputClass = true;
        }
        
        if (!cin >> classChoice) {
            cin.clear();
            cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
            cout << "I'm sorry, but the key you pressed was not a valid input. Please try again." << endl;
            goodInputClass = false;
        }
    }
    
    //Create class based on user input, and determine HP based off of body modifier
    if (classChoice == 1) {
        cout << "Chose class type 'Fighter'." << endl;
        classType = new Fighter();
        cout << "Rolling a die to determine your HP." << endl;
        
        HP = classType->rollHP(body->getModifier(2)); //Send body's constitution modifier to the rollHP method
        cout << "Your total HP is: " << HP << endl;
    }
    
    
    //Create new, empty inventory
    cout << "Creating your empty inventory now." << endl;
    inventory = new Inventory();
    
}

Character::~Character() {
    //Calls all 4 destructors for each object
    delete[] body;
    delete[] race;
    delete[] classType;
    delete[] inventory;
}

