//		Inventory.cpp
//	Author: Beth Dellea
//  Date created: 11/18/2015


#include "stdafx.h"
#include "Inventory.h"
#include <stdio.h>
#include <iostream>
#include <sstream>
#include <fstream>
#include <string>

Inventory::Inventory() {
	numGold = 0;
	firstItem = nullptr;
	lastItem = nullptr;

}


Inventory::Inventory(const Inventory* inventoryIn) {
	numGold = inventoryIn->numGold;
	Item* curr = inventoryIn->firstItem;
	firstItem = curr->copySelf();
	Item* prevItem = firstItem;
	curr = curr->getNext();
	while (curr != nullptr) {
		Item* newItem = curr->copySelf();		//workaround for the fact that copy constructors can't be virtual
		prevItem->setNext(newItem);
		prevItem = newItem;
		lastItem = prevItem;
		curr = curr->getNext();
	}
}

Inventory::Inventory(std::string fName) {
	//this takes more code than expected, tbh

	std::ifstream infile(fName);
	if (infile) {
		firstItem = nullptr;
		std::string goldBal;
		getline(infile, goldBal);
		numGold = atoi(goldBal.c_str());
		while (infile) {  //work through the whole file
			std::string line;
			getline(infile, line);
			if (line != "") {
				std::stringstream linestream(line);
				//only try and add actual data, please!
				//an array of the characteristics of the items being loaded in
				std::string* charsArray = new std::string[9];
				int curr = 0;
				while (linestream) {
					std::string itemData;
					getline(linestream, itemData, '\t');
					charsArray[curr] = itemData;
					curr++;
				}

				if (charsArray[1] == "a") {
					//then the item is armor. sweet.
					std::string itemName = charsArray[2];
					int itemWorth = atoi(charsArray[3].c_str());
					int sellP = atoi(charsArray[4].c_str()); //calculated by ItemArmor right now, but here because some day that might change
					int itemQuant = atoi(charsArray[5].c_str());		//and then we'd need to input it
					Item* itemIn = new ItemArmor(itemName, itemWorth, itemQuant);
					addItem(itemIn);
				}
				else if (charsArray[1] == "w") {
					//then the item is a weapon. kewl.
					std::string itemName = charsArray[2];
					int itemWorth = atoi(charsArray[3].c_str()); //casts these strings back into ints so they're useable
					int sellP = atoi(charsArray[4].c_str());
					int itemQuant = atoi(charsArray[5].c_str());
					std::string itemType = charsArray[6];
					Item* itemIn = new ItemWeapon(itemName, itemWorth, itemQuant, itemType);
					addItem(itemIn);
				}

			}
		}
	}
	else {
		std::cerr << "File not found." << std::endl;
	}

}


void Inventory::addItem(Item* itemToAdd) {
	if (firstItem == nullptr) {
		firstItem = itemToAdd;
	}
	else {
		if (!isInInventory(itemToAdd->getName())) {
			if (lastItem == nullptr) {
				lastItem = itemToAdd;
				firstItem->setNext(itemToAdd);
			}
			else {
				lastItem->setNext(itemToAdd);
				lastItem = itemToAdd;
			}
		}
		else {
			int itemIndx = getIndex(itemToAdd->getName());
			Item* curr = firstItem;
			Item* temp = nullptr;
			for (int i = 0; i < itemIndx; i++) {
				temp = curr;		//same algorithm as selling as far as traversing and removing the thing
				curr = curr->getNext();		//if that one was wrong, so is this.
			}
			curr->changeQuantity(itemToAdd->getQuantity());
		}
	}
}


void Inventory::sellItem(std::string itemName) {
	int itemIndx = getIndex(itemName);
	//loop through items for that index value
	Item* curr = firstItem;
	Item* temp = nullptr; //holds the pointer to the previous Item object
	for (int i = 0; i < itemIndx; i++) {
		temp = curr;
		curr = curr->getNext();
	}
	std::cout << "You have " << curr->getQuantity() << " of this item." << std::endl;
	std::cout << "How many of " << itemName << " would you like to sell?";
	int quant = 0;
	//Checks user input to make sure it's an integer
	while (!(std::cin >> quant) || quant == 0 || quant > curr->getQuantity()) {
		//Some code I found online. Basically catches when cin cannot turn the input into an integer
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout << "I'm sorry, but the key you pressed was not a valid input or tried to sell too mmany items. Please try again." << std::endl;
	}
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

	if (curr->getQuantity() > quant) {
		curr->changeQuantity(quant * -1);
		addGold(curr->getSellPrice()*quant);
	}
	else if (curr->getQuantity() == quant) {
		//assuming that loop got us where we want to be... requires testing
		temp->setNext(curr->getNext());
		addGold(curr->getSellPrice()*quant); //no haggling here, unfortunately
		delete(curr);
	}

}




