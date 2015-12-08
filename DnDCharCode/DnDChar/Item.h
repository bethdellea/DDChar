//		Item.h
//	Author: Beth Dellea
//  Date created: 11/16/2015
#ifndef __Item__
#define __Item__

#include <string>

class Item {

private:
	std::string name;
	int worth;
	int sellPrice;
	//int* effects; //assuming effects will be kept in an int array, can definitely change though
	Item* nextItem; //necessary since we're making Inventory a linked list
	int quantity; //should increase since we can't have duplicate entries
	bool isArmor;  //XOR with this and weapon
	bool isWeapon;
	std::string type; //only for weapons, rel isProf


public:
	//Item(std::string itemName, int itemWorth, int numAdding);   //need to do this in a way that it'll make whatever it needs, you know????
	//Item(const Item* itemIn);
	virtual int getQuantity();
	virtual void changeQuantity(int changeVal);

	//returns the item's value
	virtual int getWorth();
	//returns the price the item will sell for -- could be stored as a var or calculated based on the worth
	virtual int getSellPrice();

	//k I'm not reall sure how this one will work. We'll get there eventually.
	//void applyEffects();

	virtual Item* getNext();

	virtual void setNext(Item* upcomingItem);

	virtual std::string getName();

	//part of the removal process, returns the removed items to Inventory's remove function
	//if completely depleted, Inventory needs to remove fully and update itself
	virtual Item* removeSelf(int num) = 0;

	virtual Item* copySelf() = 0;
};

#endif /* defined(__Item__) */