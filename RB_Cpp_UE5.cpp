// RB_Cpp_UE5.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <algorithm>

int main()
{
    std::string name;
    std::int16_t age;
    std::string xenos;
    std::string PlayerClass;
    bool HasChosenClass = false;
    float health;
    bool HasHealthSet = false;

    std::cout << "I need your Name traveler" << "\n";
    std::cin >> name;
    std::cout << "Now tell me your age traveler " << name << "\n";
    std::cin >> age;
    std::cout << "Hmm at your age of " << age << ". You took great care of yourself." << "\n";
    std::cout << "Be Proud traveler " << name << " !" << " And tell me what Xenos do you represent"<<"\n";
    std::cin >> xenos;
    std::cout << "You are from mighty " << xenos << " people,then tell me " << name << ". What type of warrior you are!" << "\n";
    
    
    while (HasChosenClass != true) {
        std::cout << "(chose only from mage , archer or barbar)" << "\n";
        std::cin >> PlayerClass;
        std::transform(PlayerClass.begin(), PlayerClass.end(), PlayerClass.begin(), ::tolower);

        if (PlayerClass == "mage" || PlayerClass == "archer" ||PlayerClass == "barbar") {
            std::cout << " So you are mighty " << PlayerClass << "\n";
            HasChosenClass = true;
        }
        else
        {
            std::cout << "Hmm, I do not percieve the knowlodge of this class chose another one" << "\n";
            continue;
        }
    }

    while (HasHealthSet != true) {
        std::cout << "And at last tell me how is your health in you ripe age of " << age << "?" << "\n";
        std::cin >> health;
        if (health <= 100.0 || health >=1) {
            std::cout << "So you have " << health << " health" << "\n";
            HasHealthSet = true;
        }
        else {
            std::cout << "You have more health do not lie to me" << "\n";
            continue;
        }
    }

    std::cout << "Welcome to Agartha o mighty " << xenos << " " << name << " with your ripe health of " << health << " and skills of " << PlayerClass << "\n";
    std::cout << "After long " << age << " years of searching" << "\n";
    std::cout << "You reached us and we Welcome you to the Land Down Under. " << "\n";

  
}