Item* Inventory::removeItem(std::string itemName) {
	int itemIndex = getIndex(itemName);
	Item* curr = firstItem;
	Item* temp = nullptr;
	for (int i = 0; i < itemIndex; i++) {
		temp = curr;		//same algorithm as selling as far as traversing and removing the thing
		curr = curr->getNext();
	}
	std::cout << "You have " << curr->getQuantity() << " of this item." << std::endl;
	std::cout << "How many of " << itemName << "would you like to remove?";
	int quant = 0;
	//Checks user input to make sure it's an integer
	while (!(std::cin >> quant) || quant == 0 || quant > curr->getQuantity()) {
		//Some code I found online. Basically catches when cin cannot turn the input into an integer
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout << "I'm sorry, but the key you pressed was not a valid input or was greater than the quantity you have. Please try again." << std::endl;
	}
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

	Item* returnable = curr->removeSelf(quant); //makes a copy for returning purposes
	if (quant == curr->getQuantity()) { //if we remove all of the thing, it needs to be removed from the inventory entirely
		temp->setNext(curr->getNext());
		delete (curr);
	}
	return returnable; //user should delete this, yo!
}




std::string Inventory::listItems() {
	//work through the linked list pls
	std::string ownedItems = "";
	Item* curr = firstItem;
	while (curr != nullptr) {
		ownedItems += curr->getName() + "\t Quantity: " + std::to_string(curr->getQuantity()) + "\tValue: " + std::to_string(curr->getWorth()) + "\n";
		curr = curr->getNext();
	}

	return ownedItems;
}

//returns the amount of gold the character possesses
int Inventory::getGold() {
	return numGold;
}

//adds gold to the total!
void Inventory::addGold(int deposit) {
	numGold += deposit;
}

//removes gold!
void Inventory::removeGold(int withdrawal) {
	if (numGold >= withdrawal) {
		numGold -= withdrawal;
	}
	//controlling for overdraft will happen in the inventory interface
	std::cout << "There was an error in removing your gold. Please double check your numbers and try again." << std::endl;
}


/*
//returns a copy of the item we're looking for
Item* Inventory::getItem(std::string itemName) {
int itemIndx = getIndex(itemName);
Item* curr = firstItem;
Item* temp = nullptr;
for (int i = 0; i < itemIndx; i++) {
temp = curr;		//same algorithm as selling as far as traversing and removing the thing
curr = curr->getNext();		//if that one was wrong, so is this.
}
return curr;
}

*/

//returns the index position of the item by its name
int Inventory::getIndex(std::string itemName) {
	Item* curr = firstItem;
	int indx = 0;
	//traverse the list until the name matches
	while (curr->getName() != itemName && curr->getNext() != nullptr) {
		curr = curr->getNext();
		indx++;
	}
	return indx;
}

bool Inventory::isInInventory(std::string itemName) {
	Item* curr = firstItem;

	while (curr != nullptr) {
		if (curr->getName() == itemName) {
			return true;
		}
		curr = curr->getNext();
	}
	return false;

}

void Inventory::toFile() {
	Item* curr = firstItem;
	std::string toWrite = "";
	toWrite += std::to_string(getGold()) + "\n";
	while (curr != nullptr) {
		toWrite += "\t" + curr->stringMe() + "\n";
		curr = curr->getNext();
	}
	//then do something with the compiled strings
	//you know, that writing to a file shit
	std::cout << "Please enter the desired name for your inventory file: ";
	std::string filename;
	while (!(std::cin >> filename) || filename == "") {
		//Some code I found online. Basically catches when cin cannot turn the input into an integer
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout << "I'm sorry, but the key you pressed was not a valid input or was greater than the quantity you have. Please try again." << std::endl;
	}
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	filename += ".txt";
	std::ofstream outf(filename);
	if (outf) {
		std::string out;
		outf << toWrite; //add the string gained in the other fcn to the file!
		outf.close();
	}
	else {
		std::cerr << "Can't write to file" << std::endl;
	}
}


//deletes this beautiful linked list of Items
Inventory::~Inventory() {
	Item* curr = firstItem;
	Item* next = nullptr;
	while (curr != nullptr) {
		next = curr->getNext();
		delete curr;
		curr = next;
	}
	delete next;
	delete curr;
	//p sure these nullptrs are unnecessary, but better safe than sorry!
	curr = nullptr;
	firstItem = nullptr;
	lastItem = nullptr;
}


