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
	
	for (int i = (mainTable[key].size()) - 1; i >= 0; i--)
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
	ofstream dumpFile(dumpFileName);

	if (!dumpFile.is_open())
	{
		throw("Failed to open file " + dumpFileName);
	}

	dumpFile << "<HTML>\n<BODY>\n<TABLE>\n";
	dumpFile << "<tr><th>Data</th><th>Email</th><th>Key</th></tr>\n";

	for (int i = 0; i < 26; i++)
	{
		for (int j = mainTable[i].size() - 1; j >= 0; j--)
		{
			dumpFile << "<tr>\n";
			dumpFile << "\t<td>" << mainTable[i][j].getData() << "</td>\n";
			dumpFile << "\t<td>" << mainTable[i][j].getEmail() << "</td>\n";
			dumpFile << "\t<td><strong>" << i << "</strong></td>\n";
			dumpFile << "</tr>\n";
		}
	}

	dumpFile << "</TABLE>\n</BODY>\n</HTML>\n";

	dumpFile.close();

}