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
#include <cstdlib>
#include <sys/time.h>
// defines all of my libray
class card_game
{
	public:
		card_game();// constructor
		~card_game();// destructor
		int get_card();// sets card a value
		int display();// display card
		int get_back_card();// return the card
	private:
		int card;// cardj
};
