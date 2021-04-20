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
    private: 
        
    public: 
        minigit();
        ~minigit(); 
        void add(string name, singlyNode *head); 
        void remove(string filename, singlyNode *head);
        //Commit
        //Checkout
};
 
#endif
