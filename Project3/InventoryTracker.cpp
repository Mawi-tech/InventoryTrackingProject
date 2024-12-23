#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include "InventoryTracker.h"

using namespace std; 
void InventoryTracker::OpenAndReadFile() {
	cout << "Opening file" << endl;
	inFS.open("CS210_Project_Three_Input_File.txt");
	if (!inFS.is_open()) {
		cout << "Failed to open file" << endl;
	}
}

void InventoryTracker::CreateBackupFile() {
	string word;
	itemFreqMap.clear();
	inFS.clear(); 
	inFS.seekg(0, std::ios::beg);
	while (!inFS.eof()) {
		inFS >> word;
		if (!inFS.fail()) {
			itemFreqMap[word]++;
		}
	}

	// Write the frequencies to frequency.dat
	ofstream outFile("frequency.dat");
	if (!outFile.is_open()) {
		cout << "Failed to open backup file for writing." << endl;
		return;
	}

	for (const auto& pair : itemFreqMap) {
		outFile << pair.first << " " << pair.second << endl;
	}

	outFile.close();
	cout << "Backup file frequency.dat created successfully." << endl;
}
	


//Prints menu for user
void InventoryTracker::DisplayMenu() {
	cout << "Corner Grocer Item Tracker" << endl;
	cout << "Enter menu choice 1-4" << endl;
	cout << "Option 1: Prints number of times a specific item is in the system" << endl;
	cout << "Option 2: Prints all items with the corresponding frequency of the each item" << endl;
	cout << "Option 3: Prints all items with the corresponding frequency in the form of a histogram" << endl;
	cout << "Option 4: EXITS THE PROGRAM\n" << endl; 
}

//Gets user's menu option
int InventoryTracker::GetMenuChoice() const {
	return menuChoice;

}
//Sets menu option and checks for valid option
void InventoryTracker::SetMenuChoice(int userMenuChoice) {
	while (userMenuChoice < 1 || userMenuChoice > 4) {
		cout << "Please enter a correct option." << endl;
		cout << "The options are number 1 through 4 " << endl;
		cout << "Please Try Again: ";
		cin >> userMenuChoice;
	}
	menuChoice = userMenuChoice; 
	}

string InventoryTracker::GetItemName() const {
	return itemName;
}

void InventoryTracker::SetItemName(const std::string& userItemName) {

	itemName = userItemName;
}

void InventoryTracker::SetWordFrequency() {
	wordFreq = 0;
	inFS.clear();
	inFS.seekg(0, std::ios::beg);
	while (!inFS.eof()) {
		inFS >> currWord;
		if (!inFS.fail()) {
			if (currWord == itemName) {
				++wordFreq;
			}
		}
	}
}

int InventoryTracker::GetWordFrequency() const {
	return wordFreq;
}

//Prints all items from a file and how many times they appear
void InventoryTracker::PrintAllItems() {
	string word;
	itemFreqMap.clear(); 
	inFS.clear();
	inFS.seekg(0, std::ios::beg);
	while (!inFS.eof()) {
		inFS >> word;
		if (!inFS.fail()) {
			itemFreqMap[word]++;
			}
		}
	cout << "Item Frequencies: " << endl;
	for (const auto& pair : itemFreqMap) {
		cout << pair.first << " " << pair.second << endl;
	}
}
//Prints all items from a file and prints the frequency in a histogram format
void InventoryTracker::PrintHistogram() {
	string word;
	itemFreqMap.clear(); 
	inFS.clear();
	inFS.seekg(0, std::ios::beg);
	while (!inFS.eof()) {
		inFS >> word;
		if (!inFS.fail()) {
			itemFreqMap[word]++;
		}
	}
	cout << "Item Frequency Histogram: " << endl;

	for (const auto& pair : itemFreqMap) {
		cout << pair.first << " ";
		for (int i = 0; i < pair.second; ++i) {
			cout << "$";
		}
		cout << endl;
	}
}
