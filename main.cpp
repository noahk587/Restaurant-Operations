//  Student:    Noah Khan
//  netID:      nzk180000
//  Course:     CS 1337.006.S21


#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include "MenuItem.h"
#include "Table.h"
#include "Order.h"
#include "Menu.h"

using namespace::std;

Table **tables; //dynamic array of tables
int tableCount = 0; //stores the number of tables in a resturant

/**
 This method will load the table information from the file.
 
 @par fileName The file that contains the table and menu information.
 */
void loadTables(string fileName){
    ifstream finput(fileName); //open the source file
    int filePointer = 0; //stores the value of the file pointer
    finput.seekg(filePointer, finput.beg);
    
    char fileIndex = 'n'; //stoe the context of the file positsion
    finput.get(fileIndex); //get the index value of the posistion of the file
    
    //move the file pointer
    while (fileIndex != '#') { //loop that will continue to move the file pointer until the the table header is read
        filePointer++; // increase the file pointer value
        finput.seekg(filePointer, finput.beg); //read the pointer information
        finput.get(fileIndex); //get the index value of the posistion of the file
    }
    while (fileIndex != '\n') { //loop that will backtrack to the table count
        filePointer--; // decrease the file pointer value
        finput.seekg(filePointer, finput.beg); //read the pointer information
        finput.get(fileIndex); //get the index value of the posistion of the file
    }
    finput >> tableCount; //get the number of tables from the file
    tables = new Table* [tableCount]; // an array that will hold table information
    
    // advance the pointer to prevent the pointer getting stuck at table counts
    filePointer++;
    finput.seekg(filePointer, finput.beg);
    finput.get(fileIndex);
    
    while (fileIndex != '\n') { //loop that will  move pointer to the table list
        filePointer++; // increase the file pointer value
        finput.seekg(filePointer, finput.beg); //read the pointer information
        finput.get(fileIndex); //get the index value of the posistion of the file
    }
    int tableNumber, tableCapacity; // holds the table number and the size
    
    for (int i = 0; i < tableCount; i++) { //loop through the list of tables
        finput >> tableNumber >> tableCapacity; // read the table information from the file
        tables[i] = new Table(tableNumber, tableCapacity); // transfer information into the table array
    }
}

/**
 This method will attempt to seat the party.
 
 @par tableNumber The table number the party will sit at
 @par command The program option the user selected
 */
void SeatParty(string tableNumber, string command){
    string input; //stores the party number the user entered
    int partySize; //stores the party size
    for (int i = 1; i < command.size(); i++) { //loop to help convert string to int
        input = input + command.at(i);
    }
    partySize = stoi(input); //convert the party size string into an int
    int tblNumber = stoi(tableNumber); //convert the table number into an int
    for (int i = 0; i < tableCount; i++) { //go through the list of tables to find desired table
        if (tables[i]->getTableNumber() == tblNumber) { // the table number is found
            tables[i]->seatParty(partySize); // attempt to seat party
            return;
        }
    }
}

/**
 This method will place orders for tables.
 
 @par tableNumber The table number the party will sit at
 @par menu The menu from the resturant
 */
void placeOrder(string tableNumber, Menu menu){
    string order;
    getline(cin, order); //user enter the order
    int tblNumber = stoi(tableNumber); //convert the table number into an int
    for (int i = 0; i < tableCount; i++) { //go through the list of tables to find desired table
        if (tables[i]->getTableNumber() == tblNumber) { // the table number is found
            tables[i]->processOrder(order, menu, tblNumber); // attempt to seat party
            return;
        }
    }
}

/**
 This method will serve food for tables.
 
 @par tableNumber The table number the party will sit at
 */
void serveFood(string tableNumber){
    int tblNumber = stoi(tableNumber); //convert the table number into an int
    for (int i = 0; i < tableCount; i++) { //go through the list of tables to find desired table
        if (tables[i]->getTableNumber() == tblNumber) { // the table number is found
            tables[i]->serve(tblNumber); // attempt to seat party
            return;
        }
    }
}
/**
 This method table will close the tab for tables.
 
 @par tableNumber The table number the party will sit at
 */
void closeTable(string tableNumber){
    int tblNumber = stoi(tableNumber); //convert the table number into an int
    for (int i = 0; i < tableCount; i++) { //go through the list of tables to find desired table
        if (tables[i]->getTableNumber() == tblNumber) { // the table number is found
            tables[i]->closeTable(tblNumber); // attempt to seat party
            return;
        }
    }
}

int main() {
    
    string tableNumber; //stores the table number user wants to edit. If the variable holds 'C', the program will terminate
    string command; //stores the command the user wants to perform for the table
    string fileName; //stores the name of the config file
    
    cout << "Enter input config filename: ";
    cin >> fileName;    //user enters the file name

    loadTables(fileName); //form a table array that contains table information

  
    Menu resturant(fileName); //seat up the menu
    
    
    cin >> tableNumber >> command;
    while(tableNumber != "C"){
        if (command.at(0) == 'P') {
            SeatParty(tableNumber, command);
        }
        else if(command.at(0) == 'O'){
            placeOrder(tableNumber, resturant);
        }
        else if (command.at(0) == 'S'){
            serveFood(tableNumber);
        }
        else if (command.at(0) == 'C'){
            closeTable(tableNumber);
        }
        cin >> tableNumber;
        if (tableNumber.at(0) == 'C') {
            delete [] tables;
            return 0;
        }
        cin >> command;
    }

    return 0;
}
