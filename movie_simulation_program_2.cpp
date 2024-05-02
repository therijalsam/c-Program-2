/*********************************************************************
File name: movie_simulation_program_2.cpp
File:- part_two-theater.txt(given file to read the data)
File to store membership member:- members.txt (the file must be members.txt named)
File where we can update theater:- copy_theater.txt (we can use any file while testing)




Author: Samrakshan Rijal
Date: 03/29/2024

Purpose:
    This program is a simple theater management system that allows users to access various functionalities such as displaying theater information, listing currently showing movies, running price simulations, buying tickets, and accessing administrative options.

Command Parameters: 
    
    Procedure:-

    - At first, I didvided into ten different functions.
    - Created structure Theater
    -Checked for right file and its validity
    -Implemt switch statement for Menu panel
    -Did accordingly

Input:
    The program prompts the user for input through the console. It accepts input for menu choices, theater file path, user name for ticket purchase, admin password, new file paths for theater updates, and new admin passwords.

Results:
    - Display theater information: Prints details about the theater including name, number of screens, parking spots per screen, and ticket prices.
    - Display now showing: Lists the currently showing movies.
    - Run price simulation: Simulates ticket pricing based on the theater's settings.
    - Buy tickets: Allows users to purchase tickets, considering membership status and ticket prices.
    - Admin menu:
        1. Update theater information: Prompts the user for a new theater file and updates theater information accordingly.
        2. Display total sales: Prints the total amount of money made from ticket sales.
        3. Reset membership file: Clears the contents of the "members.txt" file.
        4. Change admin password: Prompts the user for a new admin password and updates it accordingly.

Notes:
    - This program assumes that the theater information is stored in a text file in a specific format.
    - It also relies on a membership file ("members.txt") to track theater members.
    - Error handling is minimal in this implementation and can be improved for robustness.
*********************************************************************/


#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <cmath>
#include <cctype>

using namespace std;

// Global constants for movie names so that i can assign these movies outside the function. I have also instalized inside main function.
const string szMovie1 = "Gone in 80 Seconds";
const string szMovie2 = "Guardians of the Ford Galaxy";
const string szMovie3 = "Marvel: The Dodge Avenger";

// Global constant value of sale tax.
const double dSALES_TAX = .08;

// Struct definition
struct Theater
{
    string szName;              // Name of the theater
    int iScreens;               // Number of screens
    int iParkingSpots;          // Number of spots for each screen
    double dAdultPrice;         // Ticket price for an adult
    double dSeniorPrice;        // Ticket price for a senior
    double dChildPrice;         // Ticket price for a child
    double dMembersPrice;       // Ticket price for theater members
    double dMembershipPrice;    // Theater membership fee
};

// Function prototypes
void displayMenu(const string& szBreakMessage);
void displayTheaterInformation(const Theater& theater, const string& szBreakMessage);
void displayNowShowing(const string& szBreakMessage);
void runPriceSimulation(const Theater& theater, const string& szBreakMessage);
void buyTickets(const Theater& theater, const string& szBreakMessage, double& totalSales);
void accessAdminOptions(string& szAdminPass, int& incorrectPasswordAttempts, Theater& theater, double& totalSales,const string& szBreakMessage);
void updateTheaterInformation(string& szFileName, Theater& theater);
void displayTotalSales(double totalSales);
void resetMembershipFile();
void changeAdminPassword(string& szAdminPass);

// Function to check if file exists
bool fileExists(const string& filename) {
    ifstream file(filename.c_str());
    return file.good();
}

// Function to process theater file and populate Theater struct
Theater processTheaterFile(const string& filename) {
    Theater theater;
    ifstream inFile(filename);
    if (!inFile) {
        cerr << "Error: Unable to open file: " << filename << endl;
        exit(EXIT_FAILURE);
    }

    // Read data from the file into theater structure
    getline(inFile, theater.szName);    // Read theater name
    inFile >> theater.iScreens;         // Read number of screens
    inFile >> theater.iParkingSpots;    // Read number of parking spots per screen
    inFile >> theater.dAdultPrice;      // Read adult ticket price
    inFile >> theater.dSeniorPrice;     // Read senior ticket price
    inFile >> theater.dChildPrice;      // Read child ticket price
    inFile >> theater.dMembersPrice;    // Read member ticket price
    inFile >> theater.dMembershipPrice; // Read membership fee

    inFile.close();
    return theater;
}

