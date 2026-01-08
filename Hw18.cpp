#include <iostream>
#include <map>
#include <string>
#include <limits>
#include <vector>
#include <algorithm>
#include <sstream>

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

int GetPlayerCount() {
	int playerCount;
	std::cout << "How big is your party?" << std::endl;
	playerCount = readInt();
	return playerCount;
}

std::map<std::string, int> CreateParty(int& playerCount) {
	std::map<std::string, int> party;
	for (int i = 1; i <= playerCount; i++) {
		int health;
		std::string name;
		std::cout << "Enter Health for Player " << std::to_string(i) << std::endl;
		health = readInt();
		std::cout << "Enter Name for Player " << std::to_string(i) << std::endl;
		std::cin >> name;
		party.insert({name,health});

	}
	return party;
}

void PrintParty(const std::map<std::string, int>& party) {
	for (auto& p : party) {
		std::cout << p.first << ":" << p.second << std::endl;
	}
}

void GetMaxHealth(std::map<std::string, int>& party) {
	std::vector<std::string> maxPlayers;
	int maxVal = std::numeric_limits<int>::min();

	for (const auto& p : party) {
		maxVal = std::max(maxVal, p.second);
	}

	for (auto& pmax : party) {
		if (pmax.second == maxVal) {
			maxPlayers.push_back(pmax.first);

		}
	}

	std::cout << maxVal << " Maximum Health" << std::endl;
	for (std::string max : maxPlayers) {
		std::cout << max << " has maximal health" << std::endl;
	}
}

void GetMinHealth(const std::map<std::string, int>& party) {
	int minVal = std::numeric_limits<int>::max();
	std::vector<std::string> minPlayers;

	for (const auto& p : party) {
		minVal = std::min(minVal, p.second);
	}

	for (auto& pmin : party) {
		if (pmin.second == minVal) {
			minPlayers.push_back(pmin.first);

		}
	}

	std::cout << minVal << " Minimal Health" << std::endl;
	for (std::string min : minPlayers) {
		std::cout << min << " has minimal health" << std::endl;
	}
}

std::map<std::string, int> doDamage(int damage, std::map<std::string, int>& party) {
	for (auto& pdamage : party) {
		pdamage.second = std::clamp(pdamage.second - damage,0,INT_MAX);
	}

	return party;
}

void CheckDeath(std::map<std::string, int>& party) {
	std::vector <std::string> dead;
	for (const auto& p : party) {
		if (p.second <= 0) {
			dead.push_back(p.first);
		}
	}

	for (std::string corpse : dead) {
		std::cout << corpse << " is dead" << std::endl;
	}
}
int main() {
	int playerCount = GetPlayerCount();
	int damage;
	bool exit = false;
	std::map<std::string, int> party = CreateParty(playerCount);
	PrintParty(party);
	std::cout << "How much damage party recieves" << std::endl;
	damage = readInt();
	party = doDamage(damage, party);

	while (exit != true)
	{
		int option;
		std::cout << "Type command to do:"<< std::endl <<"1 - Min" << std::endl
			<<"2 - Max" << std::endl << "3 - Dead" << std::endl << "0 - Exit" << std::endl;
		std::cin >> option;

		if (option == 0) {
			exit = true;
		}
		if (option == 1) {
			GetMinHealth(party);
		}
		if (option == 2) {
			GetMaxHealth(party);
		}
		if (option == 3) {
			CheckDeath(party);
		}
	}


}