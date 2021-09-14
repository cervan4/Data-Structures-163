/*
	Luis Cervantes Oropeza
	6/7/19
	In this program we use a graph an adjacency list of vertices 
	The purpose of this program is to write a scavanger hunt using a graph like this we can connext up vertices and put them into a LLL
*/
#include <iostream>
#include <cctype>
#include <cstring>
#include <fstream>
class scavenger
{
	public:
		scavenger();// constructor to set memory
		~scavenger();// desctructor to deallocate the memory
		int new_outcome(char * outcome, char * option);// creates a new path
		int copy(const scavenger & copy);// copys the data from the object
		int display_option();// displays their options
		int display_result();// displays the result of the root
	private:
		char * result;
		char * choice;
};
