#include <iostream>
#include <fstream>
#include <string>
#include "HTable.h"

using namespace std;

const std::string inFileName = "testData.csv";

void readData(HTable &mainTable);

void main()
{
	try 
	{
		HTable mainTable;

		readData(mainTable);
		mainTable.dumpTable();
	}
	catch (string e)
	{
		cout << e << endl;
	}
}

void readData(HTable &mainTable)
{
	ifstream inFile(inFileName);
	string data, email;

	if (!inFile.is_open())
	{
		throw("Failed to open" + inFileName);
	}

	while (getline(inFile, data, ','))
	{
		getline(inFile, email);

		mainTable.insert(email, data);
	}
}