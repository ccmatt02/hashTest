#include "HTable.h"
#include "HNode.h"
#include <iostream>

using namespace std;

HTable::HTable()
{
}

int HTable::getKey(std::string email)
{
	return static_cast<int>(tolower(email[0])) - static_cast<int>('a');
}

bool HTable::insert(std::string email, std::string data)
{
	mainTable[getKey(email)].push_back(HNode(data, email));

	return true;
}

std::string HTable::getData(std::string email)
{
	int key = getKey(email);

	for (int i = mainTable[key].size(); i > 0; i--)
	{
		if (mainTable[key][i].getEmail() == email)
		{
			return mainTable[key][i].getData();
		}
	}

	return std::string("DATA MISSING");

}

void HTable::dumpTable()
{

}