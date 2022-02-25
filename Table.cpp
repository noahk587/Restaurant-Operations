//  Student:    Noah Khan
//  netID:      nzk180000
//  Course:     CS 1337.006.S21

/**
 The Table class stores infromation about a table and it's status
 at a resturant.
 */

#include "Table.h"

/**
 This constructor initalizes an Table object with it's default information
 */
Table::Table()
{
    tableNumber = 0;
    maxSeats = 0;
    status = IDLE;
    numParty = 0;
}

/**
 This constructor initalizes an Table object by taking the table number and
 capacity.
 
 @par tbleNumber The table number at the resturant
 @par mseat The table's seating capacity.
 */
Table::Table(int tblNumber, int mseats)
{
    tableNumber = tblNumber;
    maxSeats = mseats;
    status = IDLE;  //when the file is loaded, there no one at the table
    numParty = 0;
}

/**
 This method returns the table number
 
 @return tableNumber The table number of the table.
 */
int Table::getTableNumber(){
    return tableNumber;
}

/**
 This method returns the seating capacity of the table.
 
 @return maxSeats The maximum seating capacitty of the table.
 */
int Table::getMaxSeats(){
    return maxSeats;
}

/**
 This mehtod returns the status of the table.
 
 @return status The status of the table.
 */
TableStatus Table::getTableStatus(){
    return status;
}

/**
 This method seats a party to a table and returns if the request was successful.
 
 @return true If the party was seated at the table.
 @return false If the party is not able to be seated.
 */
bool Table::seatParty(int numPeople){
    if (numPeople <= maxSeats && status == IDLE) { //checks if the party can be accomindated at the table and the table is open
        status = SEATED; //table is now seeated
        numParty = numPeople; //assign the party size to numParty
        cout << "Party of " << numPeople << " assigned to table " << tableNumber << endl; //user prompt
        return true;
    }
    if (status != IDLE) { //the table is not open
        cout << "Table " << tableNumber << " already occupied!" << endl;
        return false;
    }
    cout << "Sorry, max " << maxSeats << " seats in Table " << tableNumber << "!"<< endl; //table capacity is too small
    return false;
}

int orderCount = 0; //global variable that stores the number of orders for the table

/**
 This method process the orders for the table.
 
 @return true If food is ordered for the table.
 @return false If food can't be order for the table.
 */
bool Table::processOrder(string orderString, const Menu &menu, int tblNumber){
    if (status == IDLE || status == ORDERED) { //the table is empty or food is already ordered
        return false;
    } 
    
    if(status == SEATED){ //checks if table is ready to order
    for (int i = 0; i < orderString.size(); i++) { //split the string to count orders requested
        if (isalpha(orderString.at(i)) ) { //each order has a space in between
                orderCount++;
            }
        }
    
    order = new Order*[orderCount]; //order array of customer orders
    int itemsProcessed = 0; //number of orders process
    
    int arrayIndex = 0; //stores the index of the array
    string individualOrder = ""; //stores the split string of the order
    
   for (int i = 0; i < orderString.size(); i++) {
        // assign each order to new order
       if (isalpha(orderString.at(i))) {
           individualOrder = orderString.at(i);
           individualOrder = individualOrder + orderString.at(i+1);
           order[arrayIndex] = new Order(individualOrder, menu);
           if (order[arrayIndex]->getCode() != "0") { //if item is on the menu
               itemsProcessed++; //count the orders processed
           }
           arrayIndex++;
       }
       
    }
    
    cout << itemsProcessed << " items ordered for Table " << tblNumber << endl; //message regarding the number of orders processed
    
    status = ORDERED; //change the table status to ordered
    }
    else{ //ordering additional items
        int initalOrderCount = orderCount;
        for (int i = 0; i < orderString.size(); i++) { //split the string to count orders requested
            if (isalpha(orderString.at(i)) ) { //each order has a space in between
                orderCount++;
                }
            }
        Order **tempArray; //temp order array to help make order table bigger
        tempArray = new Order* [initalOrderCount];
        for (int i = 0; i < initalOrderCount; i++) {
            tempArray[i] = order[i]; //copy information from first array
        }
        
        order = new Order*[orderCount]; //order array of customer orders
        int itemsProcessed = 0; //number of orders process
        
        int arrayIndex = initalOrderCount;
        string individualOrder = ""; //stores the split string of the order
        
        for (int i = 0; i < initalOrderCount; i++) {
            order[i] = tempArray[i];
        }
        
        for (int i = 0; i < orderString.size(); i++) { //a loop that goes through the orders
             // assign each order to new order
            if (isalpha(orderString.at(i))) {
                individualOrder = orderString.at(i);
                individualOrder = individualOrder + orderString.at(i+1);
                order[arrayIndex] = new Order(individualOrder, menu);
                if (order[arrayIndex]->getCode() != "0") { //if item is on the menu
                    itemsProcessed++; //count the orders processed
                }
                arrayIndex++;
            }
            
         }
        
        cout << itemsProcessed << " additional items ordered for Table " << tblNumber << endl; //message regarding the number of orders processed
        status = ORDERED; //change the table status to ordered
    }
    
    
    return true;
}

