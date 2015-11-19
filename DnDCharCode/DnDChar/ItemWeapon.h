#pragma once
//		ItemWeapon.h
//	Author: Beth Dellea
//  Date created: 11/19/2015
#ifndef __Item__
#define __Item___
#include <string>
#include "ItemADT.h"
class ItemWeapon : public ItemADT {

private:
	std::string name;
	int worth;
	int sellPrice;
	//int* effects; //assuming effects will be kept in an int array, can definitely change though
	ItemADT* nextItem; //necessary since we're making Inventory a linked list
	int quantity; //should increase since we can't have duplicate entries
	std::string type; 

public:
	// constructor
	ItemWeapon(std::string itemName, int itemWorth, int numAdding, std::string itemType);
	//copy constructor
	ItemWeapon(const ItemWeapon& itemToCopy);

	int getQuantity();
	int changeQuantity(int changeVal);

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

#endif /* defined(__Item__) */