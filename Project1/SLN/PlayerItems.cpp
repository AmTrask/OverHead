#include "PlayerItems.h"



PlayerItems::PlayerItems()
{
	for (int x = 0; x < INVENTORYSIZE; x++)
	{
		this->itemList[x] = 999;
	}
	this->itemAvailable = 0;
}

bool PlayerItems::itemStore(int itemGotIdentification) 
{
	if (itemAvailable < INVENTORYSIZE)
	{
		itemList[itemAvailable] = itemGotIdentification;
		itemAvailable++;
		itemReorganise();
		return true;
	}
	else
	{
		return false;
	}
}
void PlayerItems::itemDelete(int itemIdentification)
{
	itemList[itemIdentification] = 999;
	itemAvailable--;
	itemReorganise();
}

void PlayerItems::itemUse(int itemIdentification)
{
	if (itemAvailable > 0)
	{
		//Calls item Effect (add later)
		itemAvailable--;
		itemList[itemIdentification] = 999;
		itemReorganise();
	}
}
void PlayerItems::itemReorganise()
{
	int temp;
	for (int x = 0; x < INVENTORYSIZE; x++)
	{
		for (int y = x + 1; y < INVENTORYSIZE; y++)
		{
			if (itemList[y] < itemList[x])
			{
				temp = itemList[x];
				itemList[x] = itemList[y];
				itemList[y] = temp;
			}
		}
	}
}
bool PlayerItems::isValidDuringFights(int itemIdentification)
{
	if (!(itemList[itemIdentification] <= 4 || itemList[itemIdentification] == 999))
	{
		return false;
	}
	else return true;
}

int PlayerItems::getItemIdentification(int position)
{
	return itemList[position];
}
int PlayerItems::getItemCount()
{
	return itemAvailable;
}
std::string PlayerItems::getItemName(int itemIdentification)
{
	switch (itemIdentification)
	{
	case 1:
		return "*MONSTER CANDY";
	case 2:
		return "*APPLE";
	case 3:
		return "*CHEWING GUM";
	case 4:
		return "*LEGENDARY HERO";
	case 999:
		return "*RETURN";
	}
}