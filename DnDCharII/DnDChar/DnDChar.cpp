// DnDChar.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "ItemWeapon.h"
#include "ItemArmor.h"
#include "Inventory.h"
#include "Fighter.h"
#include <string>

using namespace std;

void testInventory() {
	Inventory* demo = nullptr;
	cout << "For this demo, you will be making an item for your character's inventory." << endl;
	cout << "D&D Characters carry a number of items, but for sanity's sake let's just use armor or weapons! Which would you like?" << endl;
	cout << "(Hit 'W' for a weapon and 'A' for armor): ";

	//Checks user input to make sure it's an 'a' or 'w'
	string itemType = "";
	bool goodInput = false;
	while (!goodInput) {
		cin >> itemType;
		if (itemType == "w" || itemType == "W" || itemType == "a" || itemType == "A")
		{
			goodInput = true;
		}
		else
		{
			cout << "I'm sorry, but the key you pressed was not a valid input. Please try again." << endl;
		}
	}

	//If they choose weapon:
	if (itemType == "w" || itemType == "W")
	{
		//Prompts user for number of items
		cout << endl;
		cout << "You chose a weapon! Good choice; it's always good to smite your foes!" << endl;
		cout << "Please tell us how many of this item you're adding: ";
		int numItem = 0;

		//Checks user input to make sure it's an integer
		while (!(cin >> numItem) || numItem == 0) {
			//Some code I found online. Basically catches when cin cannot turn the input into an integer
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "I'm sorry, but the key you pressed was not a valid input. Please try again." << endl;
		}
		cin.ignore(numeric_limits<streamsize>::max(), '\n');

		//Prompts user for item name
		cout << endl << "Excellent! Now we need to know what the name of your armor is." << endl;
		cout << "In a real game of D&D, you would select your items from a list." << endl;
		cout << "After all, if you could just make whatever you wanted, it wouldn't be a fair game!" << endl;
		cout << "For this version though, we'll give you a bit more freedom." << endl << "Please enter the name of your armor; be as heroic as possible!" << endl;
		cout << "Item name: ";
		string itemName = "";
		cin >> itemName;
		cin.ignore(numeric_limits<streamsize>::max(), '\n');

		//Assigns worth and type
		cout << endl;
		cout << "In a game of D&D, all items have a value in gold." << endl;
		cout << "How much it's worth depends on the item; after all, you don't get to decide what your fortune's worth!" << endl;
		cout << "Because you undoubtedly entered a heroic name, your item will be worth a whole 500 gold pieces!" << endl;
		cout << "And though weapons come in all shapes and sizes, everybody knows that the best kind are swords." << endl;
		cout << "So with the number and name of your items decided, we're ready to add to your inventory!" << endl;
		int worth = 500;
		string type = "Sword";

		//Captures key press to add to Inventory
		cout << "Press 'A' to add your item to the inventory.";
		string command = "";
		goodInput = false;
		while (!goodInput) {
			cin >> command;
			if (command == "a" || command == "A")
			{
				goodInput = true;
			}
			else
			{
				cout << "Hey, that's the wrong key! Have you been paying attention?";
			}

		}

		//Creates and adds to Inventory, then prints.
		demo = new Inventory();
		Item* item = new ItemWeapon(itemName, worth, numItem, type);
		demo->addItem(item);
		cout << demo->listItems();
	}


	//If they choose armor:
	else
	{
		//Prompts user for number of items
		cout << endl;
		cout << "You chose armor! Good choice; it's always good to be safe!" << endl;
		cout << "Please tell us how many of this item you're adding: ";
		int numItem = 0;

		//Checks user input to make sure it's an integer
		while (!(cin >> numItem) || numItem == 0) {
			//Some code I found online. Basically catches when cin cannot turn the input into an integer
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "I'm sorry, but the key you pressed was not a valid input. Please try again." << endl;
		}
		cin.ignore(numeric_limits<streamsize>::max(), '\n');



		//Prompts user for item name
		cout << endl << "Excellent! Now we need to know what the name of your armor is." << endl;
		cout << "In a real game of D&D, you would select your items from a list." << endl;
		cout << "After all, if you could just make whatever you wanted, it wouldn't be a fair game!" << endl;
		cout << "For this version though, we'll give you a bit more freedom." << endl << "Please enter the name of your armor; be as heroic as possible!" << endl;
		cout << "Item name: ";
		string itemName = "";
		cin >> itemName;
		cin.ignore(numeric_limits<streamsize>::max(), '\n');


		//Assigns worth and type
		cout << endl;
		cout << "In a game of D&D, all items have a value in gold." << endl;
		cout << "How much it's worth depends on the item; after all, you don't get to decide what your fortune's worth!" << endl;
		cout << "Because you undoubtedly entered a heroic name, your item will be worth a whole 500 gold pieces!" << endl;
		cout << "So with the number and name of your items decided, we're ready to add to your inventory!" << endl;
		int worth = 500;

		//Captures key press to add to Inventory
		cout << "Press 'A' to add your item to the inventory.";
		string command = "";
		goodInput = false;
		while (!goodInput) {
			cin >> command;
			if (command == "a" || command == "A")
			{
				goodInput = true;
			}
			else
			{
				cout << "Hey, that's the wrong key! Have you been paying attention?";
			}
		}

		//Creates and adds to Inventory, then prints.
		demo = new Inventory();
		Item* item = new ItemArmor(itemName, worth, numItem);
		demo->addItem(item);

	}

	demo->addGold(250);
	Item* item1 = new ItemArmor("2343", 333, 1);
	Item* item2 = new ItemArmor("asn", 23435, 44);
	Item* item3 = new ItemArmor("pls work", 325, 12);
	demo->addItem(item1);
	cout << demo->listItems() << std::endl;
	demo->addItem(item2);
	cout << demo->listItems() << std::endl;
	demo->addItem(item3);
	cout << demo->listItems() << std::endl;

	cout << "Your current gold balanace is: " << demo->getGold() << endl;

	demo->sellItem("asn");

	std::cout << "\nYou have sold asn. Your gold balance is now: " << demo->getGold() << endl;

	std::cout << "This is your updated inventory: " << std::endl;
	std::cout << demo->listItems() << std::endl;

	std::cout << "Removing item 'pls work'.... \n" << demo->removeItem("pls work") << "Your updated inventory: " << std::endl;
	std::cout << demo->listItems();
}


int main(){
	/*
	Fighter* aragorn = new Fighter();
	aragorn->printProfs();
	aragorn->addProf("Exotic");
	aragorn->printProfs();

	*/
	/*
	//Opening welcome
	cout << "Welcome to the D&D Character Maker demo!" << endl;
	*/
	testInventory();

    return 0;
}

