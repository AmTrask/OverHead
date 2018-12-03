#ifndef ITEMS_H
#define ITEMS_H
#include <string>
const int INVENTORYSIZE = 6;
class PlayerItems
{
public:
	PlayerItems();
	bool itemStore(int itemGotIdentification);
	void itemUse(int itemIdentification);
	void itemDelete(int itemIdentification);
	void itemReorganise();
	int getItemIdentification(int position);
	std::string getItemName(int itemIdentification);
	int getItemCount();
	bool isValidDuringFights(int itemIdentification);
private:
	int itemAvailable, itemList[INVENTORYSIZE];

};

#endif ITEMS_H