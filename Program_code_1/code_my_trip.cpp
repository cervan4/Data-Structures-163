#include "my_trip.h"
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
using namespace std;
trip::trip()// The constructor
{
	head = NULL;// Sets head to NULL
}
trip::~trip()// dealocates all of the memory
{
	delete_all(head);// calls the function to delete all of the data
	delete head;
}
int trip::new_category(char * category1)// Function to add a new category
{
	strcpy(temp,category1);//copts in the data that is passed in to tmp
	char * info;
	info = new char[strlen(temp) + 1];// allocates memory
	strcpy(info,temp);// copys data to char 

	if(head == NULL)// check if head is NULL and if so it creats a new LLL
	{
		category_node * tmp = new category_node;// makes a new category node
		tmp->category = info;// adds the data
		tmp->next = NULL;// sets next to NULL
		head = tmp;// head is set to the tmp
	}
	else
	{
		sorted_order(head,info);// else it calls the function that sets the data in sorted order
	}

}////////////////////////////////////////////////////////////

int trip::sorted_order(category_node *& head,char * info)// sorts the LLL in order recursive
{
	if(head == NULL) return 0;// checks if its NULL and if so exits
	if(head->next != NULL)
	{
		char value1;
		char value2;
		value1 = head->category[0];// value 1 gets the value from the first index
		value2 = head->next->category[0];// value 2 get the value of the next index
		if(info[0] <= value1)// check if the value passed in is less than the other there if so it adds to the front
		{
			category_node * adding = new category_node;// makes a new node
			adding->category = info;// sets data
			adding->next = head;// Adds to the front
			head = adding;
			return 1;// return 1
		}
		else if(value2  >= info[0] && value1 < info[0])// else checks if the node its at and the next are less and greater than 
		{// the one there and if so adds to it
			category_node * adding = new category_node;// allocates memory
			adding->category = info;
			adding->next = head->next;// adds infront of the node
			head->next = adding;// next gets the value tmp
			return 1;
		}
	}
	else if(head->next == NULL)// if next is NUULL so at the end of the LLL
	{
		
		char value1;
		value1 = head->category[0];// gets the value from the first index
		if(info[0] <= value1)// if its less then it adds infront of it
		{
			category_node * adding = new category_node;
			adding->category = info;
			adding->next = head;// the only change needed
			head = adding;
			return 1;
		}
		else// else it adds to the end of the linked list meaning its the largest item at the timw
		{
			category_node * adding = new category_node;// makes new node
			adding->category = info;
			adding->next = NULL;// tsets nexr to NULL
			head->next = adding;
			return 1;
		}
	}
		sorted_order(head->next,info);// recursive call
}

