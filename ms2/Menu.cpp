#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "Menu.h"
#include "Utils.h"

namespace sdds {

    void Menu::setEmpty() {
        numOfOption = 0;
        menuContent = nullptr;
    }

    Menu::Menu(const char* menu) {
        setEmpty();

        if (menu != nullptr) {
            // Count the number of options based on the number of tabs
            numOfOption = 1;
            for (size_t i = 0; menu[i] != '\0'; i++) {
                if (menu[i] == '\t') {
                    numOfOption++;
                }
            }

            // Limit the number of options to MAX_MENU
            if (numOfOption > MAX_MENU) {
                numOfOption = MAX_MENU;
            }

            // Allocate memory for the menu content and copy it
            menuContent = new char[strlen(menu) + 1];
            strcpy(menuContent, menu);
        }
    }

    int Menu::run() const {
        int input = 0;
        if (isValid()) {
            while (true) {
                std::cout << getMenuContent();
                std::cout << "0- Exit" << std::endl;
                input = ut.getInt(0, numOfOption, "> ");

                if (input >= 0 && input <= numOfOption) {
                    return input;
                }
                else {
                    if (input < 0) {
                        std::cout << "Invalid Menu! ";
                    }
                    else {
                        std::cout << "Value out of range [0<=val<=" << numOfOption << "]: ";
                    }
                }
            }
        }
        else {
            std::cout << "Invalid Menu!" << std::endl;
            return 0;
        }
    }

    const char* Menu::getMenuContent() const {
        return menuContent;
    }

    int Menu::getNumOfOpt() const {
        return numOfOption;
    }

    Menu& Menu::operator=(int num) {
        if (num >= 0 && num <= MAX_MENU) {
            numOfOption = num;
        }
        return *this;
    }

    Menu& Menu::operator=(const char* menu) {
        if (menu != nullptr) {
            delete[] menuContent;
            menuContent = new char[strlen(menu) + 1];
            strcpy(menuContent, menu);
        }
        return *this;
    }

    Menu& Menu::clear() {
        delete[] menuContent;
        menuContent = nullptr;
        numOfOption = 0;
        return *this;
    }

    bool Menu::isValid() const {
        return numOfOption > 0 && numOfOption <= MAX_MENU && menuContent != nullptr;
    }

    Menu::~Menu() {
        delete[] menuContent;
    }
}
