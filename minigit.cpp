#include "minigit.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
 
using namespace std; 
 

void copy(string file)
{
    ifstream inFile; 
    inFile.open(file); 
    string line; 
    ofstream myfile; 
    myfile.open("copyf1.txt"); 
    
    while(getline(inFile, line))
    {
        myfile<<line; 
    }

    myfile.close(); 
}

void compare(string f1, string f2)
{
    ifstream infile1; 
    ifstream infile2; 
 
    string line1; 
    string line2; 
 
    int count=0; 
    bool compare=false; 
 
    infile1.open(f1); 
    infile2.open(f2); 
 
    while(getline(infile1, line1))
    { 
        while(getline(infile2, line2))
        {
            if(line1==line2)
            { 
                compare = true; 
            }
        }
        
    }
    if(compare)
    {
        cout << "complete match " << endl; 
    }
    else if(!compare)
    {
        cout << "Not a match bitch" <<endl; 
    }
 
}

bool searchHelper(singlyNode*head)
{
 
}
 
void minigit::remove(string filename, singlyNode *head)
{
    bool exist =  searchHelper(head); 
    if(exist)
    {
        if(head->fileName == filename)
        {
            
        }
    }
}
 
int main()
{
    
}
