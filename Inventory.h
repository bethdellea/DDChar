//		Inventory.h
//	Author: Beth Dellea
//  Date created: 11/16/2015


#ifndef __Inventory__
#define __Inventory__
#include "Item.h"
#include <string>

class removeBadItemException : std::exception {};

class Inventory {
	//linked list of items
private:
	int numGold;
	Item* firstItem; //let's do this linked list thing

	//fcns that alter the actual list should not be public, probably
	//adds an item to the list of Items
	void addItem(Item itemToAdd);
	//removes the desired item from the list, adds the resale price to the character's gold
	//could have it sell by index value or by item name or whatever we like
	void sellItem(std::string itemName);
	//removes an item from the character's inventory
	Item removeItem(std::string itemName);

public:
	Inventory();

	Inventory(const Inventory& inventoryIn); // <- copy constructor

	//our beautiful class's toString function, gives all items in inventory
	std::string listItems();
	//returns the amount of gold the character possesses
	int getGold();

	//returns a copy of the item we're looking for
	Item getItem(std::string itemName);

	//returns the index position of the item by its name
	int getIndex(std::string itemName);

	//deletes this beautiful linked list of Items
	~Inventory() {};
};

#endif /* defined(__Inventory__) */
