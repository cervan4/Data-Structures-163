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
#include "queue.h"
using namespace std;

winning_cards::winning_cards()
{
	rear = NULL;// sets rear to NULL
}
winning_cards::~winning_cards()// dealocates all if the memory from the CLL
{
	delete_all(rear);// calls the function to release all of the memory
}
int winning_cards::enqueue(int cards)// function to add to the circular linked list
{
	if(rear == NULL)// if rear is NULL allocated the first node 
	{
		q_node * tmp = new q_node;// makes new node
		tmp->card = cards;// gives it the value passed in
		tmp->next = tmp;// makes it point to itself
		rear = tmp;// rear is NULL
	}
	else
	{
		q_node * tmp = new q_node;// makes a new node
		tmp->card = cards;//value card
		tmp->next = rear->next;// This code might be wrong :((
		rear->next = tmp;//makes the next point to it
		rear = tmp;// rear gets tmp
	}
	return 1;
}
int winning_cards::dequeue()// deletes the first one
{
	if(rear == NULL) return 0;// checks if its NULL
	if(rear->next == rear)//checks if its to the end if so deletes it and sets it to NULL
	{
		delete rear;//deletes rear
		rear = NULL;// sets it to NULL
	}
	else
	{
		q_node * tmp = rear->next;//makes a tmp one that points to the next one
		rear->next = rear->next->next;// makes it point to the next of the next
		delete tmp;// deletes the node
	}
	return 1;// return one for success
}
int winning_cards::delete_all(q_node * & rear)
{
	if(rear == NULL) return 0;
	if(rear->next == rear)
	{
		delete rear;
		rear = NULL;
	}
	else
	{
		q_node * tmp = rear->next;
		rear->next = rear->next->next;
		delete tmp;
	}
	return delete_all(rear);
}