int trip::add_to_category(char * adding, char * category1)// Wrapper function to add to a category
{
	add_to_category(adding,category1,head);// calls recursive function 
}
int trip::add_to_category(char * adding, char * category1,category_node *& head)// adds new items to a category
{
	if(head == NULL) return 0;// checks if NULL
	if(strcmp(category1,head->category) == 0)// checks if data the same
	{
		if(head->head == NULL)// checks if head is NULL and if so it creates a new LLL
		{
			node * tmp = new node;// allocates memory
			tmp->data = adding;
			tmp->next = NULL;// sets next to NULL
			head->head = tmp;
			return 1;	
		}
		else// else it calls function to add at the end
		{
			
			add_at_end_item(adding,head->head);// calls recursive function to add at end 	
		}
	}
	else
	{
		add_to_category(adding,category1,head->next);// recursice function to traverse to next node
	}
}
int trip::add_at_end_item(char * adding, node * & current)// adds to the end of the LLL of items
{
	if(current == NULL) return 0;// checks if NULL
	if(current->next == NULL)// checks if at the end
	{
		node * tmp = new node;	// allocates memory
		tmp->data = adding;
		tmp->next = NULL;// points to NULL
		current->next = tmp;
		return 1;
	}
	else
	{
		add_at_end_item(adding,current->next);	// if not at end calls recursive function
	}
}
int trip::edit_the_location(char * category1, int position, char * looking_for) // function to move position of item in category
{
	category_node * current = head;	// makes current node
	while(strcmp(category1,current->category) != 0 && current != NULL)// traverses until it finds it
	{
		current = current->next;
	}
	// tmp nodes
	if(current->head->next == NULL)
	{
		return 0;
	}
	node * looking = current->head;
	node * previous = NULL;
	node * tmp = NULL;
	int found = 0;// to know if item is founf
	int count = 1;
	if(strcmp(looking_for,looking->data) != 0)
	{
		while(found != 1 && looking != NULL)// loop to look for the datat
		{
			if(strcmp(looking_for,looking->data) == 0)// checks if the data is the same
			{
				// if fouund sets pervious pointer to the next pointer of current
				previous->next = looking->next;
				tmp = looking;// tmp is looking
				found = 1;// exits loop
			}
			else// else it traverses to next node
			{
				previous = looking;// updates previous
				looking = looking->next;// next node
			}
		}
	}
	else if(strcmp(looking_for,looking->data) == 0)// if data is the first node 
	{
		found = 1;// lets it know that its found
		count++;// adds one to count to add it to the right order
		current->head = current->head->next;// goes to the next node	
	}
	if(found == 1)// if item is found
	{
		if(position <= 1)// if position is one it moves it to the front
		{
			looking->next = current->head;// adds the data to the front
			current->head = looking;// sets head to looking
		}
		else
		{
			if(position == 2)// if position is 2 it adds to the front of the node
			{
				looking->next = current->head->next;// the data we want to move to the next
				current->head->next = looking;// sets head->next to looking
			}
			else// else it traverses to the location*/
			{
				node * tmp = current->head;// tmp node
				while(count < position && current->head->next != NULL)// while it find the position and its not NULL
				{
					tmp = tmp->next;// traverses
					if(tmp->next == NULL)// if next is NULL it exits loop
					{
						count = position;// it exits loop
					}
					else
					{
						count++;// else it traverses again
					}
				}
				if(tmp->next != NULL)// if at end it adds to the end
				{
					looking->next = tmp->next;// adds to specifc location
					tmp->next = looking;
				}
				else
				{
					looking->next = NULL;// adds at end
					tmp->next = looking;
				}
			}
			
		}
	}
}
int trip::delete_list(node * & current)// deletes items from category recursive
{
	if(current == NULL) return 0;// checks if NULL 
	if(current->data)// if there is data 
	{
		delete [] current->data; // dealocates data
	}

	node * tmp = current;// tmp node
	current = current->next;// current points to next node 
	delete tmp;// delets current

	delete_list(current);// recursive function call
}

int trip::delete_all(category_node * & head)// delets all the data
{
	if(head == NULL) return 0;// checks if NULL
	delete_list(head->head);// calls function to delete all
	if(head->category)// if there is data 
	{
		delete [] head->category; // dealocates data
	}

	category_node * tmp = head;//tmp node
	head = head->next;
	delete tmp;//deletes node
	delete_all(head);// calls recursive call
}
int trip::remove_category(char * category1)// wrapper function to delete all
{
	remove_category(category1,head);// calls recursive functio
}
int trip::remove_category(char * category1, category_node * & head)// removes certain category
{
	if(head == NULL) return 0;// checks if NULL
	if(strcmp(category1,head->category) == 0)//checks if data is the same
	{
		delete_list(head->head);// calls function to delete all
		category_node * tmp = head;// tmp node
		head = head->next;
		delete tmp;//delete memory
		return 1;
	}
	else
	{
		remove_category(category1,head->next);// else it traverses to next
	}
}
int trip::display_category(char * category1)//display category wrapper function
{
	display_category(category1,head);// calls display function	
}
int trip::display_category(char * category1,category_node * head)//display specific functions
{
	if(head == NULL) return 0;// checks if NULL
	if(strcmp(category1,head->category) == 0)// ckecks if they are the same
	{
		category_node * tmp = head;	

		cout<<'\n'<<endl;

		cout<<"Category: "<<tmp->category<<endl;// displays name of the category	
		display_category_data(tmp->head);// calls function to diplay all inside the list 

		cout<<'\n'<<endl;
		return 1;	
	}
	else
	{
		display_category(category1,head->next);// else it traverses
	}
}
int trip::display_category_data(node * current)// display items in category recursive
{
	if(current == NULL) return 0;// chekcs if NULL
	cout<<"Item: "<<current->data<<endl;// prints data
	display_category_data(current->next);// recursive call
}
int trip::display_all()// wrapper function to display all
{
	display_all(head);// display all function call resursive
}
int trip::display_all(category_node * head)//recursive
{
	if(head == NULL) return 0;// if NULL
	category_node * tmp = head;	
	cout<<'\n'<<endl;

	cout<<"Category: "<<head->category<<endl;// prints category
	display_category_data(tmp->head);// calls function to display items

	cout<<'\n'<<endl;
	display_all(head->next);//traverses to next node
}
