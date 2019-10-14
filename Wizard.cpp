/*
* Wizard.cpp
*
* Version information v0.1
* Author: Dr. Shane Wilson
* Date: 11/10/2017
* Description: Header for the Wizard class
* Copyright notice
*/

#include "Wizard.h"



Wizard::Wizard()
	: health_{ 0 }
{
	std::cout << "A Wizard has been born!\n";
	std::cout << "via the default constructor\n\n";
}

Wizard::~Wizard()
{
}

Wizard::Wizard(std::string name, std::string characterType, int health, int level) :
	name_{ name }, characterType_{ characterType }, level_{ level }{
	std::cout << "A warrior has been born!\n\n";
}
void Wizard::SetName(std::string name) {
	name_ = name;
}
std::string Wizard::GetName() const {
	return name_;
}

void Wizard::SetCharacterType(std::string character) {
	characterType_ = character;
}
std::string Wizard::GetCharacterType() const {
	return characterType_;
}

void Wizard::SetHealth(int health) {
	health_ += health;
}
int Wizard::GetHealth() const {
	return health_;
}

void Wizard::SetLevel(int level) {
	level_ = level;
}
int Wizard::GetLevel() const {
	return level_;
}

void Wizard::PickUpItem(Item item) {
	inventory_.push_back(item);
}

void Wizard::DropItem(Item item) {
	//Search for a matching item in the inventory
	std::vector<Item>::iterator it;

	for (it = inventory_.begin(); it != inventory_.end(); it++)
		std::cout << it._Ptr->GetName() << ' ';


	for (int index = 0; index != inventory_.size(); index++) {
		if (inventory_[index].GetName() == item.GetName()) {
			inventory_.erase(inventory_.begin() + index);
		}

	}

}

void Wizard::DropArmour(Armour arm) {
	//Search for a matching item in the inventory
	std::vector<Armour>::iterator it;

	for (it = armour_.begin(); it != armour_.end(); it++)
		std::cout << it._Ptr->GetName() << ' ';


	for (int index = 0; index != armour_.size(); index++) {
		if (armour_[index].GetName() == arm.GetName()) {
			armour_.erase(armour_.begin() + index);
		}

	}

}

void Wizard::PickUpArmour(Armour arm) {
	armour_.push_back(arm);
}


void Wizard::PickUpWeapon(Weapon wep) {
	weapons_.push_back(wep);
}

void Wizard::DropWeapon(Weapon wep) {
	//Search for a matching item in the inventory
	std::vector<Weapon>::iterator it;

	for (it = weapons_.begin(); it != weapons_.end(); it++)
		std::cout << it._Ptr->GetType() << ' ';


	for (int index = 0; index != weapons_.size(); index++) {
		if (weapons_[index].GetType() == wep.GetType()) {
			weapons_.erase(weapons_.begin() + index);
		}

	}

}


void Wizard::ListInventory() {

	//Search for a matching item in the inventory
	std::vector<Item>::iterator it;
	std::cout << "\nThe inventory for character " << GetName() << " is:" << std::endl;
	for (it = inventory_.begin(); it != inventory_.end(); it++) {
		std::cout << "\n" << it._Ptr->GetName() << "\t" << it._Ptr->GetDescription() << "\t" << it._Ptr->GetValue() << std::endl;
	}
}