// Main function
int main() {
    cout << fixed << setprecision(2);

    // Create variables
    string szBreakMessage = "*****************************\n";
    string szAdminPass = "cars"; // initial password
    int incorrectPasswordAttempts = 0; // Counter for incorrect password attempts
    double totalSales = 0.0; // Initialize total sales
    
    // Read theater file path from user
    string szFileName;
    while (true) {
        cout << "Please enter theater file path: ";
        getline(cin, szFileName);

        if (szFileName == "exit") {
            cout << "Exiting program..." << endl;
            exit(EXIT_SUCCESS);
        }

        if (szFileName.find(' ') != string::npos || szFileName.substr(szFileName.find_last_of(".") + 1) != "txt") {
            cout << "Please enter a valid file path" << endl;
            cout << endl;
            continue;
        }

        if (!fileExists(szFileName)) {
            cout << szFileName << " does not exist" << endl;
            cout << endl;
            continue;
        }

        cout << "Reading " << szFileName << endl;
        break;
    }

    // Process the theater file and populate Theater structure
    Theater theater = processTheaterFile(szFileName);

    // Main menu loop
    while (true) {
        displayMenu(szBreakMessage);

        // User input for menu choice
        int choice;
        cout << "Enter choice: ";
        cin >> choice;
        // Clear input buffer
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        // Execute corresponding functionality based on user choice
        switch (choice) {
            case 1:
                displayTheaterInformation(theater, szBreakMessage);
                break;
            case 2:
                displayNowShowing(szBreakMessage);
                break;
            case 3:
                runPriceSimulation(theater, szBreakMessage);
                break;
            case 4:
                buyTickets(theater, szBreakMessage,totalSales);
                break;
            case 5:
                accessAdminOptions(szAdminPass, incorrectPasswordAttempts, theater, totalSales,szBreakMessage);
                break;
            case -1:
                cout << "Exiting program\n";
                return 0;
            default:
                cout << "Invalid choice. Please run the program again.\n";
                return 0; // returning 0 because there was no anything about invalid choice in zybooks
        }
    }

    return 0;
}

// Function to display the main menu
void displayMenu(const string& szBreakMessage) {
    cout << "\nMenu\n";
    cout << szBreakMessage;
    cout << "1. Display theater information\n";
    cout << "2. Display now showing\n";
    cout << "3. Run price simulation\n";
    cout << "4. Buy tickets\n";
    cout << "5. Admin menu\n";
    cout << "-1. Exit program\n";
    cout << szBreakMessage;
    cout << endl;
}

// Function to display theater information
void displayTheaterInformation(const Theater& theater, const string& szBreakMessage) {
    cout << "Theater Information:" << endl;
    cout << szBreakMessage;
    cout << "Name: " << theater.szName << endl;
    cout << "Number of Screens: " << theater.iScreens << endl;
    cout << "Number of Parking Spots per Screen: " << theater.iParkingSpots << endl;
    cout << szBreakMessage << endl;
}

// Function to display currently showing movies
void displayNowShowing(const string& szBreakMessage) {
    cout << "Now Showing" << endl;
    cout << szBreakMessage;
    cout << "Movie no. 1:- " << szMovie1 << endl;
    cout << "Movie no. 2:- " << szMovie2 << endl;
    cout << "Movie no. 3:- " << szMovie3 << endl;
    cout << szBreakMessage;
}

