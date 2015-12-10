//		ItemWeapon.cpp
//	Author: Beth Dellea
//  Date created: 11/19/2015


//#include "stdafx.h"
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
ItemWeapon::ItemWeapon(const ItemWeapon& ItemToCopy) {
	name = ItemToCopy.name;
	worth = ItemToCopy.worth;
	sellPrice = worth / 2;
	quantity = ItemToCopy.quantity;
	type = ItemToCopy.type;
	nextItem = nullptr;

}


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

Item* ItemWeapon::getNext() {
	return nextItem;
}

void ItemWeapon::setNext(Item* upcomingItem) {
	nextItem = upcomingItem;
}


std::string ItemWeapon::getName() {
	return name;
}



//makes a string of the item to be added to a file
std::string ItemWeapon::stringMe() {
	//idek tbh
	std::string toReturn = "w\t"; //w because this item is a weapon
	toReturn += name + "\t";
	//use stringstream for this shitt
	std::stringstream myStream;
	myStream << worth << "\t" << sellPrice << "\t" << quantity << "\t";
	toReturn += myStream.str() + type;

	return toReturn;

}


ItemWeapon* ItemWeapon::removeSelf(int num) {
	//checking for appropriate removal quantity is done in Inventory, assumed to be right here
	ItemWeapon* copiedSelf = new ItemWeapon(*this);
	int quantDiff = copiedSelf->getQuantity() - num; //set the quantity of what's being returned to the number we want
	copiedSelf->changeQuantity(quantDiff*-1);		//we need to remove the difference between actual and desired quant
	this->changeQuantity(num*-1); //remove those being removed from this actual object
	return copiedSelf;

}

ItemWeapon* ItemWeapon::copySelf() {
	ItemWeapon* copied = new ItemWeapon(*this);
	return copied;
}