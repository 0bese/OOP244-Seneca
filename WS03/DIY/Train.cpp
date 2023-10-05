#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstdio>
#include <cstring>
#include "Train.h"

using namespace std;
using namespace sdds;

void Train::initialize(){
    if (trainName != nullptr){
        delete[] trainName;
        trainName = nullptr;
    }
    noOfPeople = 0;
    departureTime = 0;
}

bool Train::validTime(int value)const{
    if (value >= MIN_TIME && value <= MAX_TIME) {
        int minutes = value % 100;

        return (minutes <= 59);
    }
	return false;
}

bool Train::validNoOfPassengers(int value)const{
    bool ok = false;

	if (value >= 0 && value <= MAX_NO_OF_PASSENGERS) {
		ok = true;
	}

	return ok;
}

void Train::set(const char* name) {
	delete[] trainName;
	trainName = nullptr;

	if (name != nullptr && name[0] != '\0') {
		trainName = new char[strlen(name) + 1];
		strcpy(trainName, name);
	}
}

void Train::set(int noOfPassengers, int departure) {
	if (validNoOfPassengers(noOfPassengers)) {
		noOfPeople = noOfPassengers;
	}
	else noOfPeople = -1;
	

	if (validTime(departure)) {
		departureTime = departure;
	}
	else departureTime = -1;
}

void Train::set(const char* name, int noOfPassengers, int departure) {
    set(name);
	set(noOfPassengers, departure);
}

void Train::finalize() {
    delete[] trainName;
	trainName = nullptr;
}

bool Train::isInvalid() const {
	return (trainName == nullptr || trainName[0] == '\0' || noOfPeople <= 0 || departureTime <= 0);
}

int Train::noOfPassengers() const {
	return noOfPeople;
}

int Train::getDepartureTime() const {
	return departureTime;
}

const char* Train::getName() const {
	return trainName;
}

void Train::display() const {
	if (!isInvalid()){
		std::cout << "NAME OF THE TRAIN:    " << getName() << std::endl
	              << "NUMBER OF PASSENGERS: " << noOfPassengers() << std::endl
                  << "DEPARTURE TIME:       " << getDepartureTime() << std::endl;
	}
	else std::cout << "Train in an invalid State!" << std::endl;
}

bool Train::load(int& notBoarded) { 
    std::cout << "Enter number of passengers boarding:\n> ";
    int value;

    if (std::cin >> value) {

        if (value > 0 && value + noOfPeople< MAX_NO_OF_PASSENGERS) {
            noOfPeople += value ;
            notBoarded = 0;
            return true;
        } 
		else {
            notBoarded = (value + noOfPeople) - MAX_NO_OF_PASSENGERS;
            noOfPeople = MAX_NO_OF_PASSENGERS;
            return false;
        }
    } 
	return false;
}

bool Train::updateDepartureTime() {
	std::cout << "Enter new departure time:\n> ";

	if (std::cin >> departureTime) {
		if (validTime(departureTime)) {
			return true;
		}
		departureTime = -1;
	}

	return false;
}

bool Train::transfer(const Train& from) {
	bool transfer = false;

	if (!this->isInvalid() && !from.isInvalid()) {
		size_t combinedLength = strlen(this->trainName) + strlen(", ") + strlen(from.trainName) + 1;

		char* newTName = new char[combinedLength];

		if (newTName != nullptr) {
			strcpy(newTName, this->trainName);
			strcat(newTName, ", ");
			strcat(newTName, from.trainName);

			delete[] this->trainName;

			this->trainName = newTName;
			this->noOfPeople += from.noOfPeople;

			if (validNoOfPassengers(this->noOfPeople)) {
				transfer = true;
			}
			else {
				cout << "Train is full; " << this->noOfPeople - MAX_NO_OF_PASSENGERS << " passengers of " << from.trainName << " could not be boarded!" << endl;
				this->noOfPeople = MAX_NO_OF_PASSENGERS;
				transfer = true;
			}
		}
		else {
			cout << "Memory allocation failed for the new name." << endl;
		}
	}

	return transfer;
}