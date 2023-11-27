/*
	==================================================
	Mile Stone 2
	==================================================
	Name   : Kojo Anyane Obese
	ID     : 137653226
	Email  : kaobese@myseneca.ca
	Section: NHH
	Date   : 2023/11/16
// I have done all the coding by myself and only copied the code that
my professor provided to complete my workshops and assignments.//
*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "AidMan.h"
#include "Menu.h"
#include "Date.h"

using namespace std;
namespace sdds
{
	AidMan::AidMan(const char *filename) : fileName(nullptr), option("1- List Items\t\n2- Add Item\t\n3- Remove Item\t\n4- Update Quantity\t\n5- Sort\t\n6- Ship Items\t\n7- New/Open Aid Database\n---------------------------------\n")
	{
		if (filename != nullptr)
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
		cout << endl;
		select = option.Menu::run();
		return select;
	}

	void AidMan::searchList(const char *menu, int select)
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
				cout << "****\n"
					 << endl;
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