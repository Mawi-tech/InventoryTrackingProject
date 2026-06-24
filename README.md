# InventoryTrackingProject

## Overview
This project tracks inventory for a grocery store by reading item data from a text file and giving the user four ways to view it: searching for a specific item's frequency, printing every item alongside its frequency, displaying a histogram of item frequencies, or exiting the program.

## Approach
I focused on making sure the program correctly validated user input and handled each of the four menu options reliably. The inventory data is organized using object-oriented programming, with an inventoryTracker object keeping the file's contents structured so the program stays easy to maintain and adapt as requirements change.

## Reflection
The most challenging part of this project was managing variable types and pointers across different functions, since data wasn't always accessible where I needed it. I resolved these issues by researching documentation, including W3Schools, and working through each error systematically. One way I could enhance the program further is by breaking out more of its logic into dedicated functions, such as a separate function purely for opening and reading the file, which would reduce repeated code in the main program. The skills I built here, particularly reading, writing, and opening files, are transferable to many other programs, especially as more software relies on handling multiple files at once.

## Skills Demonstrated
- File I/O and text parsing
- Object-oriented programming
- Variable scope and pointer management
- Debugging and self-directed research
