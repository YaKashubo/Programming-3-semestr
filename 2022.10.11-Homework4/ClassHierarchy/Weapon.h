#pragma once
class Weapon
{
protected:
	int ammo;
	int damage;
	bool fire(bool isClicked);
	bool reload(int Key);
};


