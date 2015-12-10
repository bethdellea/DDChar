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

//TODO: check copy constructor
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

Inventory::Inventory(std::string fName){
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
				Item* itemIn;
				std::string* charsArray = new std::string[6];
				int curr = 0;
				while (linestream) {
					std::string itemData;
					getline(linestream, itemData, '\t');
					charsArray[curr] = itemData;
					curr++;
				}

				if (charsArray[0] == "a") {
					//then the item is armor. sweet.
					std::string itemName = charsArray[1];
					int itemWorth = atoi(charsArray[2].c_str());
					int sellP = atoi(charsArray[3].c_str()); //calculated by ItemArmor right now, but here because some day that might change
					int itemQuant = atoi(charsArray[4].c_str());		//and then we'd need to input it
					itemIn = new ItemArmor(itemName, itemWorth, itemQuant);
				}
				else if (charsArray[0] == "w") {
					//then the item is a weapon. kewl.
					std::string itemName = charsArray[1];
					int itemWorth = atoi(charsArray[2].c_str()); //casts these strings back into ints so they're useable
					int sellP = atoi(charsArray[3].c_str());
					int itemQuant = atoi(charsArray[4].c_str());
					std::string itemType = charsArray[5];
					itemIn = new ItemWeapon(itemName, itemWorth, itemQuant, itemType);
				}

				//we just made the item from its line, now we add it to this brave new inventory
				addItem(itemIn);
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
		ownedItems += curr->getName() + "\t Quantity: " + std::to_string(curr->getQuantity()) + "\tValue: "+ std::to_string(curr->getWorth()) + "\n";
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
	//exception for overdraft needed!!!!!
}

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
	toWrite += getGold() + "\n";
		while (curr != nullptr) {
		toWrite += curr->stringMe() + "\n";
		curr = curr->getNext();
	}
	//then do something with the compiled strings
	//you know, that writing to a file shit
	std::cout << "Please enter the desired name for your inventory file: ";
	std::string filename;
	while (!(std::cin >> filename) || filename =="") {
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
	while (!hasQuit) {
		std::cout << "Welcome to your inventory. Here you can view and manage your inventory and gold." << std::endl;
		if (firstItem == nullptr) {
			std::cout << "You currently have no items in your inventory." << std::endl;
		}
		else {
			std::cout << "The following items are in your inventory: " << listItems() << std::endl;
		}
		std::cout << "\nYour current gold balance is: " << getGold() << std::endl;

		hasQuit = true;
	}
}