#include "minigit.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <filesystem>
using namespace std; 

namespace fs = std::filesystem;



minigit::~minigit()
{
    fs::remove_all(".minigit");
}

minigit::minigit()
{
    return; 
}

void copy(string file,string version)
{
    ifstream inFile; 
    inFile.open(file); 
    string line; 
    ofstream myfile; 
    
    myfile.open(".minigit/"+ file + version); 

    while(getline(inFile, line))
    {
        myfile<<line; 
    }
}

void copy2(string currFile, string verFile)
{

}

bool compare(string f1, string f2)
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
        return true;
    }
    else if(!compare)
    {
        cout << "Not a match " <<endl;
        return false;  
    }
 
}

bool searchHelper(singlyNode*head, string name)
{
    
    while(head !=NULL)
    {  
        if(head->fileName==name)
        { 
            return true; 
        }
        head = head->next; 
    }
     
    return false; 
}

singlyNode* getSLL(string fileName, string fileVersion)
{
    singlyNode *newNode = new singlyNode; 
    newNode->fileName = fileName; 
    newNode->fileVersion = fileVersion; 
    newNode->next = NULL;
    return newNode; 
}

doublyNode *getDLL(int commitNum)
{
   doublyNode *newNode = new doublyNode; 
   newNode ->commitNumber = commitNum;
   newNode->head = NULL; 
   newNode->next = NULL; 
   newNode->previous = NULL;  
   return newNode; 
}

void minigit::initialize(int num)
{
    fs::create_directory(".minigit");
    getDLL(num); 
    currentCommit->head=NULL; 
    cout << num << endl; 
}

void minigit::add(int versionNum, string name)
{
    string version= "";
    bool directoryExist = fs::exists(name);
    bool exist = searchHelper(currentCommit->head, name); 
    if(!directoryExist)
    {
        cout<< "Enter a valid name" << endl; 
       
    }
    if(directoryExist)
    {
             
        if(exist)
        {
            cout << "already been added" << endl; 
        }
        else if(!exist)
        {
            version = name + to_string(versionNum);
            singlyNode *temp = getSLL(name, version);
            singlyNode *last = currentCommit->head; 
            if(currentCommit->head==NULL)
            {
                currentCommit->head = temp; 
                return; 
            } 
            while(last->next!=NULL)
            {
                last = last->next; 
            } 
            last->next = temp; 
            return; 
        }
    } 
}

void minigit::remove(string filename)
{
    singlyNode *start = currentCommit->head; 
     
    bool exist =  searchHelper(start, filename); 
   
    if(exist)
    {
        if(start->fileName == filename)
        {
            singlyNode *temp = start;
            start = temp->next; 
            //->fileName = head->next->fileName; 
           // head ->fileVersion = head ->next->fileVersion; 
            delete temp; 
            return; 
        }
       else
       {
           singlyNode *pres = start; 
           singlyNode *prev= NULL; 
           while(pres->fileName!=filename)
           {
               prev= pres; 
               pres = pres->next;
           }
            prev->next = pres->next;
            delete pres; 
            pres->next = NULL; 
       }
    }
}
 

void minigit::commit(int commitNum, string fileVersion)
{
    
    ifstream inFile; 
    ofstream outFile; 
    singlyNode *start = currentCommit->head;  
    while(start !=NULL)
    {
        string x = ".minigit/" + start->fileName + " " + start->fileVersion; 
        inFile.open(x); 
        if(!inFile)
        {
            copy(start->fileName,fileVersion); 
        }
        else
        {
            //use compare function
            //  copy()
        }
        start = start->next; 
    }

    //traverse through the SLL and check if the fileversion exists in minigit directory
        // does not exist, copy the file from current directory into minigit
            // the name should be from the node's fileversion member (only if it's been added for the first time)
        // does exist, check if file has been changed
            // if unchanged, no nothing
            // if changed, copy the file from current directory into mingit (same as above) and increment it's version number and update SLL node with new version number

// after scanning SLL
    //final step created new DLL node
    // exact copy of SLL gets created from previous node
    // DLL commit number increases
    doublyNode *newDLL = getDLL(commitNum); 

}
