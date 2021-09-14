#include <cstring>
/*
	Luis Cervantes Oropeza
	4/19/19
	CS 163 
	Program 1
	The data structure that is being used for program 1 is a LLL of LLL
	
	In this program most of the functions all done recursive 	

	The purpose of this program is so that the user deosnt know what data structure is being used since its a ADT program
	In This program the user can create a category and add to the category of their wish 
	When the name is entered the name of category are in sorted order at all time.
	The user can add/ remove category and display the category and siplay all 
	As well rhey can swap the location of the item thats inside the LLL
*/
#include <cctype>
#include <iostream>
struct node// struct node for items of the category
{
	char * data;// dynamic char
	node * next;// next pointer
};
struct category_node// category node
{
	char * category;// dynamic memory
	category_node * next;// next pointer
	node * head;// pointer to the head of the LLL of items
};
class trip// class for all of the categorys
{
	public:
		trip();// constructor
		~trip();// desctructor
		int new_category(char * category1);// function make a new category
		int add_to_category(char * adding,char * category1);// function to add a new item in category
		int edit_the_location(char * category1, int position, char * looking_for);// edit the location of the function
		int remove_category(char * category1);// remove category function
		int display_category(char * category1);// display category function wrapper
		int display_all();// diplsy all wrapper
	private:
		char temp[1000];// tmp char array
		category_node * head;// head pointe of category
		category_node * tail;// tail pointer
		int add_to_category(char * adding, char * category1,category_node *& head);// recursive function to add category
		int display_category(char * category1,category_node * head);// display category recursive
		int display_category_data(node * current);// display items in category recursive function
		int display_all(category_node * head);//display all recursive function
		int remove_category(char * category1, category_node * & head);	// remove category function recursive
		int sorted_order(category_node *& head, char * info);// sort in order recusive function
		int add_at_end_item(char * category, node * & current);//add items of a category to the end of a LLL reccursive function
		int delete_list(node * & current);//deletes the items of the category recursive function
		int delete_all(category_node * & head);// delets all recursive
};
