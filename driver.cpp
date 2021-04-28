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
    //singlyNode * start = m1.currentCommit->head;
    bool init = false; 
    bool check = false; 

    displayMenu(); 
    cin >> input; 

    while(input !=6)
    {
        string strVersion = to_string(commitNumber);
        switch(input)
        {
            case 1:  
                cout << "New repository minigit initialized" << endl; 
                m1.initialize(initCommit);   
                initCommit++; 
                init = true; 
            break; 

            case 2: 
                if(init && !check)
                {
                    cout << "Enter file name" << endl; 
                    cin >> filenameAdd; 
                    m1.add(version,filenameAdd);
                }
                else if(!init)
                {
                    cout << "Repository has not been initialized." << endl; 
                    cout << "You must initialize a repository before adding, removing, committing or checking out." << endl; 
                }
                else if(check)
                {
                    cout << "You are currently checking another commit. You can not add, remove files or commit" << endl; 
                }
                
            break; 

            case 3: 
                if(init && !check)
                {
                    cout << "Enter file name" << endl; 
                    cin >> filenameRemove; 
                    m1.remove(filenameRemove); 
                }
                 else if(!init)
                {
                    cout << "Repository has not been initialized." << endl; 
                    cout << "You must initialize a repository before adding, removing, committing or checking out." << endl; 
                }
                else if(check)
                {
                    cout << "You are currently checking another commit. You can not add, remove files or commit" << endl; 
                }
            break; 

            case 4: 
                if(init && !check)
                {
                    m1.commit(commitNumber,strVersion);
                    cout << "has been commited" << endl;  
                    // commitNumber++;
                    currCommitNum++;  
                }
                 else if(init)
                {
                    cout << "Repository has not been initialized." << endl; 
                    cout << "You must initialize a repository before adding, removing, committing or checking out." << endl; 
                }
                else if(check)
                {
                    cout << "You are currently checking another commit. You can not add, remove files or commit" << endl; 
                }
                 
            break; 
            case 5: 
                if(init)
                {
                    cout << "Enter a commit number" << endl; 
                    cin >> commitNumber; 
                    m1.checkout(commitNumber);
                    check = true;  

                } 
                 else
                {
                    cout << "Repository has not been initialized." << endl; 
                    cout << "You must initialize a repository before adding, removing, committing or checking out." << endl; 
                }
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