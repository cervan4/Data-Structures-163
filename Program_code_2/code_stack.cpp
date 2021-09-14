/*
	Luis Cervantes
	5/3/19
	Program 2
	Spring Term 2019
	In this program we are playing a card game war where 2 players but downa card and see who has the largest card and winner takes both cards
	if they tie they both go to war where they each put down 4 card and see who had the largest card. At the end when they got no cards 
	left they count their winnings to see who won.
	In this program we are working with array of LLL where every node has a array the data structure we using are stacks and queues
	the stack is the array of LLL where every index has an object of the card. While for the queue we are using a CLL to add the winners
	cards. With the stack we are removing from the top and with the queue we remove the first item in the list.

*/
#include "stack.h"
using namespace std;
pull_cards::pull_cards()// constructor
{
	head = NULL;// sets head to NULL
	top = 0;//sets top to zero
	
	int count = 0;
	while(count < 10)// pushes 10 card into the stack 
	{
		push();// calls push function
		count++;// adds one to count
	}
}
pull_cards::~pull_cards()//dealocates all of the memory
{
	delete_all(head);// calls the function to delete all the nodes
}
int pull_cards::push()// Push function to add to the stack
{
	if(head == NULL)// if head is NULL
	{
		head = new node;// make new node
		head->card = new card_game[MAX];//  makes the artay inside the node
		head->card[top].get_card();// gets the card and puts it inside the index
		head->next = NULL;// set next to NULLl
	}
	else if(top == MAX - 1)//checks if top is already max and if so creates a new node
	{
		top = 0;// resets top back to 0
		node * tmp = new node;// new node
		tmp->card = new card_game[MAX];// new node of array
		tmp->card[top].get_card();// sets card
		tmp->next = head;// adds it to the front of the list
		head = tmp;
	}
	else
	{
		top++;// adds one to the top
		head->card[top].get_card();//gets card 
	}
}
int pull_cards::pop()// removes the most recent thing in the stack
{
	if (head == NULL) return -1;// if its empty return -1 to knoq its empty
	if(top > 0)// if top is creater than zero
	{
		int tmp = head->card[top].get_back_card();// gets value of card
		top--;// removes one from the top
		return tmp;// return card value
	}
	else if(top == 0)// if top is zero it removes the entire node
	{
		int data = head->card[top].get_back_card();// gets value of card before removed
		node * tmp = head;// tmp points to head
		head = head->next;// traverses to next node
		delete tmp;// delets tmp
		top = MAX - 1;// sers top back to max

		return data;
	}
}
int pull_cards::display_all()
{
	head->card[top].display();// displays the most recent card in the stack so the top one
}
int pull_cards::delete_all(node * & head)// function to remove all nodes
{
	if(head == NULL) return 0;// if NULL exits recursive call
	node * tmp = head;// tmp points to head
	head = head->next;// traverses to next node
	delete tmp;// deletes tmp
	return delete_all(head);// calls recursive function
}
