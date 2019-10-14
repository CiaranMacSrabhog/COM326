#pragma once
#include <string>

enum ArmourType { Helmet, shield, gloves, chest, leg, arms };
enum ArmourMaterial { Steel, Iron, Leather, Wood, Cloth, Paper};

class Armour {

private:
	std::string name_;
	std::string description_;
	int value_;
	int weight_;
	ArmourType armourType_;
	ArmourMaterial armourMaterial_;
	int defensiveValue_;
	bool equipped_;


public:
	Armour();
	
	std::string GetName() const;
	void SetName(std::string name);
	std::string GetDescription() const;
	void SetDescription(std::string description);
	int GetValue() const;
	void SetValue(int value);
	void SetDefensiveValue(int value);
	int GetDefensiveValue() const;

	void SetArmourType(ArmourType at);

	void SetArmourMaterial(ArmourMaterial am);
	ArmourMaterial GetArmourMaterial() const;

	void SetEquipped(bool equip);
	bool GetEquipped() const;

};
