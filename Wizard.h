/*
* Wizard.h
*
* Version information v0.1
* Author: Dr. Shane Wilson
* Date: 11/10/2017
* Description: Header for the Wizard class
* Copyright notice
*/

#pragma once

#include <iostream>
#include <string>
#include <vector>
#include "Weapon.h"
#include "Item.h"
#include "Armour.h"

class Wizard
{
private:
	std::string name_;
	std::string characterType_;
	int health_;
	int level_;
	std::vector <Item> inventory_{};
	std::vector <Weapon> weapons_{};
	std::vector <Armour> armour_{};
public:
	Wizard();
	Wizard(std::string name, std::string characterType, int health, int level);
	~Wizard();

	void SetName(std::string name);
	std::string GetName() const;

	void SetCharacterType(std::string character);
	std::string GetCharacterType() const;

	void SetHealth(int health);
	int GetHealth() const;

	void SetLevel(int level);
	int GetLevel() const;

	void PickUpItem(Item item);
	void DropItem(Item item);
	
	void PickUpArmour(Armour arm);
	void DropArmour(Armour arm);

	void PickUpWeapon(Weapon wep);
	void DropWeapon(Weapon wep);

	void ListInventory();
};