// Function to run price simulation
void runPriceSimulation(const Theater& theater, const string& szBreakMessage) {
    // scenario1
    cout << "Calculating Price Scenario 1" << endl;
    cout<<szBreakMessage;
    cout << "1 Adult, 1 child ticket before tax: $" << theater.dAdultPrice+ theater.dChildPrice << endl;
    cout<<"1 Adult, 1 child ticket after tax: $"<< ((theater.dAdultPrice+ theater.dChildPrice)*dSALES_TAX) + theater.dAdultPrice+ theater.dChildPrice<<endl;
    cout<<endl;
    cout<<"2 Member tickets before tax: $"<<2*theater.dMembersPrice<<endl;
    cout<<"2 Member tickets after tax: $"<<((2*theater.dMembersPrice)*dSALES_TAX)+2*theater.dMembersPrice<<endl;
    cout<<endl;
    cout<<"Price difference: $"<<abs((((theater.dAdultPrice+ theater.dChildPrice)*dSALES_TAX) + theater.dAdultPrice+ theater.dChildPrice)-(((2*theater.dMembersPrice)*dSALES_TAX)+2*theater.dMembersPrice)) <<endl;
    cout<<szBreakMessage;
    cout<<endl;
    cout<<endl;
    
    //scenario2
    cout << "Calculating Price Scenario 2" << endl;
    cout<<szBreakMessage;
    cout << "2 Adult tickets before tax: $" << theater.dAdultPrice*2 << endl;
    cout<<"2 Adult tickets after tax: $"<< ((theater.dAdultPrice*2)*dSALES_TAX) + theater.dAdultPrice*2<<endl;
    cout<<endl;
    cout<<"2 Member tickets before tax: $"<<2*theater.dMembersPrice<<endl;
    cout<<"2 Member tickets after tax: $"<<((2*theater.dMembersPrice)*dSALES_TAX)+2*theater.dMembersPrice<<endl;
    cout<<endl;
    cout<<"Price difference: $"<<abs((((theater.dAdultPrice*2)*dSALES_TAX) + theater.dAdultPrice*2)-(((2*theater.dMembersPrice)*dSALES_TAX)+2*theater.dMembersPrice)) <<endl;
    cout<<szBreakMessage;
    cout<<endl;
    cout<<endl;

    //scenario3

    cout << "Calculating Price Scenario 3" << endl;
    cout<<szBreakMessage;
    cout << "1 Adult, 1 senior, and 1 child ticket before tax: $" << theater.dAdultPrice+theater.dSeniorPrice+theater.dChildPrice << endl;
    cout<<"1 Adult, 1 senior, and 1 child ticket after tax: $"<< ((theater.dAdultPrice+theater.dSeniorPrice+theater.dChildPrice)*dSALES_TAX) + theater.dAdultPrice+theater.dSeniorPrice+theater.dChildPrice<<endl;
    cout<<endl;
    cout<<"3 Member tickets before tax: $"<<3*theater.dMembersPrice<<endl;
    cout<<"3 Member tickets after tax: $"<<((3*theater.dMembersPrice)*dSALES_TAX)+3*theater.dMembersPrice<<endl;
    cout<<endl;
    cout<<"Price difference: $"<<abs((((theater.dAdultPrice+theater.dSeniorPrice+theater.dChildPrice)*dSALES_TAX) + theater.dAdultPrice+theater.dSeniorPrice+theater.dChildPrice)-(((3*theater.dMembersPrice)*dSALES_TAX)+3*theater.dMembersPrice)) <<endl;
    cout<<szBreakMessage;
    cout<<endl;
    cout<<endl;
    
}

// Function to buy tickets
void buyTickets(const Theater& theater, const string& szBreakMessage, double& totalSales) {
    string name;
    cout << "Buying Tickets" << endl;
    cout << szBreakMessage;
    cout << "Enter your name: ";
    getline(cin, name);

    ifstream memberFile("members.txt");
    bool isMember = false;
    string line;
    while (getline(memberFile, line)) {
        if (line == name) {
            isMember = true;
            break;
        }
    }
    memberFile.close();

    if (isMember) {
        cout << "Welcome " << name << endl;
    } else {
        char response;
        cout << "Do you want to become a member (Y/N)?: ";
        cin >> response;
        cin.ignore(); // Clear input buffer

        if (toupper(response) == 'Y') {
            ofstream outFile("members.txt", ios::app);
            outFile << name << endl;
            outFile.close();
            isMember = true;
        }
    }

    int adultTickets, seniorTickets, childTickets;
    if (isMember) {
        cout << "# of member tickets: ";
        cin >> adultTickets;
    } else {
        cout << "# of adult tickets: ";
        cin >> adultTickets;
        cout << "# of senior tickets: ";
        cin >> seniorTickets;
        cout << "# of child tickets: ";
        cin >> childTickets;
    }

    double totalPrice;
    if (isMember) {
        double tp1 = adultTickets * theater.dMembersPrice;
        totalPrice = (tp1* dSALES_TAX)+tp1;
    } else {

          double ep1=adultTickets * theater.dAdultPrice;
          double ep2=seniorTickets * theater.dSeniorPrice;
          double ep3=childTickets * theater.dChildPrice;

          double fep1= (ep1*dSALES_TAX)+ep1;
          double fep2=(ep2*dSALES_TAX)+ep2;
          double fep3=(ep3*dSALES_TAX)+ep3;

        totalPrice = fep1+ fep2 +fep3;
    }

    // Increment totalSales by the total price of tickets purchased
    totalSales += totalPrice;

    cout << "Total Price: $" << totalPrice << endl;
    cout << szBreakMessage;
}

