#include <iostream>
#include <string>

class Character
{
private:
	int health = 0;
	struct Attributes
	{
		int dexterity = 0;
		int agility = 0;
		int wisdom = 0;
	};

	Attributes attributes;

	class Weapon
	{
	public:
		void setVariables(int dmg,int cld) {
			damage = dmg;
			cooldown = cld;
		}
		void setIcon(int setSize, std::string setType) {
			weaponIcon.size = setSize;
			weaponIcon.type = setType;
		}
		void getWeaponInfo() {
			std::cout << "################Weapon stats###################" << std::endl;
			std::cout << damage << std::endl;
			std::cout << cooldown << std::endl;
			std::cout << "################Icon Info###################" << std::endl;
			std::cout << weaponIcon.size << std::endl;
			std::cout << weaponIcon.type << std::endl;
		}
	private:
		int damage = 0;
		int cooldown = 0;
		struct Icon
		{
			int size = 0;
			std::string type ="";
		};
		Icon weaponIcon;
	};

	class PassiveItem
	{
	public:
		void setIcon(int setSize,std::string setType) {
			icon.size = setSize;
			icon.type = setType;
		}

		void setModedAttributes(int dex,int agi,int wis){
			modedAttributes.agility = agi;
			modedAttributes.dexterity = dex;
			modedAttributes.wisdom = wis;
		}
		int getDexterity(){
			return modedAttributes.dexterity;
		}
		int getAgility() {
			return modedAttributes.agility;
		}
		int getWisdom() {
			return modedAttributes.wisdom;
		}

	private:
		struct ModedAttributes
		{
			int dexterity = 0;
			int agility = 0;
			int wisdom = 0;
		};
		struct Icon
		{
			int size = 0;
			std::string type = "";
		};

		ModedAttributes modedAttributes;

		Icon icon;
	};
	PassiveItem passiveItem;
	Weapon weapon;

public:


	void setVariables(int setHealth) {
		health = setHealth;
	}

	void setAttributes(int dex,int agi,int wis) {
		attributes.dexterity = dex;
		attributes.agility = agi;
		attributes.wisdom = wis;
	}

	void InitializeWeapon(int iconsize, std::string icontype,int wpnDmg,int wpnCld) {
		weapon.setVariables(wpnDmg,wpnCld);
		weapon.setIcon(iconsize,icontype);
	}
	void IntializePassiveItem(int iconsize, std::string icontype,int modDex,int modAgi,int modWis) {
		passiveItem.setIcon(iconsize,icontype);
		passiveItem.setModedAttributes(modDex,modAgi,modWis);
	}
	void GetWeaponInfo() {
		weapon.getWeaponInfo();
	}
	
	void getAttributes() {
		attributes.dexterity += passiveItem.getDexterity();
		attributes.agility += passiveItem.getAgility();
		attributes.wisdom += passiveItem.getWisdom();

		std::cout << "################Atributes###################" << std::endl;
		std::cout << attributes.dexterity << std::endl;
		std::cout << attributes.agility << std::endl;
		std::cout << attributes.wisdom << std::endl;

	}






};

int main() {
	Character character;
	character.setVariables(100);
	character.setAttributes(10,11,12);
	character.IntializePassiveItem(64,".png",10,10,10);
	character.InitializeWeapon(64, ".png", 10, 10);

	character.getAttributes();
	character.GetWeaponInfo();

}