//		ItemADT.h
//	Author: Beth Dellea
//  Date created: 11/16/2015
#ifndef __Item__
#define __Item___
#include <string>
class ItemADT {
	
private:
	std::string name;
	int worth;
	int sellPrice;
	//int* effects; //assuming effects will be kept in an int array, can definitely change though
	ItemADT* nextItem; //necessary since we're making Inventory a linked list
	int quantity; //should increase since we can't have duplicate entries
	bool isArmor;  //XOR with this and weapon
	bool isWeapon;
	std::string type; //only for weapons, rel isProf

public:
	
	virtual int getQuantity() = 0;
	virtual int changeQuantity(int changeVal) = 0;

	//returns the item's value
	virtual int getWorth() = 0;
	//returns the price the item will sell for -- could be stored as a var or calculated based on the worth
	virtual int getSellPrice() = 0;
	//k I'm not reall sure how this one will work. We'll get there eventually.
	//void applyEffects();

	virtual ItemADT* getNext() = 0;

	virtual void setNext(ItemADT* upcomingItem) = 0;

	virtual std::string getName() = 0;
};

#endif /* defined(__Item__) */