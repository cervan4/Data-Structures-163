#include "my_trip.h"
/*
	Luis Cervantes Oropeza
	4/19/19
	CS 163 
	Program 1
	The data structure that is being used for program 1 is a LLL of LLL
	
	In this program most of the functions all done recursive 	

	The purpose of this program is so that the user deosnt know what data structure is being used since its a ADT program
	In This program the user can create a category and add to the category of their wish 
	When the name is entered the name of category are in sorted order at all time.
	The user can add/ remove category and display the category and siplay all 
	As well rhey can swap the location of the item thats inside the LLL
*/
using namespace std;
int main()
{
	// varibles declared 
	char * category;
	char * data;
	char tmp[1000];
	int choice;// for their option
	int done = 0;// to exir loop
	trip my_trip;// makes object called my trip
	while(done != 1)// The program keeps running untl the user is done with the program
	{
		// Displat their options 
		cout<<"1: Enter in a new category for your travel"<<endl;
		cout<<"2: Add data to a category"<<endl;
		cout<<"3: Display category data"<<endl;
		cout<<"4: Display All"<<endl;
		cout<<"5: Remove a category"<<endl;
		cout<<"6: Move position of an item in a category"<<endl;
		cout<<"10: Exit Program"<<endl;
		cin >> choice;// enters data 
		cin.ignore(1000,'\n');
		switch(choice)// depending on their input it will go to the oprion 
		{
			case 1:// In this case they add a new category to the LLL
				cout<<"Enter in the name of the category you want to add"<<endl;
				cin.get(tmp,1000,'\n');// gets the category they want to add
				cin.ignore(1000,'\n');
				category = new char[strlen(tmp) + 1];// allocates memory
				strcpy(category,tmp);//copy data 
				my_trip.new_category(category);// calls function to add a new category and passes in the category
				break;
			case 3:// Displays data inside a specific category
				cout<<"Enter in the name of the category you want to display"<<endl;
				cin.get(tmp,1000,'\n');// gets the name of the category they want to display
				cin.ignore(1000,'\n');
				category = new char[strlen(tmp) + 1];// Allocates memory
				strcpy(category,tmp);// copys data 

				my_trip.display_category(category);// calls function to display category and its data
				break;
			case 2:// Adds an item to the category they want to be added
				cout<<"Enter in the name of the category you are adding to"<<endl;
				cin.get(tmp,1000,'\n');// gets data 
				cin.ignore(1000,'\n');
				category = new char[strlen(tmp) + 1];// allocates memory
				strcpy(category,tmp);//copys data

				cout<<"Enter in the data for the category"<<endl;// enters in item for the category
				cin.get(tmp,1000,'\n');// gets item
				cin.ignore(1000,'\n');
				data = new char[strlen(tmp) + 1];// allocates memory
				strcpy(data,tmp);//copys data
				my_trip.add_to_category(data,category);// calls function to add an item to the category
				break;
			case 4:// Displays all inside the LLL of LLL
				my_trip.display_all();// Calls function to display all 
				break;
			case 5://to remove a category and its data
				cout<<"Enter in the name of the category you are removing"<<endl;
				cin.get(tmp,1000,'\n');// gets name of category
				cin.ignore(1000,'\n');
				category = new char[strlen(tmp) + 1];// allocates memory
				strcpy(category,tmp);// copys data
				my_trip.remove_category(category);// calls function to remove the category
				break;
			case 6:// To shift an item inside the category
				cout<<"Enter in the name of the category"<<endl;// gets name of the category
				cin.get(tmp,1000,'\n');// gets category
				cin.ignore(1000,'\n');
				category = new char[strlen(tmp) + 1];
				strcpy(category,tmp);// copys data

				cout<<"Enter name of what you want to move"<<endl;// gets the name of the item they want to move
				cin.get(tmp,1000,'\n');// gets data
				cin.ignore(1000,'\n');
				data = new char[strlen(tmp) + 1];
				strcpy(data,tmp);
				
				cout<<"Enter the position you want to move it to (#number)"<<endl;// gets value of what position they want to move
				int position;
				cin >> position;// ges positiob
				cin.ignore(1000,'\n');
				my_trip.edit_the_location(category,position,data);//calls function to move the item inside the category to abother place
				break;	
				
			case 10:// if they are done exits program
				done = 1;
				break;
		}
	}
	
	return 0;
}
