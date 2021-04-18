#ifndef MINIGIT_HPP
#define MINIGIT_HPP
 
#include <iostream>
using namespace std; 
 
struct doublyNode{
    int commitNumber; 
    singlyNode *head; 
    doublyNode *previous; 
    doublyNode *next;
};
 
struct singlyNode{
    string fileName; //local file
    string fileVersion; //name file in .minigit folder
    singlyNode *next;
};
 
 
class minigit
{
    private: 
        
    public: 
        //Add file
        void remove(string filename, singlyNode *head);
        //Commit
        //Checkout
};
 
#endif
