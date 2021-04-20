#include "minigit.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <filesystem>
using namespace std; 


void displayMenu()
{
    cout << "===== Main Menu =====" << endl; 
    cout << "1. Initialize new repository" <<endl; 
    cout << "2. Add a file" << endl; 
    cout << "3. Remove a file" << endl; 
    cout << "4. Commit" << endl; 
    cout << "5. Checkout" <<endl; 
    cout << "6. Quit" << endl; 
}

int main()
{
    int input; 
    string filenameAdd = "";
    string filenameRemove = "";  
    int commitNumber;
    int initCommit;
    displayMenu(); 
    cin >> input; 

    minigit m1;

    while(1)
    {
        if(input ==1)
        {
            initCommit =0; 
            cout << "new repository initialized" << endl; 
            m1.initialize(initCommit);
            initCommit++; 
        }
        else if (input ==2)
        {
            cout << "Enter file name" << endl; 
            cin >> filenameAdd; 
        }
        else if(input ==3)
        {
            cout << "Enter file name" << endl; 
            cin >> filenameRemove; 
        }
        else if(input ==4)
        {
            cout << "Files have been commited" << endl; 
        }
        else if(input ==5)
        {
            cout << "Enter a commit number" << endl; 
            cin >> commitNumber; 
        }
        else if(input==6)
        {
            cout << "Goodbye!" << endl; 
            break; 
        }
        displayMenu(); 
        cin>>input; 
    }
    return 0; 
}