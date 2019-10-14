/*
* Warrior.cpp
*
* Version information v0.1
* Author: Dr. Shane Wilson
* Date: 11/10/2017
* Description: Header for the warrior class
* Copyright notice
*/

#include "Warrior.h"

Warrior::Warrior()
	: health_{ 0 }
{
	std::cout << "A warrior has been born!\n";
	std::cout << "via the default constructor\n\n";
}

Warrior::~Warrior()
{
}


Warrior::Warrior(std::string name, std::string characterType, int health, int level) :
	name_{ name }, characterType_{ characterType }, level_{ level } {

	std::cout << "A warrior has been born!\n\n";
}

void Warrior::SetName(std::string name) {
	name_ = name;
}
std::string Warrior::GetName() const {
	return name_;
}

void Warrior::SetCharacterType(std::string character) {
	characterType_ = character;
}
std::string Warrior::GetCharacterType() const {
	return characterType_;
}

void Warrior::SetHealth(int health) {
	health_ += health;
}
int Warrior::GetHealth() const {
	return health_;
}

void Warrior::SetLevel(int level) {
	level_ = level;
}
int Warrior::GetLevel() const {
	return level_;
}

void Warrior::PickUpItem(Item item) {
	inventory_.push_back(item);
}

void Warrior::DropItem(Item item) {
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


void Warrior::DropArmour(Armour arm) {
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

void Warrior::PickUpArmour(Armour arm) {
	armour_.push_back(arm);
}

void Warrior::PickUpWeapon(Weapon wep) {
	weapons_.push_back(wep);
}

void Warrior::DropWeapon(Weapon wep) {
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


void Warrior::ListInventory(){

	//Search for a matching item in the inventory
	std::vector<Item>::iterator it;
	std::cout << "\nThe inventory for character " << GetName() << " is:" << std::endl;
	for (it = inventory_.begin(); it != inventory_.end(); it++) {
		std::cout << "\n" << it._Ptr->GetName() << "\t" << it._Ptr->GetDescription() << "\t" << it._Ptr->GetValue() << std::endl;
	}
}
