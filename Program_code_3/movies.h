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
#include <iostream>
#include <cctype>
#include <cstring>
#include <fstream>
struct node
{
	char * name;
	node * next;
};
class movies
{
	public:
		movies();// constructot
		~movies();// destructot
		int new_movie(char * film, int n_character, int n_actor);// new movie
		int copy_movie(const movies & copy);//cops movie
		int adding_character(char * data);// adds character
		int compare(char * name);// compares character
		int display_movie();// diplsays data
		int adding_actor(char * data);// adds actor
		int delete_character(char * character_name);// deletes character
		int compare_actor(char * actor_name);//compares actor
		int compare_movie(char * name);//compare movie
		int display_option();// displays their options
		int remove_characters();// removes their characters
		int remove_actors();
		int retrieve_data(movies & matching_films);// retrieves data
	private:
		char * movie;
		int n_characters;
		node * characters;
		int n_actors;
		node * actors;
		int delete_char(node *& head);
		int display_char(node * head);
		int add_new_char(char * data,node * & head);
		int copy_LLL(node * original, node *& copy);
		int compare(char * name, node * head);
		int delete_character(char * character_name, node * & head);
		int compare_actor(char * actor_name,node * head);
};
