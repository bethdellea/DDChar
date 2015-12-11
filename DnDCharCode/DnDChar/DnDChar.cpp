// DnDChar.cpp : Defines the entry point for the console application.
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
#include <ctime>

using namespace std;

int main()
{
	srand(time(NULL)); //Seed random for all methods to use
    Character* myCharacter = new Character();
	
	return 0;
}

