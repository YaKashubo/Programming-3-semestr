#pragma once
class Weapon
{
protected:
	int ammo;
	int damage;
	bool fire(bool isClicked);
	bool reload(int Key);
};
class Shotgun : public Weapon
{
protected:
	void splash(int radius);
};
class SniperRifle : public Weapon
{
protected:
	void Scope(bool key);
};
class AssaultRifle : public Weapon
{
protected:
	void FastFiring(bool isButtonHolded);
};
class Pistol : public Weapon
{
protected:
	bool FireModeChange(bool Key);
};
class Grenade : public Weapon
{
protected:
	void Explosion(int time);
};
class SmokeGrenade : public Grenade
{
protected:
	void smoke(int radius);
};
class HandGrenade : public Grenade
{
protected:
	void AreaDamage(int radius);
};
