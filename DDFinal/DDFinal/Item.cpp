//			Item.cpp
//	Author: Beth Dellea
//	Date Created: 12/3/2015

//#include "stdafx.h"
#include "Item.h"

/*			//nice in theorey, but since they can't be virtual it messes up things down the line, I think
Item::Item(std::string itemName, int itemWorth, int numAdding) {
name = itemName;
worth = itemWorth;
sellPrice = worth / 2; //standard formula, for now
quantity = numAdding;
nextItem = nullptr;
}

//ToDo: Copy Constructor
Item::Item(const Item* ItemToCopy) {}

*/

int Item::getQuantity() {
	return quantity;
}
void Item::changeQuantity(int changeVal) {
	quantity += changeVal; //if decreasing, make sure changeVal is negative!!
}


//returns the item's value
int Item::getWorth() {
	return worth;
}
//returns the price the item will sell for -- could be stored as a var or calculated based on the worth
int Item::getSellPrice() {
	return sellPrice;
}

Item* Item::getNext() {
	return nextItem;
}

void Item::setNext(Item* upcomingItem) {
	nextItem = upcomingItem;
}


std::string Item::getName() {
	return name;
}
