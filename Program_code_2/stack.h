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
#include "card_game.h"
#include <iostream>
struct node// node of LLL of arrays
{
	card_game * card;// object of card
	node * next;	// next pointer	
};
const int MAX = 5;// max for stack 
class pull_cards
{
	public:
		pull_cards();// constructor for setting up the LLL of Arrays
		~pull_cards();// dealocates all of memory from the LLL of array
		int push();// adds data to the top of the stack
		int pop();// removes the top thing from the stack 
		int display_all();// displays the top item of the list
	private:
		node * head;// set head
		int top;// for top index
		int delete_all(node *& head);// to dealocate all the nodes
};
