//		Inventory.cpp
//	Author: Beth Dellea
//  Date created: 11/18/2015


#include "stdafx.h"
#include "Inventory.h"
#include <stdio.h>
#include <iostream>
#include <string>

Inventory::Inventory() {
	numGold = 0;
	firstItem = nullptr;
	lastItem = nullptr;

}

//TODO: copy constructor
Inventory::Inventory(const Inventory* inventoryIn) {
	numGold = inventoryIn->numGold;
	Item* curr = inventoryIn->firstItem;		
	firstItem = curr->copySelf();				
	Item* copiedCurr = firstItem;   
	Item* nextItem;
	curr = curr->getNext();
	while (curr != nullptr) {
		nextItem = curr->copySelf();		//workaround for the fact that copy constructors can't be virtual
		copiedCurr->setNext(nextItem);			//hypothetically works for nonexistant items
		curr = curr->getNext();
	}
	lastItem = nextItem;
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
	std::cout << "How many of " << itemName << "would you like to sell?";
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
	else if(curr->getQuantity() == quant){
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
		ownedItems += curr->getName();
		ownedItems += "\t Quantity: ";
		ownedItems += std::to_string(curr->getQuantity());
		ownedItems += "\n";
		curr = curr->getNext();
	}

	return ownedItems;
}

//returns the amount of gold the character possesses
int Inventory::getGold() {
	return numGold;
}

//adds gold to the total!
void Inventory::addGold(int deposit){
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
	while (curr->getName()!= itemName) {
		curr = curr->getNext();
		indx++;
	}
	return indx;
}

bool Inventory::isInInventory(std::string itemName) {
	Item* curr = firstItem;

	while (curr !=nullptr) {
		if (curr->getName() == itemName) {
			return true;
		}
		curr = curr->getNext();
	}
	return false;

}

//deletes this beautiful linked list of Items
Inventory::~Inventory() {
	Item* curr = firstItem;
	Item* next  = nullptr;
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