#ifndef  HTABLE_H
#define HTABLE_H

#include <vector>
#include <string>
#include "HNode.h"

const std::string dumpFile = "tableDump.html";

class HTable {
public:
	HTable();

	int getKey(std::string email);

	bool insert(std::string email, std::string data);
	std::string getData(std::string email);

	void dumpTable();

private:
	std::vector<HNode> mainTable[26];
};

#endif // ! HTABLE_H
