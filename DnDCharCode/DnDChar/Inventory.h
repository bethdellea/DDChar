//		Inventory.h
//	Author: Beth Dellea
//  Date created: 11/16/2015


#ifndef __Inventory__
#define __Inventory__

#include "ItemWeapon.h"
#include "ItemArmor.h"
#include "Item.h"
#include <string>

class removeBadItemException : std::exception {};

class Inventory {
	//linked list of items
private:

	int numGold;
	
	Item* lastItem;

public:
    Item* firstItem; //let's do this linked list thing
	Inventory();

	Inventory(const Inventory* inventoryIn); // <- copy constructor

											 //makes a new inventory by loading one saved to a file
											 //whatever calls this functions neesd to ask for the file name to use
	Inventory(std::string fName);

	//our beautiful class's toString function, gives all items in inventory
	std::string listItems();

	//adds an item to the list of Items
	//if duplicate item, increase quantity
	void addItem(Item* itemToAdd);

	//returns the amount of gold the character possesses
	int getGold();

	//adds gold to the total!
	void addGold(int deposit);

	//removes gold!
	void removeGold(int withdrawal);

	/*		//this function is not acutally necessary with the way the inventory functions. for that reason, it's commented out
	//returns a copy of the item we're looking for
	Item* getItem(std::string itemName);
	*/

	//returns the index position of the item by its name
	int getIndex(std::string itemName);

	bool isInInventory(std::string itemName);


	//removes the desired item from the list, adds the resale price to the character's gold
	//could have it sell by index value or by item name or whatever we like
	void sellItem(std::string itemName);
	//removes an item from the character's inventory
	//removes every one of the item, not just one, because simplicity.
	Item* removeItem(std::string itemName);

	//writes the inventory to a file!
	void toFile(std::string filename);

	//the function that loops and allows users to select the actions they wish to take with their inventory
	void interact();

	//calls the walkthrough for adding an item to the inventory, which then calls the other addItem()
	void addItem();

	//deletes this beautiful linked list of Items
    ~Inventory();
};

#endif /* defined(__Inventory__) */
