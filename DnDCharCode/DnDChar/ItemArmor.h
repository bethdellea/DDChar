//		ItemArmor.h
//	Author: Beth Dellea
//  Date created: 11/19/2015
#ifndef __ItemArmor__
#define __ItemArmor__

#include "ItemADT.h"
#include "ItemWeapon.h"
#include "Inventory.h"

class ItemArmor : public ItemADT {

private:
	std::string name;
	int worth;
	int sellPrice;
	//int* effects; //assuming effects will be kept in an int array, can definitely change though
	ItemADT* nextItem; //necessary since we're making Inventory a linked list
	int quantity; //should increase since we can't have duplicate entries
	
public:
	// constructor
	ItemArmor(std::string itemName, int itemWorth, int numAdding);
	//copy constructor
	ItemArmor(const ItemArmor& itemToCopy);

	int getQuantity();
	void changeQuantity(int changeVal);

	//returns the item's value
	int getWorth();
	//returns the price the item will sell for -- could be stored as a var or calculated based on the worth
	int getSellPrice();
	//k I'm not reall sure how this one will work. We'll get there eventually.
	//void applyEffects();

	ItemADT* getNext();

	void setNext(ItemADT* upcomingItem);

	std::string getName();
};

#endif /* defined(__Item__) */#pragma once