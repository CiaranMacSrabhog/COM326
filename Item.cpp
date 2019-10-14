#include "Item.h"



Item::Item()
{
}

Item::Item(std::string name, std::string description, int value) :
	name_{ name }, description_{ description }, value_{ value } {}


std::string Item::GetName() const {
	return name_;
}

void  Item::SetName(std::string name) {
	name_ = name;
}

std::string Item::GetDescription() const {
	return description_;
}

void  Item::SetDescription(std::string description) {
	description_ = description;
}

int Item::GetValue() const {
	return value_;
}

void  Item::SetValue(int value) {
	value_ = value;
}



