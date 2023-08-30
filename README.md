# 10.15 Restaurant Operations  

Designed in CS 1337.006.S21 using the C++ programming language. The IDE used was Xcode and compiler was Clang. The program is also compatible with GNU Compiler Collection (GCC). Program reads the menu and table information from a .txt file. Program is run in a hostess/waiter’s perspective. User assign guests into tables, place orders, and calculate the bill for the table. Program does have input validation for restaurant operations. The program requires the filename entered is correct, otherwise you need to terminate the program and recompile. Code has modifation which includes a user prompt which wasn't included in the assignment submission.  


## Instructions
This assignment mimics the configuration and activities happen at a typical restaurant. Configuration data is in config.txt. Configuration file contains the table information & the full menu list.   We will use the following classes to complete this assignment. Feel free to add more variables if needed. Avoid making drastic changes to existing variables. You need to define the classes and implement all the .cpp/.h files including class implementation and the overall application functionality.
Read the configuration file and create the necessary objects / array of objects, then proceed to read the activities from the user and process them one at a time. Do not use any advanced data structures (STLs like vectors) that have not been covered in the class.   Sample configuration file (config.txt)

---

16 Menu: Listing of the full menu: item code, name, price 

A1 Bruschetta 5.29

A2 Caprese_Flatbread 6.10

A3 Artichoke-Spinach_Dip 3.99

A4 Lasagna_Fritta 4.99

A5 Mozzarella_Fonduta 5.99

E1 Lasagna_Classico 6.99

E2 Capellini_Pomodoro 7.99

E3 Eggplant_Parmigiana 8.99

E4 Fettuccine_Alfredo 7.49

E5 Tour_of_Italy 14.99

D1 Tiramisu 2.99

D2 Zeppoli 2.49

D3 Dolcini 3.49

S1 Soda 1.99

S2 Bella_Limonata 0.99

S3 Berry_Acqua_Fresca 2.88


19 Tables:  table #, max seats

1 2

2 4 

3 2 

4 2 

5 2 

6 4 

7 6 

8 10 

9 2 

10 4 

11 4 

12 4 

13 4 

14 2 

15 2 

16 2 

17 2 

18 2

50 20

---

Here is some sample input & output to capture the functionality of the program:

---
1 P2

Party of 2 assigned to Table 1

2 P10

Sorry, max 4 seats in Table 2!

2 P4

Party of 4 assigned to Table 2

1 O A1 A1 B1

No item with code B1

2 items ordered for Table 1

1 P1

Table 1 already occupied!

8 P10

Party of 10 assigned to Table 8

1 C

Food not served for Table 1 yet!

2 S

Order not placed at Table 2 yet!

1 S

Food served in table 1

1 O E1 E2 D1

3 additional items ordered for Table 1

3 P2

Party of 2 assigned to Table 3

1 S

Food served in table 1

1 C

Table 1 is closed. Here is the bill.

Receipt Table# 1 Party 2

A1         Bruschetta   5.29

A2         Bruschetta   5.29

E1   Lasagna_Classico   6.99

E2 Capellini_Pomodoro   7.99

D1           Tiramisu   2.99

                Total  28.55

5 P2

Party of 2 assigned to table 5

1 P1

Party of 1 assigned to table 1

C    (cannot be read as number - close the program!)

---
 
As you can see in the sample input & output, you should recognize the error conditions and output them.
* Do not allow orders from table with no party assigned to it.
* Do not allow assigning new party to a table when another party is already there.
* Do not allow check-out from empty table or a table in which food has not been served.
* Do not allow delivery of food to an empty table!
* Do not assign a party to a table with insufficient # of chairs.
* Output error message if the menu item code in the order string is not found.
