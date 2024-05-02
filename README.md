// Contuning the Program 1.


----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
Improving the Movie Theater Simulation
The drive-in theater for Radiator Springs has been a huge hit! With all the new traffic from Route 66, we need to improve the program to handle some more use cases. This program is a continuation of Program 1.



Part 1: Theater Information from a File (10 points)

Previously, the program had the user input the name of the theater, the number of screens, and the parking spots available for each screen. Since the program is being run more frequently, Fillmore suggests that we replace the user input component with reading in the theater information from a file.  

First, the program should ask the user to enter a file to read. The program should keep prompting the user for a new filepath until a provided one exists OR they type "exit". If they type exit, the program should exit immediately.

Note: A valid filepath must have no spaces and contain the .txt extension. 

Code Block 7.3.1: File Processing Prompt
Starting movie theater simulation

Please enter theater file path: Hello
Please enter a valid file path

Please enter theater file path: theater. txt
Please enter a valid file path

Please enter theater file path: theater.txt
theater.txt does not exist

Please enter theater file path: part_two_theater.txt
Reading part_two_theater.txt
Once the user has entered a vaild theater file, the program should open the file and process the information into a theater structure. Below is an example of what a theater file should contain. 

Note: The comments will not be in the text file provided, there are just here to provide clarity. Additionally, you do not need to worry about theater files critical missing information.

Code Block 7.3.2: part_two_theater.txt
Route 66 Theater  // Theater Name
2                 // Number of screens
30                // Number of parking spots per screen
10.99             // Adult Ticket Price
8.99              // Senior Ticket Price
6.99              // Child Ticket Price
5.99              // Member Ticket Price
6.00              // Membership Fee
Part 2: Sentinel Controlled Loop (5 points)

Fillmore wants create an interactive menu kiosik. First, we need to create a sentinel controlled loop which executes AT LEAST once and exits when the user provides a -1 input. Your loop should display the following menu each time the menu loop is executed.

Code Block 7.3.3: User Menu Display
Menu
*****************************
1. Display theater information
2. Display now showing
3. Run price simulation
4. Buy tickets
5. Admin menu
-1. Exit program
*****************************

Enter choice: 
Part 3: Creating User Menu Options (45 points)

Now that we have created the menu loop, it's time to handle different user menu options. 

* Option 1: Display Theater Information (5 points) -  When the user enters 1, your program should display the theater information provided by the file. This theater information display should be in the exact same format as program 1.

* Option 2: Display Movies Now Showing (5 points) - When the user enters 2, your program should display the movies the theater is now showing. This now showing display is the exact same as program 1.

* Option 3: Run Simulation (5 points) - When the user enters 3, your program should run the price simulation from program 1 using the prices provided from the file.  

* Option 4: Buy Tickets (25 points) -  When the user enters 4, the program should begin the ticket buying process. First, the program should ask the user to enter their name. Once getting their name, the program should check if that name exists in the "members.txt" file. If "members.txt" file does not already exist, your program should create it when recording a new member.

Rewards Members: If the user exist in "members.txt", then the program should print "Welcome" followed by their name. Then, the program should continue the ticket process as if they were members. They should not be charged the membership fee again. 

Non Members: If the user does not exist in "members.txt", the program should ask them if they would like to become rewards member. The program should accept both uppercase and lowercase 'y'. Every other input is treated as 'n'. You can assume the user will always input valid numbers for number of tickets.

If the user says yes, their name should be added to members.txt on a seperate line and the program should continue the ticket process as if they were members.

If the user says no, the program should use the normal ticket purchase options with adults, seniors, and kids.

Below is an example of what a members.txt file might look like and some ticket purchasing examples.

Code Block 7.3.4: members.txt Example
Lightning McQueen
Sally
Code Block 7.3.5: Ticket Purchasing Examples
Menu
*****************************
1. Display theater information
2. Display now showing
3. Run price simulation
4. Buy tickets
5. Admin menu
-1. Exit program
*****************************

Enter choice: 4

Buying Tickets
*****************************
Enter your name: Mater
Do you want to become a member(Y/N)?: Y
# of member tickets: 2

Total Price: $19.42
*****************************

Menu
*****************************
1. Display theater information
2. Display now showing
3. Run price simulation
4. Buy tickets
5. Admin menu
-1. Exit program
*****************************

