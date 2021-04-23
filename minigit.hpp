#ifndef MINIGIT_HPP
#define MINIGIT_HPP
 
#include <iostream>
using namespace std; 
 

struct singlyNode{
    string fileName; //local file
    string fileVersion; //name file in .minigit folder
    singlyNode *next;
};
 
struct doublyNode{
    int commitNumber; 
    singlyNode *head; 
    doublyNode *previous; 
    doublyNode *next;
};
 

 
class minigit
{    
    public: 
        minigit();
        ~minigit(); 
        void add(int num, string name); 
        void remove(string filename);
        void initialize(int commitNumber); 
        void commit(int num, string fileVersion); 
        void checkout(int commitNum); 
        doublyNode *currentCommit; 
};
 
#endif
