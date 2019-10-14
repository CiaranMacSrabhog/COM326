#include "Weapon.h"



Weapon::Weapon()
{
	std::cout << "An awesome weapon has once more been crafted by master blacksmith Shane\n";
	std::cout << "...via the default constructor\n";
}


Weapon::~Weapon()
{
}

Weapon::Weapon(std::string type, int damage, int level)
	: type_{ type }, damage_{ damage }, level_{ level } {

	std::cout << "An awesome weapon has once more been crafted by master blacksmith Shane\n";
}


void Weapon::SetType(std::string type) {
	type_ = type;
}
std::string Weapon::GetType()const {
	return type_;
}

void Weapon::SetDamage(int damage) {
	damage_ = damage;
}
int Weapon::GetDamage()const {
	return damage_;
}

void Weapon::SetLevel(int level) {
	level_ = level;
}
int Weapon::SetLevel()const {
	return level_;

}
