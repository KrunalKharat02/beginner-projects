#include <iostream>
#include <fstream>
#include <conio.h>
#include <dos.h>
#include <graphics.h>
#include <stdlib.h>
#include <string.h>
#include <iomanip>

using namespace std;

/*
    Library Management System

    This program simulates a library management system where students can add their details, view the added details, 
    search for specific students, modify their details, and delete records. It uses file handling to store and manipulate 
    the student details and provides a graphical user interface (GUI) to enhance the user experience.
*/

class Library
{
public:
    char name[20];   // Student's name
    int clas;         // Class of the student
    int rollno;       // Roll number of the student

    // Method to get student details from the user
    void getDetails()
    {
        cout << "******* Enter the details of the student: *******" << endl;
        cout << "Enter the name: " << endl;
        cin.ignore();
        cin.getline(name, 20); // Using cin.getline instead of gets for safety
        cout << "Enter the class: " << endl;
        cin >> clas;
        cout << "Enter the roll number: " << endl;
        cin >> rollno;
    }

    // Method to display student details
    void showDetails()
    {
        cout << "******** DETAILS ADDED ARE ***********" << endl;
        cout << "Name: " << name << endl;
        cout << "Class: " << clas << endl;
        cout << "Roll Number: " << rollno << endl;
    }
};

int main()
{
    int gdriver = DETECT, gmode;
    initgraph(&gdriver, &gmode, "c:\\turboc3\\bgi");
    setbkcolor(MAGENTA);
    setcolor(YELLOW);
    rectangle(10, 10, 630, 470);
    settextstyle(7, 0, 6);
    outtextxy(200, 15, "WELCOME");
    outtextxy(250, 200, "TO");
    settextstyle(7, 0, 6);
    outtextxy(70, 370, "LIBRARY");
    sleep(2);
    clearviewport();

    // Clear viewport and display developer info
    setbkcolor(BLACK);
    setcolor(YELLOW);
    rectangle(8, 8, 630, 470);
    settextstyle(7, 0, 6);
    outtextxy(200, 15, "DEVELOPED BY");
    outtextxy(250, 200, "Navi Arora");
    settextstyle(7, 0, 6);
    sleep(2);
    clearviewport();

    int choice;
    cout << "Enter your choice: " << endl;
    cout << "1) TO ADD" << endl;
    cout << "2) TO SHOW" << endl;
    cout << "3) TO SEARCH" << endl;
    cout << "4) TO MODIFY" << endl;
    cout << "5) TO DELETE" << endl;
    cout << "6) TO EXIT" << endl;
    cin >> choice;

    switch (choice)
    {
    case 1:
    {
        char ch = 'y';
        Library student;
        fstream file;
        file.open("library_records.txt", ios::binary | ios::out | ios::app);

        while (ch == 'y' || ch == 'Y')
        {
            student.getDetails();
            file.write((char *)&student, sizeof(Library));
            cout << "Do you want to add more? (y/n): " << endl;
            cin >> ch;
        }
        file.close();
        break;
    }

    case 2:
    {
        Library student;
        fstream file;
        file.open("library_records.txt", ios::binary | ios::in);

        file.seekg(0);
        while (file.read((char *)&student, sizeof(Library)))
        {
            student.showDetails();
        }
        file.close();
        break;
    }

    case 3:
    {
        char searchName[20];
        Library student;
        fstream file;
        file.open("library_records.txt", ios::binary | ios::in);

        file.seekg(0);
        cout << "Enter the name you want to search: " << endl;
        cin.ignore();
        cin.getline(searchName, 20);

        bool found = false;
        while (file.read((char *)&student, sizeof(Library)))
        {
            if (strcmp(student.name, searchName) == 0)
            {
                student.showDetails();
                found = true;
                break;
            }
        }

        if (!found)
        {
            cout << "Name not found!" << endl;
        }

        file.close();
        break;
    }

    case 4:
    {
        // Modify functionality (not implemented fully in original code)
        cout << "Modify functionality not implemented yet." << endl;
        break;
    }

    case 5:
    {
        // Delete functionality (not implemented fully in original code)
        cout << "Delete functionality not implemented yet." << endl;
        break;
    }

    case 6:
        cout << "Exiting the system. Thank you!" << endl;
        break;

    default:
        cout << "Invalid choice, please try again." << endl;
    }

    return 0;
}