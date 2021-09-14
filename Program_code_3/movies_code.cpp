/*
	Program 3
	5/24/19
	Luis Cervantes
	In this Program the data structure that we are using is a hash table where every key gets send to an index 
	The purpose of the program is to let the user search by charcter and by actor by using a ADT data structure(hash table)
	In this program the uses is able to add,remove,retrieve,display and search by key. The data that we are keeping track is all of 
	the data of the movie such as the actors/character in the data structre the key is the name of the actor and the character in the film like
	that user can seach based on the name of the actor or the name of the character.
*/
#include "movies.h"
using namespace std;
movies::movies()// constructor sets data to NULL
{
	n_characters = 0;
	n_actors = 0;
	movie = NULL;
	characters = NULL;
	actors = NULL;
}
movies::~movies()// deallocates all of the memory
{
	n_characters = 0;
	n_actors = 0;
	delete [] movie;
	delete_char(characters);
	delete_char(actors);
}
int movies::new_movie(char * film, int n_character, int n_actor)// makes a new movie
{
	movie = new char [strlen(film) +1];
	strcpy(movie,film);//gets data	

	n_characters = n_character;
	n_actors = n_actor;
}
int movies::delete_character(char * character_name)// deletes character
{
	delete_character(character_name,characters);
}
int movies::delete_character(char * character_name, node * & head)//deletes all of the data recursive
{
	if(head == NULL) return 0;//loops
	if(strcmp(character_name,head->name) == 0)
	{
		node * tmp = head;
		head = head->next;
		delete [] tmp->name;
		delete tmp;
		return 1;
	}
	else
	{
		delete_character(character_name,head->next);
	}
}
int movies::remove_characters()// deletes all of the data of character
{
		delete_char(characters);
}
int movies::remove_actors()// deletes all data of actor
{
		delete_char(actors);
}
int movies::copy_movie(const movies & copy)// copys movie
{
	if(!copy.movie || !copy.characters || !copy.actors || !copy.characters || !copy.actors) return 0;

	if(movie)
		delete [] movie;
	if(characters)
		delete_char(characters);
	if(actors)
		delete_char(actors);


	movie = new char[strlen(copy.movie) +1];
	strcpy(movie,copy.movie);
	

	n_actors = copy.n_actors;
	n_characters = copy.n_characters;		
	
	copy_LLL(copy.characters,characters);
	copy_LLL(copy.actors,actors);	
}
int movies::compare_movie(char * name)// compares the movie name to their data
{
	if(movie == NULL) return 0;
	if(strcmp(name,movie) == 0)
	{
		n_characters++;
		return 1;
	}
	else
	{
		return 0;
	}
}
int movies::compare(char * name)
{
	int found;
	found = compare(name, characters);
	return found;
}
int movies::compare(char * name, node * head)
{
	if(head == NULL) return 0;
	if(strcmp(head->name,name) == 0)
	{
		return 1;
	}
	compare(name,head->next);
}
int movies::compare_actor(char * actor_name)
{
	compare_actor(actor_name,actors);
}
int movies::compare_actor(char * actor_name,node * head)
{
	if(head == NULL) return 0;
	if(strcmp(actor_name,head->name) == 0)
	{
		return 1;
	}
	compare_actor(actor_name,head->next);
}
int movies::copy_LLL(node * original, node *& copy)
{
	if(original == NULL) return 0;
	if(copy == NULL)
	{
		node * tmp = new node;
		tmp->name = original->name;
		tmp->next = NULL;
		copy = tmp;
	}
	else
	{
		node * tmp = new node;
		tmp->name = original->name;
		tmp->next = NULL;
		copy = tmp;
	}
	copy_LLL(original->next,copy->next);
	
}
int movies::retrieve_data(movies & matching_films)
{
	matching_films.movie = new char[strlen(movie) +1];
	strcpy(matching_films.movie,movie);
	

	matching_films.n_actors = n_actors;
	matching_films.n_characters = n_characters;
	
	copy_LLL(characters,matching_films.characters);
	copy_LLL(actors,matching_films.actors);	
}
int movies::adding_character(char * data)
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
		tmp->next = characters;
		characters = tmp;
	}
}
int movies::adding_actor(char * data)
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
		tmp->next = actors;
		actors = tmp;
	}

}
int movies::add_new_char(char * data,node * & head)
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
int movies::display_movie()
{
	cout<<'\n'<<endl;
	cout<<"Name of Movie:"<<endl;
	cout<<movie<<endl;
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
int movies::display_option()
{
	if(characters == NULL && actors == NULL) return 0;
	cout<<"These are the Characters from what you can search on:"<<endl;
	cout<<characters->name<<endl;
	cout<<"\n"<<endl;
	cout<<"These are the Actors from what you can search on:"<<endl;
	cout<<actors->name<<endl;
	cout<<"\n"<<endl;
}
int movies::display_char(node * head)
{
	if(head == NULL) return 0;
	cout<< head->name <<endl;
	display_char(head->next);
}
int movies::delete_char(node *& head)
{
	if(head == NULL) return 0;

	node * tmp = head;
	head = head->next;
	delete tmp;

	delete_char(head);
}
