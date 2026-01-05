#include <iostream>
#include <string>
#include <list>
#include <vector>
#include <algorithm>
#include <limits>

struct Character
{
	int id;
	int locX;
	int locY;
	float health;
	std::string name;

};

struct Meteor {
	int id;
	int locX;
	int locY;
	float damage;
};

//void addCharacter(std::vector<Character> characters, const std::string name,float health,int locX,int locY) {
//	Character character;
//
//	character.id = nextId++;
//	character.name = name;
//	character.health = health;
//	character.locX = locX;
//	character.locY = locY;
//	
//	characters.push_back(character);
//}

bool isInRadius(int centerlocX,int centerlocY,int pointlocX,int pointlocY, int radius)
{
	int dx = pointlocX - centerlocX;
	int dy = pointlocY - centerlocY;

	return (dx * dx + dy * dy) <= (radius * radius);
}

void meteora() {
	std::vector<Character> characters;
	int N;
	int nextId = 0;

	std::cout << "How many characters does we have?" << std::endl;
	std::cin >> N;

	for (int i = 1; i <= N; i++) {
		std::string tempName = "";
		float tempHealth = 0;
		int templocX = 0;
		int templocY = 0;


		std::cout << "###################################################################" << std::endl;

		std::cout << "Character Name" << std::endl;
		std::cin >> tempName;

		std::cout << "Charcter Health" << std::endl;
		std::cin >> tempHealth;

		std::cout << "Character LocX" << std::endl;
		std::cin >> templocX;

		std::cout << "Character LocY" << std::endl;
		std::cin >> templocY;


		Character character;

		character.id = nextId++;
		character.name = tempName;
		character.health = tempHealth;
		character.locX = templocX;
		character.locY = templocY;

		characters.push_back(character);
	}

	for (auto charecter : characters ) {
		std::cout << "###################################################################" << std::endl;
		std::cout << "Name:" << charecter.name << std::endl;
		std::cout << "Health:" << charecter.health << std::endl;
		std::cout << "LocX:" << charecter.locX << std::endl;
		std::cout << "LocY:" << charecter.locY << std::endl;
		std::cout << "ID:" << charecter.id << std::endl;
		std::cout << "###################################################################" << std::endl;
	}

	Meteor meteor;

	std::cout << "Meteor strength:" << std::endl;
	std::cin >> meteor.damage;

	std::cout << "Meteor location X axis:" << std::endl;
	std::cin >> meteor.locX;

	std::cout << "Meteor location Y axis:" << std::endl;
	std::cin >> meteor.locY;

	meteor.id = 0;

	for (auto character : characters) {
		if (isInRadius(meteor.locX, meteor.locY, character.locX, character.locY, (3 * meteor.damage))) {
			character.health = std::clamp(
				character.health - meteor.damage,
				0.0f,
				static_cast<float>(INT_MAX)
			);
			
			std::cout << "###################################################################" << std::endl;
			std::cout << "********Damaged*********" << std::endl;
			std::cout << "Name:" << character.name << std::endl;
			std::cout << "Health:" << character.health << std::endl;
			std::cout << "LocX:" << character.locX << std::endl;
			std::cout << "LocY:" << character.locY << std::endl;
			std::cout << "ID:" << character.id << std::endl;
			std::cout << "###################################################################" << std::endl;
		}

		if (character.health <= 0) {
			std::cout << "###################################################################" << std::endl;
			std::cout << "********Dead*********" << std::endl;
			std::cout << "Name:" << character.name << std::endl;
			std::cout << "Health:" << character.health << std::endl;
			std::cout << "LocX:" << character.locX << std::endl;
			std::cout << "LocY:" << character.locY << std::endl;
			std::cout << "ID:" << character.id << std::endl;
			std::cout << "###################################################################" << std::endl;
		}
		
	}

}

int main() {
	meteora();
}