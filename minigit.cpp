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

bool searchHelper(singlyNode*head, string name)
{
    singlyNode *current = head; 
    while(current !=NULL)
    {
        if(current->fileName==name)
        {
            return true; 
        }
        current = current->next; 
    }
    return false; 
}
 
void minigit::remove(string filename, singlyNode *head)
{
     
    bool exist =  searchHelper(head, filename); 
    if(exist)
    {
        if(head->fileName == filename)
        {
            singlyNode *temp = head;
            if(head->next ==NULL)
            {
                cout << "I'm not sure what to do" << endl; 
                return; 
            }
            head->fileName = head->next->fileName; 
            head ->fileVersion = head ->next->fileVersion; 

            temp= head->next; 
            head->next = head->next->next; 
            delete temp; 
            return; 
        }
        singlyNode *prev = head; 
        //add code for the rest
    }
}
 
int main()
{
    
}
