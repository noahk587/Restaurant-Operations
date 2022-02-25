//  Student:    Noah Khan
//  netID:      nzk180000
//  Course:     CS 1337.006.S21

/**
 The Menu class stores information about
 a menu for a resturant.
 */

#include "Menu.h"

/**
 This constructor initalizes a menu object that takes the infromation
 from a file.
 
 @par filename The name of the .txt file.
 */
Menu::Menu(string filename){
    ifstream finput(filename);
    
    numItems = 0;   //store the num of items on the menu
    finput >> numItems; //get the number of items on the menu
    
    //reset the file pointer
    int filePointer = 0; //stores the value of the file pointer
    finput.clear();
    finput.seekg(filePointer, finput.beg);
    
    char fileIndex = 'n'; //stoe the context of the file positsion
    finput.get(fileIndex); //get the index value of the posistion of the file
    
    //move the file pointer
    while (fileIndex != '\n') { //loop that will continue to move the file pointer until the menu starts
        filePointer++; // increase the file pointer value
        finput.seekg(filePointer, finput.beg); //read the pointer information
        finput.get(fileIndex); //get the index value of the posistion of the file
    }
    
    //allocate the memory to hold that many pointers
    menuItems = new MenuItem* [numItems];
    
    //read the menu from the .txt file
    for (int i = 0; i < numItems; i++) {
        menuItems[i] = new MenuItem();  //allocate a new menu item
        finput >> *menuItems[i];    //assign the information into the item structure
    }
    
}

/**
 This method returns the number of items on the menu.
 
 @return numItems The number of items on the menu.
 */
int Menu::getNumItems(){
    return numItems;
}

/**
 This mehtod returns the item code of the dish from
 the menu.
 
 @return menuItems[item]->getCode()  The item code of the dish from the menu
 */
string Menu::getCode(int index){
    return menuItems[index]->getCode();
}

/**
 This method returns the name of the dish from the menu.
 
 @return menuItems[index]->getName()  The name of the dish from the menu.
 */
string Menu::getName(int index){
    return menuItems[index]->getName();
}

/**
 This method returns the price of the dish from the menu.
 
 @return menuItems[index]->getPrice() The price of the dish from the menu.
 */
double Menu::getPrice(int index){
    return menuItems[index]->getPrice();
}
