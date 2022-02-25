//  Student:    Noah Khan
//  netID:      nzk180000
//  Course:     CS 1337.006.S21

/**
 The MenuItem class stores information about the
 items on the menu.
 */

#include <stdio.h>
#include "MenuItem.h"

/**
 This constructor initalizes a MenuItem object by taking
 the item code, the name of the dish, and the price.
 
 @par itemCode The item code for the dish.
 @par name The name of the dish.
 @par price The price for the dish.
 */
MenuItem::MenuItem()
{
    itemCode = "";
    name = "";
    price = 0.00;
}

/**
 The method sets the information for the menu item object.
 
 @par itemCode The item code for the dish.
 @par name The name of the dish.
 @par price The price for the dish.
 */
MenuItem::MenuItem(string itemCode, string name, double price){
    this->itemCode = itemCode;
    this->name = name;
    this->price = price;
}

/**
 This method returns the item code for the dish.
 
 @return itemCode The item code for the dish
 */
string MenuItem::getCode(){
    return itemCode;
}

/**
 This method returns the name of the dish
 
 @par name The name of the dish.
 */
string MenuItem::getName(){
    return name;
}


/**
 This method returns the price for the dish
 
 @return price The price of the dish
 */
double MenuItem::getPrice(){
    return price;
}

/**
 This method overloads the << operator to print out menu information.
 */
ostream& operator<< (ostream& stream, const MenuItem& mi){
    stream << mi.itemCode << " " << mi.name << " " << mi.price << endl; //print the menu item
    return stream;
}

/**
 This method overloads the >> operator to read infromation from the .txt fiel
 */
istream& operator>> (istream& stream, MenuItem& mi){
    stream >> mi.itemCode >> mi.name >> mi.price;
    return stream;
}