void Inventory::interact() {
	bool hasQuit = false;
	std::cout << "Welcome to your inventory. Here you can view and manage your inventory and gold." << std::endl;
	while (!hasQuit) {
		std::cout << std::endl;
		std::cout << "From any menu, you may press 'Q' to quit." << std::endl;
		std::cout << "For wealth management, enter 'G'. For item management, enter 'I': ";

		std::string moneyorstuff = "";
		bool goodInput = false;
		while (!goodInput) {
			std::cin >> moneyorstuff;
			if (moneyorstuff == "g" || moneyorstuff == "G" || moneyorstuff == "i" || moneyorstuff == "I" || moneyorstuff == "q" || moneyorstuff == "Q")
			{
				goodInput = true;
			}
			else
			{
				std::cout << "I'm sorry, but the key you pressed was not a valid input. Please try again." << std::endl;
			}
		}

		// ---------------------------------------------------------------------------------------------------
		//		START OF GOLD-RELATED FUNCTIONS

		if (moneyorstuff == "g" || moneyorstuff == "G") {
			std::cout << "\nLet's talk money.\nYour current gold balance is: " << getGold() << std::endl;

			std::cout << std::endl << "Enter 'D' to deposit gold, 'W' to withdraw gold: ";
			std::string addorremove = "";
			bool goodInput = false;
			while (!goodInput) {
				std::cin >> addorremove;
				if (addorremove == "d" || addorremove == "D" || addorremove == "w" || addorremove == "W" || addorremove == "q" || addorremove == "Q")
				{
					goodInput = true;
				}
				else
				{
					std::cout << "I'm sorry, but the key you pressed was not a valid input. Please try again." << std::endl;
				}
			}

			if (addorremove == "q" || addorremove == "Q") {
				hasQuit = true;
				std::cout << "Quitting... Thank you for your time..." << std::endl;
			}
			else if (addorremove == "d" || addorremove == "D") {
				std::cout << "How much gold will you be depositing today? ";
				std::cout << "\n(Enter 0 if you do not wish to deposit.)";
				int deposit = -1;
				while (!(std::cin >> deposit) || deposit < 0) {
					//Some code I found online. Basically catches when cin cannot turn the input into an integer
					std::cin.clear();
					std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					std::cout << "I'm sorry, but the key you pressed was not a valid input. Please try again." << std::endl;
				}
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

				addGold(deposit);
				std::cout << "\nYour deposit has been processed. Thank you. Your balance is now " << getGold() << std::endl;
			}
			else if (addorremove == "w" || addorremove == "W") {
				std::cout << "How much gold will you be withdrawing today? ";
				std::cout << "\n(Enter 0 if you did not want to withdraw)";
				int withdraw = -1;
				while (!(std::cin >> withdraw) || withdraw < 0 || withdraw > getGold()) {
					//Some code I found online. Basically catches when cin cannot turn the input into an integer
					std::cin.clear();
					std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					std::cout << "I'm sorry, but the key you pressed was not a valid input. Please try again." << std::endl;
				}
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

				removeGold(withdraw);
				std::cout << "\nYour deposit has been processed. Thank you. Your balance is now " << getGold() << std::endl;
			}
		}

		// ----------------------------------------------------------------------------------------------------------
		//			END OF GOLD-RELATED FUNCTIONS

		//-----------------------------------------------------------------------------------------------------------
		//			START OF ITEM-RELATED FUNCTIONS

		else if (moneyorstuff == "i" || moneyorstuff == "I") {
			std::cout << "Okay, let's look at what you've got!" << std::endl;
			//DO: itemthings
			if (firstItem == nullptr) {
				std::cout << "You currently have no items in your inventory." << std::endl;
				std::cout << "Perhaps you should add an item or two to your inventory. Enter 'A' to add an item: ";
				std::string addOrQ = "";
				bool goodInput = false;
				while (!goodInput) {
					std::cin >> addOrQ;
					if (addOrQ == "a" || addOrQ == "A" || addOrQ == "q" || addOrQ == "Q")
					{
						goodInput = true;
					}
					else
					{
						std::cout << "I'm sorry, but the key you pressed was not a valid input. Please try again." << std::endl;
					}
				}
				if (addOrQ == "Q" || addOrQ == "q") {
					hasQuit = true;
					std::cout << "Quitting... Thank you for your time..." << std::endl;
				}
				else {
					std::cout << "Wondeful. Let's add your first item!" << std::endl;
					addItem();
					std::cout << "Your new item has been added! This is what your inventory looks like now: \n" << listItems() << std::endl;
				}
			}
			else {
				std::cout << "The following items are in your inventory: " << listItems() << std::endl;

				std::cout << std::endl << std::endl;
				std::cout << "Now that you've seen your inventory, what would you like to do? " << std::endl;
				std::cout << "\tEnter 'R' to remove an item, 'S' to sell an item, or 'A' to add an item: ";

				std::string remSellAdd = "";
				bool goodInput = false;
				while (!goodInput) {
					std::cin >> remSellAdd;
					if (remSellAdd == "r" || remSellAdd == "R" || remSellAdd == "s" || remSellAdd == "S" || remSellAdd == "a" || remSellAdd == "A" || remSellAdd == "q" || remSellAdd == "Q")
					{
						goodInput = true;
					}
					else
					{
						std::cout << "I'm sorry, but the key you pressed was not a valid input. Please try again." << std::endl;
					}
				}
				//q to quit
				if (remSellAdd == "q" || remSellAdd == "Q") {
					hasQuit = true;
					std::cout << "Quitting... Thank you for your time..." << std::endl;
				}
				//remove an item
				else if (remSellAdd == "r" || remSellAdd == "R") {
					//ask for item name, check if it's in the inventory, remove
					std::cout << "Please enter the name of the item you would like to remove: ";
					std::string toRemove = "";
					bool goodInput = false;
					while (!goodInput) {
						std::cin >> toRemove;
						if (isInInventory(toRemove))
						{
							goodInput = true;
						}
						else
						{
							std::cout << "I'm sorry, but the item you have entered is not in your inventory. Please try again." << std::endl;
						}
					}
					removeItem(toRemove);
					std::cout << "Your item has been removed! This is what your inventory looks like now: \n" << listItems() << std::endl;

				}
				//sell an item
				else if (remSellAdd == "s" || remSellAdd == "S") {
					//ask for item name, check if it's in the inventory, sell
					std::cout << "Please enter the name of the item you would like to remove: ";
					std::string toSell = "";
					bool goodInput = false;
					while (!goodInput) {
						std::cin >> toSell;
						if (isInInventory(toSell))
						{
							goodInput = true;
						}
						else
						{
							std::cout << "I'm sorry, but the item you have entered is not in your inventory. Please try again." << std::endl;
						}
					}
					sellItem(toSell);
					std::cout << "Your item has been sold! This is what your inventory looks like now: \n" << listItems() << std::endl;

				}
				//add an item
				else {
					//borrow Joe's add/remove interface from test
					addItem();
					std::cout << "Your new item has been added! This is what your inventory looks like now: \n" << listItems() << std::endl;

				}
			}

		} //gold or items decision point

		  // ----------------------------------------------------------------------------------------------------------
		  //			END OF ITEM-RELATED FUNCTIONS

		  // ----------------------------------------------------------------------------------------------------------
		  //			QUITTING

		else {
			hasQuit = true;
			std::cout << "Quitting... Thank you for your time..." << std::endl;
		} //gold/items decision point

	} //while loop for interfaace
	return;
}


