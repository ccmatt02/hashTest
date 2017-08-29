#include "HNode.h"

std::string HNode::getData()
{
	return this->data;
}

std::string HNode::getEmail()
{
	return this->email;
}

void HNode::setData(std::string in)
{
	this->data = in;
}

void HNode::setEmail(std::string in)
{
	this->email = in;
}