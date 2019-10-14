#include "Archer.h"



Archer::Archer() 
	: health_{ 0 }
{
	std::cout << "An Archer has been born!\n";
	std::cout << "via the default constructor\n\n";
}


Archer::~Archer()
{
}


Archer::Archer(std::string name, std::string characterType, int health, int level) :
	name_{ name }, characterType_{ characterType }, level_{ level } {

	std::cout << "An Archer has been born!\n\n";
	
}

void Archer::SetName(std::string name) {
	name_ = name;
}
std::string Archer::GetName() const {
	return name_;
}

void Archer::SetCharacterType(std::string character) {
	characterType_ = character;
}
std::string Archer::GetCharacterType() const {
	return characterType_;
}

void Archer::SetHealth(int health) {
	health_ += health;
}
int Archer::GetHealth() const {
	return health_;
}

void Archer::SetLevel(int level) {
	level_ = level;
}
int Archer::GetLevel() const {
	return level_;
}

void Archer::PickUpItem(Item item) {
	inventory_.push_back(item);
}

void Archer::DropItem(Item item) {
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

void Archer::PickUpArmour(Armour arm) {
	armour_.push_back(arm);
}

void Archer::DropArmour(Armour arm) {
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

void Archer::PickUpWeapon(Weapon wep) {
	weapons_.push_back(wep);
}

void Archer::DropWeapon(Weapon wep) {
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

void Archer::ListInventory() {

	//Search for a matching item in the inventory
	std::vector<Item>::iterator it;
	std::cout << "\nThe inventory for character " << GetName() << " is:" << std::endl;
	for (it = inventory_.begin(); it != inventory_.end(); it++) {
		std::cout << "\n" << it._Ptr->GetName() << "\t" << it._Ptr->GetDescription() << "\t" << it._Ptr->GetValue() << std::endl;
	}
}
