#include <iostream>
#include <string>
#include <list>
#include <vector>
#include <algorithm>
#include <limits>
#include <map>
#include <sstream>

class Character
{
private:
	int speed;
	int defaultX;
	int defaultY;

public:
	void Move(int x,int y) {
		defaultX += x * speed;
		defaultY += y * speed;
	}

	void enterData(int tempX,int tempY,int tempSpeed) {
		speed = tempSpeed;
		defaultX = tempX;
		defaultY = tempY;
	}
	
	void printData() {
		std::cout << "Current speed:" << speed << std::endl;
		std::cout << "Current X position:" << defaultX << std::endl;
		std::cout << "Current Y position:" << defaultY << std::endl;
	}
};

int readInt() {
	std::string input;
	int value;

	while (true) {
		std::getline(std::cin, input);
		std::stringstream ss(input);

		if (ss >> value && ss.eof()) {
			return value; // valid int
		}

		std::cout << "Invalid integer. Try again: ";
	}
}

int main() {
	std::map <int,Character> characters;
	
	bool exit = false;
	int N;

	std::cout << "Enter How many characters we have" << std::endl;
	std::cin >> N;


	for (int i = 1; i <= N; i++) {
		int templocX = 0;
		int templocY = 0;
		int tempSpeed = 0;

		std::cout << "Enter Charcter position X" << std::endl;
		templocX = readInt();
		std::cout << "Enter Charcter position Y" << std::endl;
		templocY = readInt();
		std::cout << "Enter Charcter speed" << std::endl;
		tempSpeed = readInt();

		Character character;

		character.enterData(templocX, templocY, tempSpeed);

		character.printData();

		characters.insert({ i,character });

	}

	int idKey;
	int moveLocX;
	int moveLocY;

	std::cout << "Enter character ID" << std::endl;
	idKey = readInt();

	std::cout << "Enter to move X loc" << std::endl;
	moveLocX = readInt();
	std::cout << "Enter to move Y loc" << std::endl;
	moveLocY = readInt();

	characters[idKey].Move(moveLocX, moveLocY);

	characters[idKey].printData();
}