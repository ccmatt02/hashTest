#ifndef HNODE_H
#define HNODE_H

#include <string>

class HNode {
public:
	HNode(std::string d, std::string e) : data{ d }, email{ e } {}
	
	std::string getData();
	std::string getEmail();

	void setData(std::string in);
	void setEmail(std::string in);

private:
	std::string email;
	std::string data;
};


#endif  /* !HNODE_H */