Enter choice: 4

Buying Tickets
*****************************
Enter your name: Mater           
Welcome Mater
# of member tickets: 2

Total Price: $12.94
*****************************

Menu
*****************************
1. Display theater information
2. Display now showing
3. Run price simulation
4. Buy tickets
5. Admin menu
-1. Exit program
*****************************

Enter choice: 4

Buying Tickets
*****************************
Enter your name: Flo
Do you want to become a member(Y/N)?: N
# of adult tickets: 1
# of senior tickets: 0
# of child tickets: 1

Total Price: $19.42
*****************************

Menu
*****************************
1. Display theater information
2. Display now showing
3. Run price simulation
4. Buy tickets
5. Admin menu
-1. Exit program
*****************************
Option 5: Access Admin Options (5 points) - When the user enters 5, your program should prompt the user to input an admin password. For this program, we can assume the default password is set to "cars" when first starting the program. If the user enters the proper password, the user will be given access to an admin menu which we will create in parts 4 and 5 below. If the user enters the incorrect password, the program should display "Incorrect password." and display the menu again. 

Additionally, if the user incorrectly enters the admin password more than 3 times, the program should exit with the message "Closing program due to excess password attempts.". The program should restart this counter every time the user successfully enters the admin password.  

Part 4: Creating Admin Menu (5 points)

Repeat the process from Part 2 given the following admin menu options.

Code Block 7.3.6: Admin Menu
Admin Menu
*****************************
1. Update theater information
2. Display total sales
3. Reset membership file
4. Update admin password
-1. Exit admin menu
*****************************
Part 5: Creating Admin Menu Options (25 points)

Now that we have created our menu loop, it's time to handle the different admin menu options. 

* Option 1: Update Theater Information (05 points) -  When the user enters 1, your program should prompt the user for a new theater file and update the theater information accordingly. However, if the file does not exist, your program should default back to the current theater file's information. 

* Option 2: Display Total Sales (05 points) - When the user enters 2, your program should display the total amount of money you have made from ticket sales at this point.

* Option 3: Clear Current Members (05 points) - When the user enters 3, your program should reset the "members.txt" file.

* Option 4: Change Password (10 points) - When the user enters 4, your program should prompt the user for a new admin password. Once given a new password, the admin password should be updated accordingly. Afterward, the user should be returned to the original menu. This means next time the user is prompted for the admin password, they will need to.

Code Block 7.3.7: Admin Access
Menu
*****************************
1. Display theater information
2. Display now showing
3. Run price simulation
4. Buy tickets
5. Admin menu
-1. Exit program
*****************************

Enter choice: 5
Enter admin password: hello
Incorrect password.

Menu
*****************************
1. Display theater information
2. Display now showing
3. Run price simulation
4. Buy tickets
5. Admin menu
-1. Exit program
*****************************

Enter choice: 5
Enter admin password: cars
Admin access granted

Admin Menu
*****************************
1. Update theater information
2. Display total sales
3. Reset membership file
4. Update admin password
-1. Exit admin menu
*****************************
Part 6: Documenting the Code and Following Programming Standards (10 points)

Finally, now that you are done with the code you need to properly document how it works. Add the program header below and replace its information with information relevant to the program. Make sure to follow the programming standards document on Canvas. 

Code Block 7.3.8: Example Program Header
/*********************************************************************
File name: example.cpp
Author: <Your Name Here>(<netID>)
Date: XX/XX/XXXX

Purpose:
    Description of the purpose of the program.
Command Parameters:
    -
Input:
    Description of the input to the program.
Results:
    Description of what the program produces.
Notes:
    Description of any special information regarding this program.
*********************************************************************/
Program Requirements and Tips:

* Your program MUST follow the C++ Standards Document provided on CANVAS.

* Your program MUST compile for you to get credit.

* Your program MUST close any files it opens.

* Your program MUST NOT use any vectors. 

* Your program should match the provided program output. 

* Your program should use the appropriate datatypes for each variable. 

* Any output which uses money should have a $ and  should be properly rounded to the nearest hundredth place (or cent).

* Use the provided szBreakMessage variable to print out the stars shown in the program.

* Remember to clear the buffer when switching between cin and getline.
