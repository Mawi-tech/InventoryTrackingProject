#pragma once

#ifndef InventoryTracker_H
#define InventoryTracker_H
#include <string>
#include <cstring>
#include <fstream>
#include <map>
class InventoryTracker {
	public:
		void OpenAndReadFile();
		void CreateBackupFile();
		void static DisplayMenu();
		int GetMenuChoice() const;
		void SetMenuChoice(int menuChoice);
		std::string GetItemName() const;
		void SetItemName(const std::string& itemName);
		int GetWordFrequency() const;
		void SetWordFrequency(); 
		void PrintAllItems();
		void PrintHistogram();
		
		
	private: 
		std::ifstream inFS;
		int menuChoice;
		int userMenuChoice;
		std::string itemName;
		std::string userItemName;
		std::string currWord;
		int wordFreq;
		std::map<std::string, int> itemFreqMap;
};



#endif