//		Items.h
//	Author: Beth Dellea
//  Date created: 11/16/2015
#ifndef __Item__
#define __Item___
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
	// constructor
	Item(std::string itemName, int itemWorth, int quantity, std::string itemType);
	//copy constructor
	Item(const Item& itemToCopy);

	//returns the item's value
	int getWorth();
	//returns the price the item will sell for -- could be stored as a var or calculated based on the worth
	int getSellPrice();
	//k I'm not reall sure how this one will work. We'll get there eventually.
	//void applyEffects();

	Item* getNext();

};

#endif /* defined(__Item__) */