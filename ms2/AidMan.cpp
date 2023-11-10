#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "AidMan.h"
#include "Date.h"

using namespace std;
namespace sdds {
    AidMan::AidMan(const char* filename) : fileName(nullptr), option("1- List Items\n2- Add Item\n3- Remove Item\n4- Update Quantity\n5- Sort\n6- Ship Items\n7- New/Open Aid Database\n---------------------------------\n")
	{
		if (filename)
		{
			fileName = new char[strlen(filename) + 1];
			strcpy(fileName, filename);
		}
	}

	int AidMan::menu() const
	{
		int select;
		cout << "Aid Management System" << endl;
		cout << "Date: " << Date() << endl;
		if (fileName)
		{
			cout << "Data file: " << fileName << endl;
		}
		else
		{
			cout << "Data file: No file" << endl;
		}
		cout << "---------------------------------" << endl;
		select = option.Menu::run();
		return select;
	}

	void AidMan::searchList(const char* menu, int select)
	{
		char list[30];
		int menuLen = 0;
		int count = 0;
		int j = 0;
		menuLen = strlen(option.getMenuContent());
		if (select > 0)
		{
			for (int i = 0; i < menuLen; i++)
			{
				if (option.getMenuContent()[i] == '\n')
				{
					count++;
					if (count == select)
					{
						list[j] = '\0';
						i = strlen(option.getMenuContent());
					}
				}
				if (count == select - 1)
				{
					list[j] = option.getMenuContent()[i];
					j++;
				}
			}
			if (select == count)
			{
				cout << "\n****";
				if (select == 1)
				{
					for (int i = 3; list[i] != '\0'; i++)
					{
						cout << list[i];
					}
				}
				else
				{
					for (int i = 4; list[i] != '\0'; i++)
					{
						cout << list[i];
					}
				}
				cout << "****\n" << endl;
			}
		}
	}

	void AidMan::run()
	{
		int select = 0;
		AidMan test(fileName);
		do
		{
			select = test.menu();
			if (select == 0)
			{
				cout << "Exiting Program!" << endl;
			}
			else
			{
				searchList(option.getMenuContent(), select);
			}
		} while (select != 0);
	}

	AidMan::~AidMan()
	{
		delete[] fileName;
		option.clear();
	}
}