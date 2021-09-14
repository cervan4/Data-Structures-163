/*
	Program 4
	5/31/19
	Luis Cervantes
	In this Program we are using a BST as our data structure the purpose is to sort our data based on the character
	the user can add and remove vert easy 
*/
#include <iostream>
#include <cctype>
#include <cstring>
#include <fstream>

// This is a node for the character and actors. 
struct node
{
	char * name;
	node * next;
};

// This is the movie class. 
class movies
{
	public:
		movies();// constructot
		~movies();// destructot
		int new_movie(char * film,char * main, int n_character, int n_actor);// new movie
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
		int compare_character(char * name); // This function checks if there are a match. 
		int sorting_bst(char * name); // This sorts the BST. 
	private:
		char * movie; 
		int n_characters;
		node * characters;
		int n_actors;
		char * main_character;
		node * actors;
		int delete_char(node *& head); // This function will delete the linked list. 
		int display_char(node * head); // This function will display the linked list. 
		int add_new_char(char * data,node * & head); // This function will add to the linked list. 
		int copy_LLL(node * original, node *& copy); // This function will copy the linked list. 
		int delete_character(char * character_name, node * & head); // This function will delete a character from the movie. 
		int compare_actor(char * actor_name,node * head); // This function will compare acters. 
		int compare_character(char * name, node * head); // This function will compare characters. 
};
