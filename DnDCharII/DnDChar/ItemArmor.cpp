//		ItemArmor.cpp
//	Author: Beth Dellea
//  Date created: 11/19/2015


#include "stdafx.h"
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
	name = ItemToCopy.name;
	worth = ItemToCopy.worth;
	sellPrice = worth / 2;
	quantity = ItemToCopy.quantity;
	nextItem = nullptr;

}



//			SHOULD BE TAKEN CARE OF IN ITEM, STILL HERE IN CASE SOMETHING GOES WRONG
/*

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

*/

ItemArmor* ItemArmor::removeSelf(int num) {
	if (this->quantity >= num) {
		ItemArmor* copiedSelf = new ItemArmor(*this);
		int quantDiff = copiedSelf->getQuantity - num; //set the quantity of what's being returned to the number we want
		copiedSelf->changeQuantity(quantDiff*-1);		//we need to remove the difference between actual and desired quant
		this->changeQuantity(num*-1); //remove those being removed from this actual object
		return copiedSelf;
	}
	//removing too many exception

}


ItemArmor* ItemArmor::copySelf() {
	ItemArmor* copied = new ItemArmor(*this);
	return copied;
}