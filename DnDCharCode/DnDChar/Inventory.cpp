//		Inventory.cpp
//	Author: Beth Dellea
//  Date created: 11/18/2015


#include "stdafx.h"
#include "Inventory.h"
#include <stdio.h>
#include <sstream>

Inventory::Inventory() {
	numGold = 0;
	firstItem = nullptr;
	lastItem = nullptr;

}

//TODO: copy constructor
Inventory::Inventory(const Inventory& inventoryIn) {

}

void Inventory::addItem(Item* itemToAdd) {
	if (firstItem == nullptr) {
		firstItem = itemToAdd;
	}
	else {
		if (!isInInventory(itemToAdd->getName())) {
			if (lastItem == nullptr) {
				lastItem = itemToAdd;
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
	if (curr->getQuantity > 1) {
		curr->changeQuantity(-1);
	}
	else {
		//assuming that loop got us where we want to be... requires testing
		temp->setNext(curr->getNext());
		addGold(curr->getSellPrice); //no haggling here, unfortunately
		delete(curr);
	}
}

//removes all of the item rn, sorry not sorry
Item* Inventory::removeItem(std::string itemName) {
	int itemIndex = getIndex(itemName);
	Item* curr = firstItem;
	Item* temp = nullptr;
	for (int i = 0; i < itemIndex; i++) {
		temp = curr;		//same algorithm as selling as far as traversing and removing the thing
		curr = curr->getNext();		//if that one was wrong, so is this.
	}
	temp->setNext(curr->getNext());
	Item* returnable = new Item(*curr);//makes a copy for returning purposes
	delete (curr);
	return returnable; //user should delete this, yo!
}

std::string Inventory::listItems() {
	//try out that stringstream thing, yeah?

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
		if (curr->getName == itemName) {
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