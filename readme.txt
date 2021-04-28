CSCI 2270 Final Project: Minigit
This project is a version control system that mimics the commands the functionality of a git program. The core functionality of the program allows for the user to initialize a repository, add, and remove files, commit the files that have been added and lastly to checkout previous commits. 
This program uses singly linked lists to keep track of the files that the user wants to keep track. Each node of the singly linked list contains the name of the file, the version of the file and a pointer to the next node in the linked list. To keep track of the commits made by the user, this program uses a doubly linked list. Each node in the doubly linked list contains a pointer the previous and next node, the number corresponding to the commit. Along with that, the doubly linked list points to the head of the singly linked list containing the files to be tracked. 
When first running the program, the following options are available: 
1.Initialize a repository
	a.This initializes a new repository called “minigit”. This is where the files that get committed will appear. You must initialize a repository before choosing any other option. 
2.Add a file
	a.This option adds a file to the singly linked list and will be tracked when committing. This means that if the program detects any changes to the text files, a new version of the file will get added to the minigit repository. 
3.Remove a file
	a.This option removes the file from the linked list, and it will no longer get tracked by the program. This does not mean that the file will disappear from the minigit repository but that if there are changes made to the file, there will not be an updated file in the repository.  
4.Commit
	a.This option allows the user to see the files they have added and to make changes to them. As stated in the add and remove description, this option traverses through the singly linked list of the file nodes and checks if there are changes to them. If there are changes, the new file with changes gets added to the minigit repository with an incremented file version number. If there are no changes, nothing happens. 
	b.Also, at every commit a new doubly linked list node gets created and contains a deep copy of singly linked list from the past commit. The commit number gets incremented with each commit, starting at 0. 
5.Checkout 
	a.This option allows the user to go back to the previous commits to check what the files looked like during that commit. The user will input a commit number and the program will traverse the doubly linked list until it finds one with a matching commit number and writes the file associated with the commit to the minigit repository. 
6.Quit
	a.This quits the menu and program and deletes the minigit repository. 

The command used to compile for this program is g++ -std=c++17.
