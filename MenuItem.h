//  Student:    Noah Khan
//  netID:      nzk180000
//  Course:     CS 1337.006.S21

#ifndef MENUITEM_H
#define MENUITEM_H

#include <iostream>
#include <string>

using namespace std;

class MenuItem {
public:
    MenuItem(); //default constructor
    MenuItem(string itemCode, string name, double price);
    
    string getCode();
    string getName();
    double getPrice();
    
    string setName();
    
    friend ostream& operator<< (ostream& stream, const MenuItem& mi);
    friend istream& operator>> (istream& stream, MenuItem& mi);


    
private:
    string itemCode;    //the itemCode for a dish
    string name;        //the name of the dish
    double price;       //the price for the dish
};


#endif /* MenuItem_h */
