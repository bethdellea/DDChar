//		ItemWeapon.h
//	Author: Beth Dellea
//  Date created: 11/19/2015
#ifndef __ItemWeapon__
#define __ItemWeapon__

#include "Item.h"

class ItemWeapon : public Item {

private:
	std::string name;
	int worth;
	int sellPrice;
	//int* effects; //assuming effects will be kept in an int array, can definitely change though
	Item* nextItem; //necessary since we're making Inventory a linked list
	int quantity; //should increase since we can't have duplicate entries
	std::string type; 

public:
	// constructor
	ItemWeapon(std::string itemName, int itemWorth, int numAdding, std::string itemType);
	//copy constructor
	ItemWeapon(const ItemWeapon& itemToCopy);



	//			THESE FUNCTIONS SHOULD BE INHERITED FROM ITEM AND BE FUNCTIONAL FROM THAT
			//let's pretend that never happened, ok?
	int getQuantity();
	void changeQuantity(int changeVal);

	//returns the item's value
	int getWorth();
	//returns the price the item will sell for -- could be stored as a var or calculated based on the worth
	int getSellPrice();
	//k I'm not reall sure how this one will work. We'll get there eventually.
	//void applyEffects();

	Item* getNext();

	void setNext(Item* upcomingItem);

	std::string getName();


	//part of the removal process, returns the removed items to Inventory's remove function
	//if completely depleted, Inventory needs to remove fully and update itself
	ItemWeapon* removeSelf(int num);

	//makes and returns a copy of the object via its copy constructor
	//should be used with Inventory's copy constructor
	ItemWeapon* copySelf();
};

#endif /* defined(__Item__) */