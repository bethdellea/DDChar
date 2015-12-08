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
ItemWeapon::ItemWeapon(const ItemWeapon& ItemToCopy) {
	name = ItemToCopy.name;
	worth = ItemToCopy.worth;
	sellPrice = worth / 2;
	quantity = ItemToCopy.quantity;
	type = ItemToCopy.type;
	nextItem = nullptr;

}


//			SHOULD BE TAKEN CARE OF IN ITEM, STILL HERE IN CASE SOMETHING GOES WRONG
/*


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

*/

ItemWeapon* ItemWeapon::removeSelf(int num) {
	if (this->quantity >= num) {
		ItemWeapon* copiedSelf = new ItemWeapon(*this);
		int quantDiff = copiedSelf->getQuantity - num; //set the quantity of what's being returned to the number we want
		copiedSelf->changeQuantity(quantDiff*-1);		//we need to remove the difference between actual and desired quant
		this->changeQuantity(num*-1); //remove those being removed from this actual object
		return copiedSelf;
	}
	//removing too many exception

}

ItemWeapon* ItemWeapon::copySelf() {
	ItemWeapon* copied = new ItemWeapon(*this);
	return copied;
}