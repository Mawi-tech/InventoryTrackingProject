/*Marshon Hughes 
12/15/2024
Mod 7 Project: Inventory Tracking*/


/*four different menu options
Option 1: 
	1: User Input of item/word looking for
	2: return # of times the word shows up
Option 2:
	1: Print list with numbers that represent frequency of all items purchased
Option 3:
	1: Print list with numbers that list the number of times all items was purchased
			EX: Potatoes 4
				Pumpkins 5
	****INPUT FILE is CS210_Project_Three_Input_File.txt
Option 4: Exits Program
*/

#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include "InventoryTracker.h"
using namespace std; 

int main() {
	int userMenuChoice;
	string userItemName;
	ifstream inFS; //Input filestream

	


	//Creating object inventory Tracker 
	//NEED VECTOR/ARRAY TO STORE ITEMS FROM FILE
	InventoryTracker inventoryTracker;
	
	//Opening file and making sure it can be opened and backing up the data in a backup file
	inventoryTracker.OpenAndReadFile();
	inventoryTracker.CreateBackupFile();

	InventoryTracker::DisplayMenu();
	cin >> userMenuChoice;
	inventoryTracker.SetMenuChoice(userMenuChoice);
	cout << "You chose: " << inventoryTracker.GetMenuChoice() << endl;

	
	switch (inventoryTracker.GetMenuChoice()) {
		case 1: 
			//Printing out the number of time an item appears in the list
			cout << "Option 1: Returns the frequency of an item" << endl;
			cout << "Enter the item you would like to search for: ";
			cin >> userItemName;
			inventoryTracker.SetItemName(userItemName);
			cout << "You entered: " << inventoryTracker.GetItemName() << endl; 
			inventoryTracker.SetWordFrequency();
			cout << inventoryTracker.GetItemName() << " appears " << inventoryTracker.GetWordFrequency() << " times." << endl;
			break;

		case 2:
			cout << "Option 2: Prints list of all items with the number of times it appears. " << endl;
			inventoryTracker.PrintAllItems();
			break;

		case 3:
			cout << "Option 3: Prints list of all items with the number of times it appears in a histogram";
			inventoryTracker.PrintHistogram();
			break;
		case 4:
			inFS.close();
			cout << "Exiting the program...";
			exit(0);

		default:
			cout << "Invalid choice." << endl;
			break;


	}
	inFS.close();
	
	return 0;
}