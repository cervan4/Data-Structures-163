
/*
	Program 4
	5/31/19
	Luis Cervantes
	In this Program we are using a BST as our data structure the purpose is to sort our data based on the character
	the user can add and remove vert easy 
*/
#include "movies.h"
// This is the node stuct for the tree nodes. 
struct b_node
{
	movies film; // object of the class
	b_node * left; // Pointer
	b_node * right; // Pointer
};

// This is the tree class. 
class tree
{
	public:
		tree(); // This is the constructor. 
		~tree(); // This is the destructor. 
		int insert(char * character,movies & adding); // This is the wrapper function that will add a node. 
		int display_all(); // This is the wrapper function to display the data. 
		int display_matching_character(char * character); // This is the wrapper that will display the matching main character. 
		int add_movie_character(char * character, char * movie); // This is the wrapper that will add a movie character. 
		int get_height(); // This is the wrapper to calculate the hieght. 
		int is_balanced(); // This is the wrapper to check if it is balanced. 
		int retrieve_movie(movies * & adding,int & keeping_track,char * character); // this will retrieve the movie data. 
		int delete_film(char * character, char * movie); // This is a wrapper funciton to delete a movie. 
	private:
		b_node * root; // This is the root. 
		int insert(char * character,b_node * & root, movies & adding); // This recursive function to add a movie. 
		int display_all(b_node * root); // This is the recursive function to display all. 
		int display_matching_character(b_node * root, char * character); // This is the recursive function to display by matching character. 
		int add_movie_character(b_node * & root,char * character, char * movie); // This function will add a charaacter to a movie. 
		int get_height(b_node * root); // This function will calculate the hieght. 
		int retrieve_movie(b_node * root, movies * & adding,int & keeping_track,char * character); // This function will retrive the movie data.
		int delete_film(char * character, char * movie, b_node * & root); // This function will delete the movie. 
		int delete_node(b_node * & root); // This function will delete a node. 
		int find_inorder(b_node * & root,b_node * & inorder); // This function will find the in order successor. 
		int remove_all(b_node * & root); // This will deallocate the data. 
};
