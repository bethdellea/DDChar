//		ItemArmor.cpp
//	Author: Beth Dellea
//  Date created: 11/19/2015


#include "stdafx.h"
#include <sstream>
#include "ItemArmor.h"

ItemArmor::ItemArmor(std::string itemName, int itemWorth, int numAdding) {
	name = itemName;
	worth = itemWorth;
	sellPrice = worth / 2; //standard formula, for now
	quantity = numAdding;
	nextItem = nullptr;
}

//ToDo: Copy Constructor
ItemArmor::ItemArmor(const ItemArmor& ItemToCopy) {
	name = ItemToCopy->getName();
	worth = ItemToCopy->getWorth();
	sellPrice = worth / 2;
	quantity = ItemToCopy->getQuantity();
	nextItem = nullptr; //should this be null or point to whatever the copying item points to??
}



int ItemArmor::getQuantity() {
	return quantity;
}
void ItemArmor::changeQuantity(int changeVal) {
	quantity += changeVal; //if decreasing, make sure changeVal is negative!!
}


//returns the item's value
int ItemArmor::getWorth() {
	return worth;
}
//returns the price the item will sell for -- could be stored as a var or calculated based on the worth
int ItemArmor::getSellPrice() {
	return sellPrice;
}

Item* ItemArmor::getNext() {
	return nextItem;
}

void ItemArmor::setNext(Item* upcomingItem) {
	nextItem = upcomingItem;
}


std::string ItemArmor::getName() {
	return name;
}
