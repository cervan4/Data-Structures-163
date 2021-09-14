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
#include <iostream>
#include <cstring>
#include <cctype>
struct q_node// node of a CLL
{
	int card;// card value
	q_node * next;// next pointer
};
class winning_cards// class
{
	public:
		winning_cards();// constructor to set memory
		~winning_cards();// destructor to release all memory
		int enqueue(int cards);// to add ro the CLL at the end
		int dequeue();// deletes the fist thing in the list
	private:
		q_node * rear;// sets rear 
		int delete_all(q_node *& rear);// recursive function to delete all the nodes
};
