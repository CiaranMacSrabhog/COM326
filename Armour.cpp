#include "Armour.h"



Armour::Armour()
{

	//std::string name_;
	//std::string description_;
	//int value_;
	//ArmourType armourType_;
	//ArmourMaterial armourMaterial_;
	//int defensiveValue_;
	//bool equipped_;
}


std::string Armour::GetName() const {
	return name_;
}

void  Armour::SetName(std::string name) {
	name_ = name;
}

std::string Armour::GetDescription() const {
	return description_;
}

void  Armour::SetDescription(std::string description) {
	description_ = description;
}

int Armour::GetValue() const {
	return value_;
}

void  Armour::SetValue(int value) {
	value_ = value;
}

void Armour::SetDefensiveValue(int value) {
	defensiveValue_ = value;
}

int Armour::GetDefensiveValue() const {
	return defensiveValue_;

}

void Armour::SetArmourType(ArmourType at) {
	armourType_ = at;
}

void Armour::SetArmourMaterial(ArmourMaterial am) {
	armourMaterial_ = am;
}

ArmourMaterial Armour::GetArmourMaterial() const {
	return armourMaterial_;

}

void Armour::SetEquipped(bool equip) {
	equipped_ = equip;
}
bool Armour::GetEquipped() const {
	return equipped_;
}
