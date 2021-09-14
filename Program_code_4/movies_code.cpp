/*
	Program 4
	5/31/19
	Luis Cervantes
	In this Program we are using a BST as our data structure the purpose is to sort our data based on the character
	the user can add and remove vert easy 
*/
#include "movies.h"
using namespace std;
movies::movies()// constructor sets data to NULL
{
	/*
		Sets all of my variables to NULL
	*/
	n_characters = 0;
	n_actors = 0;
	movie = NULL;
	characters = NULL;
	actors = NULL;
	main_character = NULL;
	/*
		Sets all of my variables to NULL
	*/
}
movies::~movies()// deallocates all of the memory
{
	/*
		releases  all of my variables and sets to NULL
	*/
	n_characters = 0;
	n_actors = 0;
	delete [] movie;
	delete_char(characters);
	delete_char(actors);
	/*
		releases  all of my variables and sets to NULL
	*/
}
int movies::new_movie(char * film,char * main, int n_character, int n_actor)// gets data from main and saves data
{
	movie = new char [strlen(film) +1];
	strcpy(movie,film);//copys movie

	main_character = new char[strlen(main) +1];
	strcpy(main_character,main);// copy main charcter

	n_characters = n_character;//gets #
	n_actors = n_actor;// gets #
}
int movies::delete_character(char * character_name)// deletes character wrapper
{
	delete_character(character_name,characters);// calls function to delete character
}
int movies::delete_character(char * character_name, node * & head)//deletes character from LLL
{
	if(head == NULL) return 0;//loops
	if(strcmp(character_name,head->name) == 0)// checks if the same
	{
		node * tmp = head;// tmp node
		head = head->next;// gets the next value
		delete [] tmp->name;// dealocates
		delete tmp;// deletes nide
		return 1;
	}
	else
	{
		delete_character(character_name,head->next);// traverses to the next node
	}
}
int movies::remove_characters()// deletes all of the data of character
{
		delete_char(characters);// calls function to delete all 
}
int movies::remove_actors()// deletes all data of actor
{
		delete_char(actors);// calls function to delete all
}
int movies::copy_movie(const movies & copy)// copys movie from class to this class
{
	if(!copy.movie || !copy.characters || !copy.actors || !copy.characters || !copy.actors) return 0;// if NULL exits

	if(movie)// if there is data deletes it 
		delete [] movie;
	if(characters)// if there is data it deletes it
		delete_char(characters);
	if(actors)// if ther is data it deletes it
		delete_char(actors);


	movie = new char[strlen(copy.movie) +1];// allocates memory
	strcpy(movie,copy.movie);//copys
	

	main_character = new char[strlen(copy.main_character) +1];
	strcpy(main_character,copy.main_character);

	n_actors = copy.n_actors;
	n_characters = copy.n_characters;		
	
	copy_LLL(copy.characters,characters);//copys LLL
	copy_LLL(copy.actors,actors);//copys LLL	
}
int movies::sorting_bst(char * name)// sorts the BST based on lengtj
{
	int value1 = strlen(name);// gets length
	int value2 = strlen(main_character);// gets length
	if(value1 >= value2)// if greater goes to the right
	{
		return 1;//return 1
	}
	else
	{
		return 0;
	}
}
int movies::compare_movie(char * name)// compares the movie name to their data
{
	if(movie == NULL) return 0;
	if(strcmp(name,movie) == 0)// checks if the movie is the same as what they passed in
	{
		return 1;//exits
	}
	else
	{
		return 0;
	}
}
int movies::compare(char * name)
{
	if(main_character == NULL) return 0;//exits if NULL
	int value = strcmp(name,main_character);// gets the value of stcmp
	if(value == 0)// if same return 1
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
int movies::compare_character(char * name)//function to compare the charcters in the LLL
{
	int found;
	found = compare_character(name, characters);// calls function
	return found;// return if found
}
int movies::compare_character(char * name, node * head)// recursive function to copare data
{
	if(head == NULL) return 0;
	if(strcmp(head->name,name) == 0)// if same exits loop
	{
		return 1;
	}
	compare_character(name,head->next);// recursive call
}
int movies::compare_actor(char * actor_name)//calls function to compare actors
{
	compare_actor(actor_name,actors);// recursive function
}
int movies::compare_actor(char * actor_name,node * head)// recursive functiion to compare actors`
{
	if(head == NULL) return 0;// if NULL exits program
	if(strcmp(actor_name,head->name) == 0)// if same exits loop
	{
		return 1;//exits
	}
	compare_actor(actor_name,head->next);// goes to the next
}
int movies::copy_LLL(node * original, node *& copy)// copys the LLL data to another
{
	if(original == NULL) return 0;
	if(copy == NULL)// if NULL makes New one
	{
		node * tmp = new node;
		tmp->name = original->name;
		tmp->next = NULL;
		copy = tmp;
	}
	else// else it just adds 
	{
		node * tmp = new node;
		tmp->name = original->name;
		tmp->next = NULL;
		copy = tmp;
	}
	copy_LLL(original->next,copy->next);// traverses
	
}
int movies::retrieve_data(movies & matching_films)// copys data from the function to another object
{
	matching_films.movie = new char[strlen(movie) +1];
	strcpy(matching_films.movie,movie);//cops data

	matching_films.main_character = new char[strlen(main_character) +1];
	strcpy(matching_films.main_character, main_character);
	

	matching_films.n_actors = n_actors;
	matching_films.n_characters = n_characters;
	
	copy_LLL(characters,matching_films.characters);// cops data
	copy_LLL(actors,matching_films.actors);	
}
int movies::adding_character(char * data)// adds a new charcter to the LLL of charcter
{
	if(characters == NULL)
	{
		node * tmp = new node;
		tmp->name = data;
		tmp->next = NULL;
		characters = tmp;
	}
	else
	{
		node * tmp = new node;
		tmp->name = data;
		tmp->next = characters;// adds to the front
		characters = tmp;
	}
}
int movies::adding_actor(char * data)// adds an actor to the LLL
{
	if(actors == NULL)
	{
		node * tmp = new node;
		tmp->name = data;
		tmp->next = NULL;
		actors = tmp;
	}
	else
	{
		node * tmp = new node;
		tmp->name = data;
		tmp->next = actors;// adds to the front
		actors = tmp;
	}

}
int movies::add_new_char(char * data,node * & head)// adds data to what ever LLL i desire  and adds to the front
{
	if(head == NULL)
	{
		node * tmp = new node;
		tmp->name = data;
		tmp->next = NULL;
		head = tmp;
	}
	else
	{
		node * tmp = new node;
		tmp->name = data;
		tmp->next = head;
		head = tmp;
	}
}
int movies::display_movie()// displays all of the data
{
	cout<<'\n'<<endl;
	cout<<"Name of Movie:"<<endl;
	cout<<movie<<endl;
	cout<<"Main character"<<endl;
	cout<<main_character<<endl;
	cout<<"Amount of characters in movie:"<<endl;
	cout<<n_characters<<endl;
	cout<<"Name of the characters in the film:"<<endl;
	display_char(characters);
	cout<<"Number of Actors in the film:"<<endl;
	cout<<n_actors<<endl;
	cout<<"Name of the actors:"<<endl;
	display_char(actors);
	cout<<'\n'<<endl;
}
int movies::display_option()// Displays their options
{
	if(characters == NULL && actors == NULL) return 0;
	cout<<"These are the Characters from what you can search on:"<<endl;
	cout<<characters->name<<endl;
	cout<<"\n"<<endl;
	cout<<"These are the Actors from what you can search on:"<<endl;
	cout<<actors->name<<endl;
	cout<<"\n"<<endl;
}
int movies::display_char(node * head)// displays data inside LLL
{
	if(head == NULL) return 0;
	cout<< head->name <<endl;
	display_char(head->next);
}
int movies::delete_char(node *& head)// deletes all the data in the LLL
{
	if(head == NULL) return 0;

	node * tmp = head;
	head = head->next;
	delete tmp;

	delete_char(head);
}
