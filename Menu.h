//  Student:    Noah Khan
//  netID:      nzk180000
//  Course:     CS 1337.006.S21

#ifndef MENU_H
#define MENU_H

#include "MenuItem.h"
#include <fstream>
#include <iomanip>

using namespace std;

class Menu
{
public:
    Menu(string filename);
    int getNumItems();
    string getCode(int index);
    string getName(int index);
    double getPrice(int index);
    
protected:
    
private:
    int numItems;           //stores the number of items on the menu
    MenuItem **menuItems;   //stores the resturant menu
};
#endif /* Menu_h */
