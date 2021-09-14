/*
	Luis Cervantes Oropeza
	6/7/19
	In this program we use a graph an adjacency list of vertices 
	The purpose of this program is to write a scavanger hunt using a graph like this we can connext up vertices and put them into a LLL
*/
#include "scavanger_hunt.h"
using namespace std;
scavenger::scavenger()
{
	result = NULL;// sets to NULL
	choice = NULL;// sets to NULL
}
scavenger::~scavenger()
{
	if(result)// if there is data it deletes it
		delete [] result;// deletes data
	if(choice)
		delete [] choice;// delete data
}
int scavenger::new_outcome(char * outcome, char * option)// read in data 
{
	result = new char[strlen(outcome) + 1];// allocates memory
	strcpy(result,outcome);// copys data
	choice = new char[strlen(option) + 1];//allocates memory
	strcpy(choice,option);//copys data
}
int scavenger::copy(const scavenger & copy)//copys data from object
{
	if(!copy.result || !copy.choice) return 0;// if NULL return 0
	if(result)// if data deletes it
		delete [] result;// deletes data
	if(choice)
		delete [] choice;// deletes data

	result = new char[strlen(copy.result) + 1];// allocates data
	strcpy(result,copy.result);// copys data
	choice = new char [strlen(copy.choice) + 1];// allocates data
	strcpy(choice,copy.choice);//copys data
	return 1;
}
int scavenger::display_option()// displays options
{
	if(choice == NULL) return 0;
	cout<<choice<<endl;// displays 
}
int scavenger::display_result()// displays result
{
	if(result == NULL) return 0;// if NULL exits
	cout<<result<<endl;// displays 
}
