//  Student:    Noah Khan
//  netID:      nzk180000
//  Course:     CS 1337.006.S21

/**
 The order class stores information about the food order
 for a table.
 */

#include "Order.h"

/**
 This constructor initalizes an Order object by taking in the table order and
 the resturant menu.
 
 @par orderString The order the table placed
 @par menu The menu of the resturant
 */
Order::Order(string orderString, const Menu &menu){
    Menu resturant = menu;
    numItems = resturant.getNumItems();
    
    for (int i = 0; i < numItems; i++) { //a loop that goes through the menu to make sure if the food requested is on the menu
        if (orderString == resturant.getCode(i)) { //if food is on the menu, add the item to the list
            itemCode = orderString;
            name = resturant.getName(i);
            price = resturant.getPrice(i);
            break;
        }
        else if (i == (numItems)-1){ //food is not on the menu
            cout << "No item with code " << orderString << endl;
            itemCode = "0";
            name = "";
            price = 0;
        }
    }
}

/**
 This method returns the item code for the dish ordered.
 
 @return itemCode The item code for the dish ordered.
 */
string Order::getCode(){
    return itemCode;
}

/**
 This method returns the name of the dish ordered.
 
 @return name The name of the dish ordered.
 */
string Order::getName(){
    return name;
}

/**
 This method returns the price of the dish ordered.
 
 @return price The price of the dish ordered.
 */
double Order::getPrice(){
    return price;
}
