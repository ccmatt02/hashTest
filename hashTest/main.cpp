#include <iostream>
#include "HTable.h"

using namespace std;

void main()
{
	HTable mainTable;

	mainTable.insert("test@email.com", "TEST DATA!");

	cout << mainTable.getData("test@email.com");
}