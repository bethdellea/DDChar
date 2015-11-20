//		ItemWeapon.cpp
//	Author: Beth Dellea
//  Date created: 11/19/2015


#include "stdafx.h"
#include <sstream>
#include "ItemWeapon.h"

ItemWeapon::ItemWeapon(std::string itemName, int itemWorth, int numAdding, std::string itemType) {
	name = itemName;
	worth = itemWorth;
	sellPrice = worth / 2; //standard formula, for now
	quantity = numAdding;
	type = itemType;
	nextItem = nullptr;
}

//ToDo: Copy Constructor
ItemWeapon::ItemWeapon(const ItemWeapon& ItemToCopy) {}



int ItemWeapon::getQuantity() {
	return quantity;
}
void ItemWeapon::changeQuantity(int changeVal) {
	quantity += changeVal; //if decreasing, make sure changeVal is negative!!
}


//returns the item's value
int ItemWeapon::getWorth() {
	return worth;
}
//returns the price the item will sell for -- could be stored as a var or calculated based on the worth
int ItemWeapon::getSellPrice() {
	return sellPrice;
}

ItemADT* ItemWeapon::getNext() {
	return nextItem;
}

void ItemWeapon::setNext(ItemADT* upcomingItem) {
	nextItem = upcomingItem;
}


std::string ItemWeapon::getName() {
	return name;
}
