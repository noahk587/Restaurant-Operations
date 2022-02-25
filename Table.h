//  Student:    Noah Khan
//  netID:      nzk180000
//  Course:     CS 1337.006.S21

#ifndef TABLE_H
#define TABLE_H

#include <fstream>
#include <iomanip>
#include "Order.h"

using namespace std;

enum TableStatus {IDLE, SEATED, ORDERED, SERVED}; //the options for the status of a table at a resturant


class Table
{
public:
    Table();
    Table(int tblNumber, int mseats);
    
    //getters
    int getTableNumber();
    int getMaxSeats();
    int getOrderCount(int orders);
    TableStatus getTableStatus();
    
    bool seatParty(int numPeople); //return false if the table is NOT empty OR num # of people is > maxSeats
        //for both new order from the table OR additional order
    bool processOrder(string orderString, const Menu &menu, int tblNumber);
    bool serve(int tblNumber); //ORDERED --> SERVED;
    bool closeTable(int tblNumber); // print receipt then SERVED --> IDLE.

    
protected:
    
private:
    int tableNumber;    //the table number at the resturant
    int maxSeats; //max # of seats in this table
    TableStatus status; //the status of the table
    int numParty; //number of people seated at this table
    Order **order; //points to menu items that the table has ordered

    
};

#endif /* Table_h */
