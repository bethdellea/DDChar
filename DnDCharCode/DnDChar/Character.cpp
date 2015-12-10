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
    //Body* body = new Body();
    Body* body = new Body();
    
    RaceADT* race;
    ClassADT* classType;
    Inventory* inventory;
    int HP;
    
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
        if (choice < 1 || choice > 3) {
            cout << "Please enter a valid number." << endl;
            goodInput = false;
        }
        if (choice == 1 || choice == 2 || choice == 3) {
            cout << "Selection recorded!" << endl;
            goodInput = true;
        }
        
        if (!cin >> choice) {
            cin.clear();
            cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
            cout << "I'm sorry, but the key you pressed was not a valid input. Please try again." << endl;
            goodInput = false;
        }
    }
    
    //I can't access the abilities array in body???
    if (choice == 1) {
        race = new Dwarf();
        race->changeAbilities(body->abilities);
    }
    else if (choice == 2) {
        race = new Elf();
        race->changeAbilities(body->abilities);
    }
    
    else if (choice == 3) {
        race = new Human();
        race->changeAbilities(body->abilities);
    }
    
    

    
    
    
    
    
   }