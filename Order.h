//  Student:    Noah Khan
//  netID:      nzk180000
//  Course:     CS 1337.006.S21

#ifndef ORDER_H
#define ORDER_H

#include <iostream>
#include <string>
#include "Menu.h"

using namespace std;

class Order
{
public:
    Order(string orderString, const Menu &menu);
    string getCode();
    string getName();
    double getPrice();


    
private:
    int numItems;       //stores the number of items to order
    MenuItem **items;   //stores the menu to order from
    string itemCode;    //stores the item code of the dish
    string name;        //stores the name of the dish
    double price;       //stores the price for the dish
};

#endif /* Order_h */
