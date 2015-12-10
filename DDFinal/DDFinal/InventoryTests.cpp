//#include "stdafx.h"
#include <iostream>
#include "Inventory.h"


void testInventory() {
	Inventory* demo = nullptr;
	std::cout << "For this demo, you will be making an item for your character's inventory." << std::endl;
	std::cout << "D&D Characters carry a number of items, but for sanity's sake let's just use armor or weapons! Which would you like?" << std::endl;
	std::cout << "(Hit 'W' for a weapon and 'A' for armor): ";

	//Checks user input to make sure it's an 'a' or 'w'
	std::string itemType = "";
	bool goodInput = false;
	while (!goodInput) {
		std::cin >> itemType;
		if (itemType == "w" || itemType == "W" || itemType == "a" || itemType == "A")
		{
			goodInput = true;
		}
		else
		{
			std::cout << "I'm sorry, but the key you pressed was not a valid input. Please try again." << std::endl;
		}
	}

	//If they choose weapon:
	if (itemType == "w" || itemType == "W")
	{
		//Prompts user for number of items
		std::cout << std::endl;
		std::cout << "You chose a weapon! Good choice; it's always good to smite your foes!" << std::endl;
		std::cout << "Please tell us how many of this item you're adding: ";
		int numItem = 0;

		//Checks user input to make sure it's an integer
		while (!(std::cin >> numItem) || numItem == 0) {
			//Some code I found online. Basically catches when cin cannot turn the input into an integer
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "I'm sorry, but the key you pressed was not a valid input. Please try again." << std::endl;
		}
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

		//Prompts user for item name
		std::cout << std::endl << "Excellent! Now we need to know what the name of your armor is." << std::endl;
		std::cout << "In a real game of D&D, you would select your items from a list." << std::endl;
		std::cout << "After all, if you could just make whatever you wanted, it wouldn't be a fair game!" << std::endl;
		std::cout << "For this version though, we'll give you a bit more freedom." << std::endl << "Please enter the name of your armor; be as heroic as possible!" << std::endl;
		std::cout << "Item name: ";
		std::string itemName = "";
		std::cin >> itemName;
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

		//Assigns worth and type
		std::cout << std::endl;
		std::cout << "In a game of D&D, all items have a value in gold." << std::endl;
		std::cout << "How much it's worth depends on the item; after all, you don't get to decide what your fortune's worth!" << std::endl;
		std::cout << "Because you undoubtedly entered a heroic name, your item will be worth a whole 500 gold pieces!" << std::endl;
		std::cout << "And though weapons come in all shapes and sizes, everybody knows that the best kind are swords." << std::endl;
		std::cout << "So with the number and name of your items decided, we're ready to add to your inventory!" << std::endl;
		int worth = 500;
		std::string type = "Sword";

		//Captures key press to add to Inventory
		std::cout << "Press 'A' to add your item to the inventory.";
		std::string command = "";
		goodInput = false;
		while (!goodInput) {
			std::cin >> command;
			if (command == "a" || command == "A")
			{
				goodInput = true;
			}
			else
			{
				std::cout << "Hey, that's the wrong key! Have you been paying attention?";
			}

		}

		//Creates and adds to Inventory, then prints.
		demo = new Inventory();
		Item* item = new ItemWeapon(itemName, worth, numItem, type);
		demo->addItem(item);
		std::cout << demo->listItems();
	}


	//If they choose armor:
	else
	{
		//Prompts user for number of items
		std::cout << std::endl;
		std::cout << "You chose armor! Good choice; it's always good to be safe!" << std::endl;
		std::cout << "Please tell us how many of this item you're adding: ";
		int numItem = 0;

		//Checks user input to make sure it's an integer
		while (!(std::cin >> numItem) || numItem == 0) {
			//Some code I found online. Basically catches when cin cannot turn the input into an integer
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "I'm sorry, but the key you pressed was not a valid input. Please try again." << std::endl;
		}
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');



		//Prompts user for item name
		std::cout << std::endl << "Excellent! Now we need to know what the name of your armor is." << std::endl;
		std::cout << "In a real game of D&D, you would select your items from a list." << std::endl;
		std::cout << "After all, if you could just make whatever you wanted, it wouldn't be a fair game!" << std::endl;
		std::cout << "For this version though, we'll give you a bit more freedom." << std::endl << "Please enter the name of your armor; be as heroic as possible!" << std::endl;
		std::cout << "Item name: ";
		std::string itemName = "";
		std::cin >> itemName;
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');


		//Assigns worth and type
		std::cout << std::endl;
		std::cout << "In a game of D&D, all items have a value in gold." << std::endl;
		std::cout << "How much it's worth depends on the item; after all, you don't get to decide what your fortune's worth!" << std::endl;
		std::cout << "Because you undoubtedly entered a heroic name, your item will be worth a whole 500 gold pieces!" << std::endl;
		std::cout << "So with the number and name of your items decided, we're ready to add to your inventory!" << std::endl;
		int worth = 500;

		//Captures key press to add to Inventory
		std::cout << "Press 'A' to add your item to the inventory.";
		std::string command = "";
		goodInput = false;
		while (!goodInput) {
			std::cin >> command;
			if (command == "a" || command == "A")
			{
				goodInput = true;
			}
			else
			{
				std::cout << "Hey, that's the wrong key! Have you been paying attention?";
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
	std::cout << demo->listItems() << std::endl;
	demo->addItem(item2);
	std::cout << demo->listItems() << std::endl;
	demo->addItem(item3);
	std::cout << demo->listItems() << std::endl;

	std::cout << "Your current gold balanace is: " << demo->getGold() << std::endl;
	/*
	demo->sellItem("asn");

	std::cout << "\nYou have sold asn. Your gold balance is now: " << demo->getGold() << std::endl;

	std::cout << "This is your updated inventory: " << std::endl;
	std::cout << demo->listItems() << std::endl;

	std::cout << "Removing item 'pls work'.... \n" << demo->removeItem("pls work") << "Your updated inventory: " << std::endl;
	std::cout << demo->listItems();

	std::cout << "Writing demo inventory to a file. Please check that it appears as expected...\n";
	demo->toFile();
	*/
	std::cout << "\nNow we'll test the copy constructor...\n";
	Inventory* demo2 = new Inventory(demo);

	std::cout << "Contents of Inventory 1: \n" << demo->listItems();
	std::cout << "\nContents of Inventory II: \n" << demo2->listItems();

}