void Inventory::addItem() {
	//joe's walkthrough here (thanks, Joe!)
	std::cout << "Would you like a weapon or armor?" << std::endl;
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
		while (!(std::cin >> numItem) || numItem == 0 || numItem < 0) {
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
		std::cout << "For this version though, we'll give you a bit more freedom." << std::endl << "Please enter the name of your armor; be as heroic as possible! (make sure the name is one word)" << std::endl;
		std::cout << "Item name: ";
		std::string itemName = "";
		std::cin >> itemName;
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

		//Assigns worth and type
		std::cout << std::endl;
		std::cout << "Your item undoubtedly holds a lot of value. What is the worth of your item? ";
		int worth = 0;

		//Checks user input to make sure it's an integer
		while (!(std::cin >> worth) || worth == 0 || worth < 0) {
			//Some code I found online. Basically catches when cin cannot turn the input into an integer
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "I'm sorry, but the key you pressed was not a valid input. Please try again." << std::endl;
		}
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

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
		Item* item = new ItemWeapon(itemName, worth, numItem, type);
		addItem(item);
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
		while (!(std::cin >> numItem) || numItem == 0 || numItem < 0) {
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
		std::cout << "For this version though, we'll give you a bit more freedom." << std::endl << "Please enter the name of your armor; be as heroic as possible! (make sure the name is one word)" << std::endl;
		std::cout << "Item name: ";
		std::string itemName = "";
		std::cin >> itemName;
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');


		//Assigns worth and type
		std::cout << std::endl;
		std::cout << "Your item undoubtedly holds a lot of value. What is the worth of your item? ";
		int worth = 0;

		//Checks user input to make sure it's an integer
		while (!(std::cin >> worth) || worth == 0 || worth < 0) {
			//Some code I found online. Basically catches when cin cannot turn the input into an integer
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "I'm sorry, but the key you pressed was not a valid input. Please try again." << std::endl;
		}
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');


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
		Item* item = new ItemArmor(itemName, worth, numItem);
		addItem(item);

	}

}