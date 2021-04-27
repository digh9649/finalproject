#include "minigit.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <filesystem>
using namespace std; 


void displayMenu()
{
    cout << "Select a numerical option" << endl; 
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
    int commitNumber =0;
    int initCommit =0;
    minigit m1;
    int version=0;
    int currCommitNum =1;
    singlyNode * start = m1.currentCommit->head;

    displayMenu(); 
    cin >> input; 

    while(input !=6)
    {
        string strVersion = to_string(commitNumber);
        switch(input)
        {
            case 1:  
                cout << "new repository initialized" << endl; 
                m1.initialize(initCommit);   
                initCommit++; 
            break; 

            case 2: 
                cout << "Enter file name" << endl; 
                cin >> filenameAdd; 
                m1.add(version,filenameAdd);

            break; 

            case 3: 
                cout << "Enter file name" << endl; 
                cin >> filenameRemove; 
                m1.remove(filenameRemove); 
            break; 

            case 4: 
            
                 m1.commit(commitNumber,strVersion);
                 cout << "Files have been commited" << endl;  
                // commitNumber++;
                 currCommitNum++;  
            break; 
            case 5:  
                cout << "Enter a commit number" << endl; 
                cin >> commitNumber; 
                 m1.checkout(commitNumber); 
            break; 

            case 6:
                 cout << "Goodbye!" << endl; 
            
            break;
        }
        displayMenu();
        cin>>input;
        
    }
    return 0; 
}