#include "minigit.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <filesystem>
using namespace std; 

namespace fs = std::filesystem;

minigit::minigit()
{
    return; 
}

minigit::~minigit()
{
    fs::remove_all(".minigit");
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
    currentCommit = getDLL(num); 
    currentCommit->head = NULL; 
}

void copy(string file,string version)
{
    ifstream inFile; 
    inFile.open(file); 
    string line; 
    ofstream myfile; 
    //ofstream::trunc; 
    myfile.open(".minigit/"+ file + version); 

    while(getline(inFile, line))
    {
        myfile<<line; 
    }
    myfile.close(); 
    inFile.close(); 
}


bool compare(string f1, string f2)
{
    ifstream infile1; 
    ifstream infile2; 
 
    string line1; 
    string line2; 
 
    int count=0; 
    bool compared; 
 
    infile1.open(f1); 
    infile2.open(f2); 
 
    while(getline(infile1, line1))
    { 
        while(getline(infile2, line2))
        {
            if(line1==line2)
            { 
                compared = true; 
            }
            else
            {
                compared = false; 
            }
        }
        
    }

    return compared; 
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


void minigit::add(int versionNum, string name)
{
    string version= "";
    bool directoryExist = fs::exists(name);
    bool exist = searchHelper(currentCommit->head, name); 
    if(!directoryExist)
    {
        cout<< "This file does not exist. Enter a valid name" << endl; 
       
    }
    if(directoryExist)
    {
             
        if(exist)
        {
            cout << "This file has already been added" << endl; 
        }
        else if(!exist)
        {
            version = to_string(versionNum);
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
    else
    {
        cout << "This file does not exist" << endl; 
        cout << "Enter a valid name" << endl; 
    }
}
 
doublyNode* commitDLL(int commitNum, doublyNode *current)
{
    doublyNode *nn = new doublyNode; 
    nn->commitNumber = commitNum; 
    nn->previous = current; 
    nn->next = NULL; 
    nn->head= NULL;
    return nn; 
}

void minigit::commit(int commitNum, string fileVersion)
{
    bool same; 
    ifstream inFile; 
    ofstream outFile; 
    singlyNode *start = currentCommit->head;  
    while(start !=NULL)
    {
         
        string x = ".minigit/" + start->fileName + start->fileVersion;
        inFile.open(x); 
        if(!inFile)
        {
            copy(start->fileName,fileVersion); 
        }
        else 
        {
            string toCompare = start->fileName+ start->fileVersion; 
            same = compare(start->fileName, toCompare);
            if(same)
            {
                cout << "Nothing has changed" << endl;  
            }
            else if(!same)
            {
                int numVersion = stoi(fileVersion); 
                numVersion ++; 
                start->fileVersion = to_string(numVersion); 
                cout << start->fileVersion << endl; 
                copy(start->fileName, start->fileVersion); 
            }
           
        }
        start = start->next; 
    }

   
    doublyNode *newDLL = commitDLL(commitNum,currentCommit); 
    singlyNode *fileListHead = 0; 
    singlyNode *fileListCurr = 0; 

    singlyNode *curr = currentCommit->head;
    for(curr; curr!=NULL; curr=curr->next)
    {
        cout << curr->fileName << " "; 
        singlyNode *copyCurr = new singlyNode();
        copyCurr->fileName = curr->fileName; 
        copyCurr->fileVersion = curr->fileVersion; 
        copyCurr->next = NULL; 
       
        if(fileListCurr!=0)
        {
            fileListCurr->next = copyCurr; 
        }
        if(fileListHead ==NULL)
        {
            fileListHead = copyCurr; 
        }
        fileListCurr = copyCurr; 
    }
    newDLL->head = fileListHead; 
    currentCommit = newDLL; 
  
}

void minigit::checkout(int commit)
{
    ofstream myfile; 
   
     
    while(currentCommit!=NULL)
    {
        
        if(currentCommit->commitNumber == commit)
        {
            cout << currentCommit->commitNumber<<endl; 
            singlyNode*curr = currentCommit->head; 
            while(curr!=NULL)
            {
                myfile.open(".minigit/"+ curr->fileName+curr->fileVersion); 
                //copy(curr->fileName, curr->fileVersion); 
                curr= curr->next; 
            }
        }
        currentCommit = currentCommit->next;
    }
}
