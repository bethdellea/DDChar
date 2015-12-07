//		Item.cpp
//	Author: Beth Dellea
//  Date created: 12/04/2015


#include "stdafx.h"
#include <sstream>
#include "Item.h"

Item::Item(std::string itemName, int itemWorth, int numAdding) {
	name = itemName;
	worth = itemWorth;
	sellPrice = worth / 2; //standard formula, for now
	quantity = numAdding;
	nextItem = nullptr;
}

/*
Item::Item(const Item& ItemToCopy) {
	name = ItemToCopy->getName();
	worth = ItemToCopy->getWorth();
	sellPrice = worth / 2;
	quantity = ItemToCopy->getQuantity();
	nextItem = nullptr; //should this be null or point to whatever the copying item points to??
}
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
