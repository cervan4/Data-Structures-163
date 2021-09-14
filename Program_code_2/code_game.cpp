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
using namespace std;
card_game::card_game()//Constructor sets the value of card to zero
{
	card = 0;// sets value to zero
}
card_game::~card_game()//destructor 
{
	card = 0;// sets card to zero again
}
int card_game::get_card()
{
	card = rand() % 13;// randomizes number to get value of card
	if(card == 0)// if card is equals zero it sets it to 13 since we are using the mod that would mean zero would be 13
	{
		card = 13;// card value to 13
	}
	return card;// returns the value of the card
}
int card_game::display()
{
	cout<<card<<endl;// displays the value of the card
}
int card_game::get_back_card()
{
	return card;// returns card value
}
