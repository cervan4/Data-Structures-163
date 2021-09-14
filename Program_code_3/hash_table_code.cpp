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
#include "hash_table.h"
using namespace std;
table::table(int size) // constructure to set every index to NULL
{
	int count = 0;
	hash_table = new s_node *[size];// allocates memory
	while(count < hash_table_size)// until its the size of table
	{
		hash_table[count] = NULL;// sets index to NULL
		count++;
	}		

}
table::~table()//desctructure to release all memory 
{
	int count = 0;
	while(count < hash_table_size)//goes index by index releasing all
	{
		while(hash_table[count] != NULL)// checks if its NUll 
		{
			s_node * tmp = hash_table[count];// set tmp
			hash_table[count] = hash_table[count]->next;// goes to next
			delete tmp;//deletes memory
		}
		count++;
	}
}
int table::function(char * key)
{
	// Creates a key for the index
	int total = 0;
	int loop = 0;
	int l = 0;
	while(loop < hash_table_size)
	{
		l = loop * key[loop];
		total += l;
		loop++;
	}
	total = total % hash_table_size;// hashes it by the table size
	return total;	
}
int table::insert(char * key, movies & film)// inserts into the hash table
{
	int value;
	value = function(key);// catches value
	if(hash_table[value] == NULL)// checks if NULL
	{
		hash_table[value] = new s_node;//allocates node
		hash_table[value]->film.copy_movie(film);// copys data 
		hash_table[value]->next = NULL;//sets next to NULL
	}
	else
	{
		s_node * tmp = new s_node;//allocates memory
		tmp->film.copy_movie(film);// copys data
		tmp->next = hash_table[value];// adds to the front
		hash_table[value] = tmp;// gets the value
	}
}
int table::read_from_file()
{
	// makes all of the local variables
	char * movie = NULL;
	int n_characters = 0;
	int n_actors = 0;
	char * character = NULL;
	char * actor = NULL;
	char tmp[500];

	ifstream file_ins("Movies.txt");// reads in from file
	if(file_ins)
	{
		movies test;
		file_ins.get(tmp,500,'\n');
		file_ins.ignore();

		while(!file_ins.eof() && file_ins)// checks if file exists and reads in data until the end
		{
			movie = new char[strlen(tmp) +1];
			strcpy(movie,tmp);

			file_ins >> n_characters;
			file_ins.ignore();

			file_ins >> n_actors;
			file_ins.ignore();

			file_ins.get(tmp,500,'\n');
			file_ins.ignore();
			character = new char[strlen(tmp) +1];
			strcpy(character,tmp);
			test.adding_character(character);

			file_ins.get(tmp,500,'\n');
			file_ins.ignore();
			actor = new char[strlen(tmp) +1];
			strcpy(actor,tmp);
			test.adding_actor(actor);
			//reads In all of the data the file

			
			test.new_movie(movie,n_characters, n_actors);// enters in data
			insert(character,test);//inserts into the hash table
			test.remove_characters();//clears LLL
			test.remove_actors();
			
			file_ins.get(tmp,500,'\n');// checks if there is still data
			file_ins.ignore();
		}
		file_ins.close();
	}
}
int table::read_from_file_actor()
{

	char * movie = NULL;
	int n_characters = 0;
	int n_actors = 0;
	char * character = NULL;
	char * actor = NULL;
	char tmp[500];

	ifstream file_ins("Movies.txt");
	if(file_ins)
	{
		movies test;
		file_ins.get(tmp,500,'\n');
		file_ins.ignore();

		while(!file_ins.eof() && file_ins)
		{
			movie = new char[strlen(tmp) +1];
			strcpy(movie,tmp);

			file_ins >> n_characters;
			file_ins.ignore();

			file_ins >> n_actors;
			file_ins.ignore();

			file_ins.get(tmp,500,'\n');
			file_ins.ignore();
			character = new char[strlen(tmp) +1];
			strcpy(character,tmp);
			test.adding_character(character);

			file_ins.get(tmp,500,'\n');
			file_ins.ignore();
			actor = new char[strlen(tmp) +1];
			strcpy(actor,tmp);
			test.adding_actor(actor);


			
			test.new_movie(movie,n_characters, n_actors);
			insert(actor,test);
			test.remove_characters();
			test.remove_actors();
			
			file_ins.get(tmp,500,'\n');
			file_ins.ignore();
		}
		file_ins.close();
	}
}
int table::add_new_character(char * film, char * new_character)// adds character to individual film 
{
	int value = 0;
	while(value < hash_table_size-1)//loops until it seached every index
	{
		if(hash_table[value] != NULL)// checks if its NULL
		{
			s_node * tmp = hash_table[value];//tmp
			while(tmp != NULL)// loops until its NULL
			{
				int checking = tmp->film.compare_movie(film);// checks if its the movie
				if(checking == 1)
				{
					tmp->film.adding_character(new_character);// calls function to add
				}
				tmp = tmp->next;// goes to next 
			}
		}
		value++;
	}

}
int table::search_for_character(char * character_name, movies * & matching_films)// function to retrieve 
{
	int value = 0;
	int loop = 0;
	value = function(character_name);// gets key value
	s_node * tmp = hash_table[value];// tmp 
	while(tmp != NULL)// until NULL
	{
		int found = tmp->film.compare(character_name);//checks if its the same 
		if(found == 1)
		{
			tmp->film.retrieve_data(matching_films[loop]);// retrieves 
			loop++;	
		}
		tmp = tmp->next;// goes to next
	}
}
int table::search_for_actor(char * actor_name, movies * & matching_films)
{
	int value = 0;
	int loop = 0;
	value = function(actor_name);
	s_node * tmp = hash_table[value];
	while(tmp != NULL)
	{
		int found = tmp->film.compare_actor(actor_name);
		if(found == 1)
		{
			tmp->film.retrieve_data(matching_films[loop]);
			loop++;	
		}
		tmp = tmp->next;
	}
}
int table::search_character(char * character_name)
{
	int count = 0;
	while(count < hash_table_size)// loops
	{
		s_node * tmp = hash_table[count];
		while(tmp != NULL)
		{
			int found = tmp->film.compare(character_name);// compares data
			if(found == 1)
			{
				tmp->film.display_movie();// displays movie
			}
			tmp = tmp->next;// goes to next
		}
		count++;
	}
}
int table::delete_searched_character(char * character_name)// deletes every movie with that name
{
	int value;

	value = function(character_name);// gets valeu
	while(hash_table[value] != NULL)// loops entire index
	{
		s_node * tmp = hash_table[value];//tmp
		hash_table[value] = hash_table[value]->next;// goes to next
		delete tmp;// deletes node
	}
}
int table::display_all()
{
	int value = 0;
	while(value < hash_table_size)// loops every index
	{	
		if(hash_table[value] != NULL)// checks if NULL
		{
			display_data(hash_table[value]);	// calls function to display all
		}
		value++;
	}
	return 0;
}

int table::display_options()// displays their options they can search on
{
	int count = 0;
	while(count < hash_table_size)// loops all index's
	{
		s_node * tmp = hash_table[count];
		while(tmp != NULL)// loops all
		{
			tmp->film.display_option();
			tmp = tmp->next;
		}
		count++;
	}
}
int table::display_data(s_node * head)// displays data inside LLL of the index
{
	if(head == NULL) return 0;
	head->film.display_movie();
	display_data(head->next);
}