/**
 This method give the status if food was served for the table.
 
 @return true If food is served for the table.
 @return false If food is not served for the table.
 */
bool Table::serve(int tblNumber){
    if (status != ORDERED) { //if there was no order placed for the table
        cout << "Order not placed at Table " << tblNumber << " yet!" << endl; //error message
        return false;
    }
    cout << "Food served in table " << tblNumber << endl; //success message
    
    status = SERVED; //change table status to served
    
    return true;
}

/**
 This method closes the ticket for the table
 
 @return true If the ticket is closed for the table
 @return false If the ticket can't be closed for the table
 */
bool Table::closeTable(int tblNumber){
    if (status != SERVED) { //if table hasn't recieved their food
        cout << "Food not served for Table " << tblNumber << " yet!" << endl;
        return false;
    }
    cout << "Table " << tblNumber << " is closed. Here is the bill." << endl << endl;
    
    double tableTotal = 0;
    
    int maxLength = 0;
    for (int i = 0; i < orderCount; i++) { //a loop to set up the ticket
        if (order[i]->getCode() != "0") { //if item is on the menu
            tableTotal += order[i]->getPrice();
            string itemName = order[i]->getName();
            if (itemName.size() > maxLength) {
                maxLength = itemName.size();
            }
        }
    }
    
    //block of code that sets up the field for the ticket total
    string ticketTotal = to_string(tableTotal);
    string tabTotal = "";
    
    int string_index = 0;
    while (ticketTotal.at(string_index) != '.') {
        tabTotal+= ticketTotal.at(string_index);
        string_index++;
    }
    //end of block
    
    int price_Col_Width = string_index + 3; //stores the width of column for the ticket output
    
    cout << fixed << setprecision(2);
    cout << "Receipt Table# " << tblNumber << " Party " << numParty << endl;
    
    //block of code that prints out the ticket
    int appetizerCount = 1;
    int entreeCount = 1;
    int dessertCount = 1;
    
    
    for (int i = 0; i < orderCount; i++) {
        if (order[i]->getCode() != "0") { //if item is on the menu
            string itemCode = order[i]->getCode();
            string billCode = "";
            if (itemCode.at(0) == 'A') {
                billCode = billCode + itemCode.at(0);
                string countString = to_string(appetizerCount);
                billCode = billCode + countString;
                appetizerCount++;
            }
            else if (itemCode.at(0) == 'E') {
                billCode = billCode + itemCode.at(0);
                string countString = to_string(entreeCount);
                billCode = billCode + countString;
                entreeCount++;
            }
            else if (itemCode.at(0) == 'D') {
                billCode = billCode + itemCode.at(0);
                string countString = to_string(dessertCount);
                billCode = billCode + countString;
                dessertCount++;
            }
            
            cout << billCode << " ";
            cout.width(maxLength);
            cout << right << order[i]->getName();
            cout.width(price_Col_Width+2);
            cout << right << order[i]->getPrice() << endl;
        }
    }
    cout.width(maxLength + 3);
    cout << right << "Total";
    cout.width(price_Col_Width+2);
    cout << right << tableTotal << endl << endl;
    //end of block
    
    //reset the table
    status = IDLE;
    numParty = 0;
    
    //delete the order array
    delete [] order;
    return true;
}
