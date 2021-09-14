
/*
	Program 4
	5/31/19
	Luis Cervantes
	In this Program we are using a BST as our data structure the purpose is to sort our data based on the character
	the user can add and remove vert easy 
*/
#include "bst.h"
using namespace std;
tree::tree()
{
	root = NULL;// sets root to NULL
}
tree::~tree()
{
	remove_all(root);// calls function to remove all
}
int tree::insert(char * character, movies & adding)// wrapper function to insert into the BST
{
	insert(character, root,adding);// calls function to insert
}
int tree::insert(char * character,b_node * & root, movies & adding)// function to insert into the BST
{
	if(root == NULL)// if root is NULL
	{
		b_node * tmp = new b_node;// new node
		tmp->film.copy_movie(adding);// calls function to copy data in
		tmp->left = tmp->right = NULL;// sets the left and right to NULL
		root = tmp;// root gets value tmp
	}
	else // else it traverses 
	{
		int value = root->film.sorting_bst(character);// checks if it goes to right or left
		if(value == 1)// checks if value is one if so goes to the right
		{
			insert(character,root->right,adding);// traverses to the right 
		}
		else
		{
			insert(character,root->left,adding);// traverses to the left if smaller
		}
	}
}
int tree::add_movie_character(char * character, char * movie)// adds a new movie character to a certain movie
{
	add_movie_character(root,character,movie);// calls recursive function
}
int tree::add_movie_character(b_node * & root,char * character, char * movie)//function to add new character
{
	if(root == NULL) return 0;// if NULl exits function
	add_movie_character(root->left, character, movie);//traverses all the way to the right tree
	int value = root->film.compare_movie(movie);// return a one if its thet right movie
	if(value == 1)
	{
		root->film.adding_character(character);// adds a new character to the LLL in the movie class
		return 1;// exits 
	}	
	add_movie_character(root->left, character, movie);//traverses to the right subtree
}
int tree::delete_film(char * character, char * movie)// function to delete a film
{
	delete_film(character,movie,root);// recursive function to delete the film
}
int tree::delete_film(char * character, char * movie, b_node * & root)
{
	if(root == NULL) return 0;// if null exits
	int value = root->film.compare_movie(movie);
	if(value == 1)
	{
		int main = root->film.compare(character);// checks if main character is the same if so return 1
		int values = root->film.compare_character(character);// checks all the characters if so return 1
		if(main == 1 || values == 1)// if either are the same deletes it
		{
			delete_node(root);//calls function to delete the node
			return 1;
		}
	}
	delete_film(character,movie,root->left);// traverses to the left
	delete_film(character,movie,root->right);// traverses to the right
}
int tree::find_inorder(b_node * & root,b_node *& inorder)// finds the in order succesor on the right subtee
{
	if(inorder == NULL) return 0;// exits code if the same
	if(inorder->left == NULL && inorder->right == NULL)// if its at a leaf 
	{
		b_node * temp = inorder;// tmp node
		inorder->left = root->left;// gets the value on the right
		delete root;// deletes the parent
		root = inorder;// the inorder becomes the parent
		return 1;//exits
	}
	find_inorder(root,inorder->left);// traverses all the way to the right
}
int tree::delete_node(b_node * & root)// deletes the node function
{
	if(root == NULL) return 0;// exits code
	if(root->left == NULL)// if the left is NULL
	{
		b_node * tmp = root;// tmp node
		root = root->right;// root gets the value on the rightk
		delete tmp;
	}
	else if(root->right == NULL)// if the right is NULL
	{
		b_node * tmp = root;// tmp node
		root = root->left;// root gets the left
		delete tmp;	
	}
	else if(root->left != NULL && root->right != NULL)// if it has two children
	{
		find_inorder(root,root->right);//goes to find the inorder
		return 1;//exits
	}
	else//if only one
	{
		delete root;//delete root
		root = NULL;// sets to NULl
	}
}
int tree::retrieve_movie(movies * & adding,int & keeping_track, char * character)// retieves data of certain character
{
	retrieve_movie(root,adding,keeping_track,character);//calls function
}
int tree::retrieve_movie(b_node * root, movies * & adding,int & keeping_track,char * character)//function to retrieve function
{
	if(root == NULL) return 0;// if NULL exits
	retrieve_movie(root->left,adding,keeping_track,character);//traverses to the right
	int main = root->film.compare(character);// gets value of character
	int value = root->film.compare_character(character);// all the charcters
	if(main == 1 || value == 1)// if the character is found it retrieves it
	{
		root->film.retrieve_data(adding[keeping_track]);//calls function
		keeping_track++;//adds to the index
	}
	retrieve_movie(root->left,adding,keeping_track,character);// goes to the right
}
int tree::is_balanced()// checks if they are balanced
{
	int left = get_height(root->left);// gets height of the left
	int right = get_height(root->right);// gets height of the right
	if(left == right)// if they are the same its true
	{
		return 1;
	}
	else//else return false
	{
		return 0;
	}
}
int tree::get_height()// function to get height
{
	int length = get_height(root);// gets the length
	return length;//return length
}
int tree::get_height(b_node * root)
{
	if(root == NULL) return 0;// if NULL exits
	int left = get_height(root->left);// goes to the left tree
	int right = get_height(root->right);// right sub tree
	if(left > right)// if left is greater add to the left
		return left + 1;
	else
		return right + 1;// if right is greater adds to the right
}
int tree::display_matching_character(char * character)// displays all the data that has same charcter
{
	display_matching_character(root,character);//calls function
}
int tree::display_matching_character(b_node * root, char * character)// displays matching character
{

	if(root == NULL) return 0;// exits 

	display_matching_character(root->left,character);//goes to the left
	int main = root->film.compare(character);// checks if character is there
	int value = root->film.compare_character(character);// checks rest of characters
	if(value == 1 || main == 1)// if either are true displays data
	{
		root->film.display_movie();// display function
	}
	display_matching_character(root->right,character);// goes to the right
}
int tree::remove_all(b_node * & root)// removes all functions
{
	if(root == NULL) return 0;// exits code
	remove_all(root->left);// goes to the left
	remove_all(root->right);// right subtee
	delete root;// delets the node
	root = NULL;// sets to NULL
}
int tree::display_all()//function to display all
{
	display_all(root);// calls function
}
int tree::display_all(b_node * root)// recursive function to display all in order
{
	if(root == 0) return 0;// exits code
	display_all(root->left);// goes to the left
	root->film.display_movie();// display film
	display_all(root->right);// to the right
}
