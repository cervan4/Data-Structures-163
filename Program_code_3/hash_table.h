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
struct s_node //node
{
	movies film;
	s_node * next;
};
class table 
{
	public:
		table(int size = 5);
		~table();
		int function(char * key);// creates key
		int insert(char * key, movies & film);// inserts into hash table
		int add_new_character(char * film, char * new_character);// adds a new character to movie
		int display_all();// displays all
		int search_character(char * character_name);
		int delete_searched_character(char * character_name);// delets character
		int read_from_file();// reads in data
		int display_options();// displays their options
		int search_for_character(char * character_name, movies * & matching_films);// retrieves data
		int search_for_actor(char * character_name, movies * & matching_films);// retrieve data
		int read_from_file_actor();
	private:
		// sets all of the data
		s_node ** hash_table;
		const int hash_table_size = 5;
		int display_data(s_node * head);
};

