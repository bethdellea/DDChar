//		Item.cpp
//	Author: Beth Dellea
//  Date created: 11/18/2015


#include "stdafx.h"
#include <sstream>
#include "Item.h"

Item::Item(std::string itemName, int itemWorth, int numAdding, std::string itemType) {
	name = itemName;
	worth = itemWorth;
	sellPrice = worth / 2; //standard formula, for now
	quantity = numAdding;
	//some evaluation to determine item type. not right now, though.
	nextItem = nullptr;
}

//ToDo: Copy Constructor
Item::Item(const Item& ItemToCopy) {}



int Item::getQuantity() {
	return quantity;
}
int Item::changeQuantity(int changeVal) {
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
