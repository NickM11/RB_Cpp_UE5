#include <iostream>
#include <vector>
#include <algorithm>

#include <string>
#include <map>

std::map<int, int> CreateArmy() {
	std::map<int, int> army;
	int ArmyCount;

	std::cout << "Tell me how many groups we have?" << std::endl;
	std::cin >> ArmyCount;

	for (int i = 1; i <= ArmyCount; i++) {
		int amount;
		int type;
		std::cout << "Enter Type of the Group " << std::to_string(i) << std::endl;
		std::cin >> type;
		std::cout << "Enter Amount of Troops " << std::to_string(i) << std::endl;
		std::cin >> amount;
		auto it = army.find(type);
		if (it != army.end()) {
			army[type] += amount;
		}
		else {
			army.insert({ type,amount });
		}
		

	}
	return army;
}
void PrintParty(const std::map<int, int> party) {
	for (auto& p : party) {
		std::cout << p.first << ":" << p.second << std::endl;
	}
}

void GetMaxHealth(std::map<int, int> party) {
	std::vector<int> maxArmies;
	int maxVal = std::numeric_limits<int>::min();

	for (const auto& p : party) {
		maxVal = std::max(maxVal, p.second);
	}

	for (auto& pmax : party) {
		if (pmax.second == maxVal) {
			maxArmies.push_back(pmax.first);

		}
	}

	std::cout << maxVal << " is biggest army size" << std::endl;
	for (int max : maxArmies) {
		std::cout << max << " group has biggest army" << std::endl;
	}
}

void GetMinHealth(std::map<int, int> party) {
	std::vector<int> minArmies;
	int minVal = std::numeric_limits<int>::max();

	for (const auto& p : party) {
		minVal = std::min(minVal, p.second);
	}

	for (auto& pmin : party) {
		if (pmin.second == minVal) {
			minArmies.push_back(pmin.first);

		}
	}

	std::cout << minVal << " is smallest army size" << std::endl;
	for (int min : minArmies) {
		std::cout << min << " group has smallest army" << std::endl;
	}
}

void Cords() {
	//vars
	int x;
	int y;
	int N;
	int speed;
	std::vector<std::string> directions;

	//Coordites start position;
	std::cout << "Enter start x coordinate" << std::endl;
	std::cin >> x;
	std::cout << "Enter start y coordinate" << std::endl;
	std::cin >> y;

	//Speed
	std::cout << "Enter speed" << std::endl;
	std::cin >> speed;

	//Steps
	std::cout << "How many Steps N do we move?" << std::endl;
	std::cin >> N;

	for (int i = 1; i <= N; i++) {
		std::string temp;
		std::cout << "Enter direction (right,left,forward, backward)" << std::endl;
		std::cin >> temp;
		directions.push_back(temp);
	}
	
	std::cout << directions.size() << std::endl;
	std::reverse(directions.begin(), directions.end());

	for (auto j : directions) {
		if (j == "right") {
			x += speed;
		}
		if (j == "left") {
			x -= speed;
		}
		if (j == "forward") {
			y += speed;
		}
		if (j == "backward") {
			y -= speed;
		}
	}
	
	std::cout << "Current X coordinate is: " << x << std::endl;
	std::cout << "Current Y coordinate is: " << y << std::endl;
}

int main() {
	bool exit = false;

	std::map<int, int> army;

	while (exit!=true)
	{
		int option;
		std::cout << "Type command to do:" << std::endl << "1 - First Program" << std::endl
			<< "2 - Second Program" << std::endl << "0 - Exit" << std::endl;
		std::cin >> option;

		if (option == 0) {
			exit = true;
		}
		if (option == 1) {
			army = CreateArmy();
			PrintParty(army);
			GetMaxHealth(army);
			GetMinHealth(army);

		}
		if (option == 2) {
			std::cout << "Option 2" << std::endl;
			Cords();
		}
	}
}