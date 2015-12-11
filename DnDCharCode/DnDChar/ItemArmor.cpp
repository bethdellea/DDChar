//		ItemArmor.cpp
//	Author: Beth Dellea
//  Date created: 11/19/2015


#include "stdafx.h"
#include "ItemArmor.h"
#include <sstream>

ItemArmor::ItemArmor(std::string itemName, int itemWorth, int numAdding) {
	name = itemName;
	worth = itemWorth;
	sellPrice = worth / 2; //standard formula, for now
	quantity = numAdding;
	nextItem = nullptr;
}

//ToDo: Copy Constructor
ItemArmor::ItemArmor(const ItemArmor& ItemToCopy) {
	name = ItemToCopy.name;
	worth = ItemToCopy.worth;
	sellPrice = worth / 2;
	quantity = ItemToCopy.quantity;
	nextItem = nullptr;

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



//makes a string of the item to be added to a file
std::string ItemArmor::stringMe() {
	std::string toReturn = "a\t"; //a because this item is armor
	toReturn += name + "\t";
	//use stringstream for this type casting thing
	std::stringstream myStream;
	myStream << worth << "\t" << sellPrice << "\t" << quantity << "\t";
	toReturn += myStream.str();

	return toReturn;
}


ItemArmor* ItemArmor::removeSelf(int num) {
	//checking for appropriate removal quantity is done in Inventory, assumed to be right here
	ItemArmor* copiedSelf = new ItemArmor(*this);
	int quantDiff = copiedSelf->getQuantity() - num; //set the quantity of what's being returned to the number we want
	copiedSelf->changeQuantity(quantDiff*-1);		//we need to remove the difference between actual and desired quant
	this->changeQuantity(num * -1); //remove those being removed from this actual object
	return copiedSelf;
}


ItemArmor* ItemArmor::copySelf() {
	ItemArmor* copied = new ItemArmor(*this);
	//we couldn't add a virtual copy constructor, so this function is  in both item types and can be called from Inventory
	return copied;
}