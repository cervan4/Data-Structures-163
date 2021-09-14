
/*
	Program 4
	5/31/19
	Luis Cervantes
	In this Program we are using a BST as our data structure the purpose is to sort our data based on the character
	the user can add and remove vert easy 
*/
#include "bst.h"
using namespace std;
int main()
{
	//declares valiables
	movies test;
	tree my_tree;
	int count = 0;
	int choose;
	int done = 0;
	char * movie = NULL;
	char * main = NULL;
	char * actor = NULL;
	char * character = NULL;
	char tmp[500];
	int number_c = 0;
	int number_a = 0;
	int height = 0;
	int keep = 0;
	movies * retrieve;
	retrieve = new movies[100];
	//declares variables
	while(done != 1)// while they decide they are done they will be able to choose 
	{
		// Displays their options
		cout<<"1: Add a new movie"<<endl;
		cout<<"2: Display all"<<endl;
		cout<<"3: Display movies character has been in"<<endl;
		cout<<"4: Add a new character to a movie"<<endl;
		cout<<"5: Get height"<<endl;
		cout<<"6: See if it's balanced"<<endl;
		cout<<"7: Retrieve movie based on character"<<endl;
		cout<<"8: Delete a movie "<<endl;
		cout<<"10: Exit Program"<<endl;
		//displays options
		cin >> choose;//enters in their data
		cin.ignore();// ignore
		switch(choose)// switch statement
		{
			//case 1 they add a new movie to the BST
			case 1:
				/*
					Gets data froom the user such as the movie name,main character, # of actors # of characters
					all the characters name, actors names
				*/
				cout<<"Enter in the name of the movie"<<endl;
				cin.get(tmp,500,'\n');
				cin.ignore(500,'\n');
				movie = new char [strlen(tmp) +1];
				strcpy(movie,tmp);

				cout<<"Enter in the name of the main character"<<endl;
				cin.get(tmp,500,'\n');
				cin.ignore(500,'\n');
				main = new char [strlen(tmp) +1];
				strcpy(main,tmp);
		
				cout<<"Enter in the number of characters"<<endl;
				cin >>number_c;
				cin.ignore(500,'\n');

				cout<<"Enter in the number of Actor"<<endl;
				cin >>number_a;
				cin.ignore(500,'\n');
				test.new_movie(movie,main,number_c,number_a);
				count = 0;
				while(count < number_c)
				{
					cout<<"Enter in the name of the character"<<endl;
					cin.get(tmp,500,'\n');
					cin.ignore(500,'\n');
					character = new char [strlen(tmp) +1];
					strcpy(character,tmp);
					test.adding_character(character);//calls function to add character to LLL
					count++;
				}
				count = 0;
				while(count < number_a)
				{
					cout<<"Enter in the name of the Actor"<<endl;
					cin.get(tmp,500,'\n');
					cin.ignore(500,'\n');
					actor = new char [strlen(tmp) +1];
					strcpy(actor,tmp);
					test.adding_actor(actor);//adds actor to LLL of actors
					count++;
				}
				/*
					Gets data froom the user such as the movie name,main character, # of actors # of characters
					all the characters name, actors names
				*/
				my_tree.insert(main,test);//calls function to insert into BST
				test.remove_characters();//deallocates all character
				test.remove_actors();//deallocates all actors
				break;	
				
				case 2:// Displays all thats inside the BST
					my_tree.display_all();// Function to display all
					break;
				case 3:
					// Display all the movie with a certain character
					cout<<"Enter in the name of the character"<<endl;// asks for the name
					cin.get(tmp,500,'\n');
					cin.ignore(500,'\n');
					character = new char [strlen(tmp) +1];
					strcpy(character,tmp);
					
					my_tree.display_matching_character(character);// calls function to dipplay all matches
					break;
				case 4:
					//Adds a new character to certain movie
				/*
					Gets data froom the user such as the movie name,character
				*/
					cout<<"Enter in the name of the character you are adding"<<endl;
					cin.get(tmp,500,'\n');
					cin.ignore(500,'\n');
					character = new char [strlen(tmp) +1];
					strcpy(character,tmp);

					cout<<"Enter in the name of the movie you are adding to"<<endl;
					cin.get(tmp,500,'\n');
					cin.ignore(500,'\n');
					movie = new char [strlen(tmp) +1];
					strcpy(movie,tmp);
				/*
					Gets data froom the user such as the movie name,character
				*/
				
					my_tree.add_movie_character(character,movie);//calls function to add new character to movie
					break;
				case 5:// gets the height of the tree
					height = my_tree.get_height();// gets height of the tree
					cout<<"This is the Height: "<<height<<endl;// displays the height
					break;
				case 6://checks if the tree is balanced
					height = my_tree.is_balanced();// gets value back
					if(height == 1)
					{
						cout<<"The Tree is somewhat balanced"<<endl;// its balaneced
					}
					else// not balanced
					{
						cout<<"The Tree is not balanced"<<endl;
					}
					break;
				case 7:
					// retrieves data with all movies with certain character
					cout<<"Enter in the name of the character"<<endl;// ask for the charcter name
					cin.get(tmp,500,'\n');
					cin.ignore(500,'\n');
					character = new char [strlen(tmp) +1];
					strcpy(character,tmp);
			
					my_tree.retrieve_movie(retrieve,keep,character);// calls function to retrieve all data
					
					break;
				case 8:
					/*
						Ask the user for the data such the charcter name and the movie
						in order to delete certain film with actors
					*/
					cout<<"Enter in the name of the character"<<endl;// 
					cin.get(tmp,500,'\n');// gets character name
					cin.ignore(500,'\n');
					character = new char [strlen(tmp) +1];
					strcpy(character,tmp);

					cout<<"Enter in the name of the movie"<<endl;
					cin.get(tmp,500,'\n');// gets actors name
					cin.ignore(500,'\n');
					movie = new char [strlen(tmp) +1];
					strcpy(movie,tmp);

					my_tree.delete_film(character,movie);// class function to delete certain film with actor in it
					break;
				case 10:// exits program
					done = 1;//exits loop
					break;
		}
	}
	return 0;
}