// Function to access admin options
void accessAdminOptions(string& szAdminPass, int& incorrectPasswordAttempts, Theater& theater, double& totalSales, const string& szBreakMessage) {
    string inputPassword;
    cout << "Enter admin password: ";
    cin >> inputPassword;
    cin.ignore(); // Clear input buffer

    if (inputPassword == szAdminPass) {
        // Reset incorrect password attempts counter
        incorrectPasswordAttempts = 0;
    

        // Admin menu
        cout << "Admin access granted" << endl;
        cout<<endl;
        cout<<szBreakMessage;
        cout << "Admin Menu:" << endl;
        cout << "1. Update theater information" << endl;
        cout << "2. Display total sales" << endl;
        cout << "3. Reset membership file" << endl;
        cout << "4. Change admin password" << endl;
        cout << "-1. Exit admin menu" << endl;
        cout<<szBreakMessage;
        cout<<endl;

        // User input for admin menu choice
        int adminChoice;
        cout << "Enter choice: ";
        cin >> adminChoice;
        cin.ignore(); // Clear input buffer
        
        
        // Execute corresponding admin functionality based on user choice
        switch (adminChoice) {
            case 1:
                // Update theater information
                updateTheaterInformation(szAdminPass, theater);
                break;
            case 2:
                // Display total sales
                displayTotalSales(totalSales);
                break;
            case 3:
                // Reset membership file
                resetMembershipFile();
                break;
            case 4:
                // Change admin password
                changeAdminPassword(szAdminPass);
                break;
            case -1:
                // Exit admin menu
                cout << "Exiting admin menu." << endl;
                break;

            default:
                cout << "Invalid choice. Returning to main menu." << endl;
               

        }
    } else {
        cout << "Incorrect password." << endl;
        incorrectPasswordAttempts++;

        // Check if exceeded maximum password attempts
        if (incorrectPasswordAttempts > 2) {
            cout << "Closing program due to excess password attempts." << endl;
            exit(EXIT_FAILURE);
        }
    }
}

// Function to update theater information
void updateTheaterInformation(string& szAdminPass, Theater& theater) {
    // Prompt the user for a new theater file
    string newFileName;
    cout << "Enter the path of the new theater file: ";
    getline(cin, newFileName);

    // Process the new theater file and attempt to populate the theater structure
    Theater updatedTheater = processTheaterFile(newFileName);

    // Check if any of the fields in the updated theater structure are different from the original
    if (updatedTheater.szName != theater.szName || updatedTheater.iScreens != theater.iScreens ||
        updatedTheater.iParkingSpots != theater.iParkingSpots || updatedTheater.dAdultPrice != theater.dAdultPrice ||
        updatedTheater.dSeniorPrice != theater.dSeniorPrice || updatedTheater.dChildPrice != theater.dChildPrice ||
        updatedTheater.dMembersPrice != theater.dMembersPrice || updatedTheater.dMembershipPrice != theater.dMembershipPrice) {
        // If any field is different, update the theater
        theater = updatedTheater;
        cout << "Theater information updated successfully." << endl;
    } else {
        cout << "File does not exist or could not be processed. Theater information remains unchanged." << endl;
    }
}

// Function to display total sales
void displayTotalSales(double totalSales) {
    cout << "Total sales: $" << totalSales << endl;
}

// Function to reset membership file
void resetMembershipFile() {
    // Clear the contents of the membership file
    ofstream outFile("members.txt", ios::trunc);
    outFile.close();
    cout << "Membership file reset successfully." << endl;
}

// Function to change admin password
void changeAdminPassword(string& szAdminPass) {
    // Prompt the user for a new password

    string newPassword;
    cout << "Enter the new admin password: ";
    getline(cin, newPassword);

    // Update the admin password
    szAdminPass = newPassword;
    cout << "Admin password changed successfully." << endl;
}
