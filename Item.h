#pragma once

#include <string>

class Item
{
private:
	std::string name_;
	std::string description_;
	int value_;

public:
	Item();
	Item(std::string name, std::string description, int value);
	

	std::string GetName() const;
	void SetName(std::string name);
	std::string GetDescription() const;
	void SetDescription(std::string description);
	int GetValue() const;
	void SetValue(int value);

};
