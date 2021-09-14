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

int main()
{
	// declares all of the variables
	char tmp[500];
	char * movie;
	char * character;
	char * actor;
	int number_c = 0;
	int number_a = 0;
	int choosing;
	int counting = 0;
	int done = 0;
	int count = 0;	
	movies test;
	movies *  matching_data;
	matching_data = new movies[10];

	movies *  matching_data_actor;
	matching_data_actor = new movies[10];

	table my_table, my_table_actors;
	my_table.read_from_file();
	my_table_actors.read_from_file_actor();
	while(done != 1)
	{
		//Displays all of the options from where they can choose from 
		my_table.display_options();// display options of data they can select from 
		cout<<"1: Add a new movie"<<endl;
		cout<<"2: Add a new character to a movie"<<endl;
		cout<<"3: Search Based on Character"<<endl;
		cout<<"4: Delete Character from movie"<<endl;
		cout<<"5: Display All"<<endl;
		cout<<"6: Get macthing data of character(retrieve)"<<endl;
		cout<<"7: Get macthing data of actor(retrieve)"<<endl;
		cout<<"10: Exit Program"<<endl;
		cin>>choosing;// gets int value of what they want to do
		cin.ignore(500,'\n');
		switch(choosing)// goes to what every case they chose from 
		{
			case 1:// they add a new movie to the hash table
				cout<<"Enter in the name of the movie"<<endl;
				cin.get(tmp,500,'\n');
				cin.ignore(500,'\n');
				movie = new char [strlen(tmp) +1];
				strcpy(movie,tmp);
		
				cout<<"Enter in the number of characters"<<endl;
				cin >>number_c;
				cin.ignore(500,'\n');

				cout<<"Enter in the number of Actor"<<endl;
				cin >>number_a;
				cin.ignore(500,'\n');
				counting = 0;
				count = 0;
				// gets data 
	
				test.new_movie(movie, number_c, number_a);
				while(count < number_c)
				{
					cout<<"Enter in the name of the character"<<endl;
					cin.get(tmp,500,'\n');
					cin.ignore(500,'\n');
					character = new char [strlen(tmp) +1];
					strcpy(character,tmp);
					test.adding_character(character);
					if(counting < number_a)
					{
						cout<<"Enter in the name of the Actor"<<endl;
						cin.get(tmp,500,'\n');
						cin.ignore(500,'\n');
						actor = new char [strlen(tmp) +1];
						strcpy(actor,tmp);
						test.adding_actor(actor);
					}
					count++;
					counting++;
				}
				// Gets data of the character and actor
				my_table.insert(character,test);// puts it inside the hash table
				my_table_actors.insert(actor,test);// puts in inside the actor hash table
				test.remove_characters();// clears the LLL
				test.remove_actors();
				
				break;
		
			case 2://adds a new character to spectfic movie
				cout<<"Enter in the name of the movie"<<endl;
				cin.get(tmp,500,'\n');
				cin.ignore(500,'\n');
				movie = new char [strlen(tmp) +1];
				strcpy(movie,tmp);

				cout<<"Enter in the name of the character you are adding to the film"<<endl;
				cin.get(tmp,500,'\n');
				cin.ignore(500,'\n');
				character = new char [strlen(tmp) +1];
				strcpy(character,tmp);
				my_table.add_new_character(movie,character);// calls function to add new character
				break;		
			case 3:// they seach based om character
				cout<<"Enter in the name of the character"<<endl;
				cin.get(tmp,500,'\n');
				cin.ignore(500,'\n');
				character = new char [strlen(tmp) +1];
				strcpy(character,tmp);
				my_table.search_character(character);// calls function to display all movies with that character
				break;
			case 4:// deletes every movie with the character
				cout<<"Enter in the name of the character you are deleting"<<endl;
				cout<<"This will delete every movie with this character!!"<<endl;
				cin.get(tmp,500,'\n');
				cin.ignore(500,'\n');
				character = new char [strlen(tmp) +1];
				strcpy(character,tmp);
				my_table.delete_searched_character(character);// calls function to delete character
				break;
			case 5:// Displays everything inside the hash table
				my_table.display_all();//call function to display all
				break;
			case 6:// retrieves all the movies with the character name
				cout<<"Enter in the name of the character"<<endl;
				cin.get(tmp,500,'\n');
				cin.ignore(500,'\n');
				character = new char [strlen(tmp) +1];
				strcpy(character,tmp);
				my_table.search_for_character(character,matching_data);// calls functiom
				//matching_data[0].display_movie();//dispays the first thing it retrieved un comment to see
				break;
			case 7:// Retrieve all the movies with the actor
				cout<<"Enter in the name of the Actor"<<endl;
				cin.get(tmp,500,'\n');
				cin.ignore(500,'\n');
				actor = new char [strlen(tmp) +1];
				strcpy(actor,tmp);
				my_table_actors.search_for_actor(actor,matching_data_actor);
				//matching_data_actor[0].display_movie();// display retrieved item uncomment to see
				break;
			

			case 10://exits code
				done = 1;
				break;
		}	
	}	
		return 0;
}
