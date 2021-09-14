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
#include "queue.h"
using namespace std;
int card_define(int card);// Prototype
int main()
{
	struct timeval start_time;
	gettimeofday(&start_time, NULL);
	srand(start_time.tv_usec);
	// sets up all of my vatiables	
	int choose;
	int done = 0;
	int machine = 0;
	int player = 0;
	int making_NULL = 0;
	int c_winnings = 0;
	int p_winnings = 0;
	int checking = 0;
	int player_war [500];// array of winning cards
	int computer_war[500];	// array of winning cards
	int exit = 0;
	while(making_NULL < 500)// loop to set each index to NULL
	{
		player_war[making_NULL] = '\0';// sets to NULL
		computer_war[making_NULL] = '\0';// sets to NULL
		making_NULL++;// adds one to the one
	}
	pull_cards test,computer;// creates object
	winning_cards test_winning, computer_winning;// creates object
	int count = 0;
	while(done != 1)// loops until they decide they are done
	{
		// Promps the user their option
		cout<<"1: Draw a card"<<endl;
		cout<<"2: Put down a card (Play card)"<<endl;
		cout<<"3: Count Winnings"<<endl;
		cout<<"10: Exit Program"<<endl;
		cin >> choose;// reads in their option
		cin.ignore(100,'\n');
		cout<<"\n"<<endl;
		switch(choose)// switch statement to go to their option
		{
			case 1:// to draw a card into the stack
				test.push();// pushes card into stack 
				computer.push();// pushes card into stack 
				break;
			case 2:// when thet put down a card to see who won
				player = test.pop();// gets players card value
				machine = computer.pop();// gets card value from the computer
				if(player != -1 && machine != -1)// checks the stack wasnt empty 
				{
					if(machine > player)// if machine was greater then it wins
					{
						cout<<"Computers card was: "<<endl;
						card_define(machine);// says what type of card it was
						cout<<"\n"<<endl;

						cout<<"Player card was: "<<endl;
						card_define(player);// display what type of card it was	
						cout<<"\n"<<endl;
						cout<<"The Computer won"<<endl;
						cout<<"\n"<<endl;
						computer_winning.enqueue(machine);// puts both card into the enqueue
						computer_winning.enqueue(player);// puts cards into enqueue
					}	
					else if( machine == player)// if they both have same value they both go to war
					{
						int flag = 1;//defines flag to endicate when there is a winner 
						while(flag != 0)
						{
							cout<<"\n"<<endl;
							cout<<"You tied you are going to war"<<endl;
							cout<<"\n"<<endl;
							player_war[0] = player;// first index gets value
							computer_war[0] = machine;	
							if(player == -1 && machine == -1) // if they are both null there is no more cards
							{
								cout<<"There are no more cards now count your wins to see who won"<<endl;
								flag = 0;
							}
							else//else it pops 4 cards and see who has the largest card
							{
								int count = 1;
								int counting = 1;
								while(count < 5)// pops 4 cards and puts it into an array
								{
									player = test.pop();// gets card value
									machine = computer.pop();// gets card
									player_war[count] = player;// puts it into an array
									computer_war[count] = machine;	// puts it itno an array
									count++;// adds one
								}
								int player_largest = 0;
								int computer_largest = 0;
								while(computer_war[counting] != '\0')// looks for the largets in the array
								{
									if(computer_war[counting] > computer_largest)
									{
										computer_largest = computer_war[counting];// larger gets a value
									}	
									if(player_war[counting] > player_largest)//checks if its larger 
									{
										player_largest = player_war[counting];// gets larger value
									}
									counting++;// adds one
								}
								if(computer_largest > player_largest)// if cumputer had larger he wins all cards
								{
									cout<<"Computers card was: "<<endl;
									card_define(computer_largest);	
									cout<<"\n"<<endl;

									cout<<"Player card was: "<<endl;
									card_define(player_largest);	
									cout<<"\n"<<endl;
									cout<<"The Computer won"<<endl;
									cout<<"\n"<<endl;
									int track = 0;
									while(computer_war[track] != '\0')// gets all the data from array to the queue
									{
										computer_winning.enqueue(computer_war[track]);
										computer_winning.enqueue(player_war[track]);
										track++;
									//enqueue all of the cards to the winners queue
									}
									flag = 0;// exits the loop
								}	
								else if(computer_largest == player_largest)// if they tied they go to war again
								{
									cout<<"\n"<<endl;
									cout<<"You Tied again"<<endl;// displayed they tied
									cout<<"\n"<<endl;
								}
								else if(computer_largest < player_largest)// if player won the war gets a;l cards
								{
									cout<<"Computers card: "<<endl;
									card_define(computer_largest);
									cout<<"\n"<<endl;
					
									cout<<"Players card was: "<<endl;
									card_define(player_largest);	
									cout<<"\n"<<endl;
									cout<<"The Player won"<<endl;
									cout<<"\n"<<endl;
									int track = 0;
									while(player_war[track] != '\0')// puts all stuff from array to enqueue
									{
										test_winning.enqueue(player_war[track]);// adds data
										test_winning.enqueue(computer_war[track]);// adds data
										track++;
									}
									flag = 0;// exits loop
								}
							}
						}
					}
					else// else it display that player one
					{
						cout<<"Computers card: "<<endl;
						card_define(machine);
						cout<<"\n"<<endl;
		
						cout<<"Players card was: "<<endl;
						card_define(player);	
						cout<<"\n"<<endl;
						cout<<"The Player won"<<endl;
						cout<<"\n"<<endl;
						test_winning.enqueue(player);// puts card into enqueue
						test_winning.enqueue(machine);// puts card into enqueue
					}
				}
				break;

			case 3:
				while(exit != 1)// pops all items until there is no more
				{
					checking = computer_winning.dequeue();// gets value
					if(checking == 1)// if it deleted successfully it adds to their winnings
					{
						c_winnings += checking;// adds to winnings
					}
					else
					{
						exit = 1;// exits loop since its all NULL
					}
				}
				exit = 0;// setx it back to zero
				while(exit != 1)
				{
					checking = test_winning.dequeue();// gets value of success
					if(checking == 1)
					{
						p_winnings += checking;// adds to the count
					}
					else
					{
						exit = 1;// exits loop since its at end
					}
				}
				if(p_winnings > c_winnings)// player won the game since he had more cards
				{
					cout<<"\n"<<endl;
					
					cout<<"Player won this game you had "<<p_winnings<<" cards compared to "<<c_winnings<<
					" computers cards"<<endl;// display winner message

					cout<<"\n"<<endl;
				}
				else if(p_winnings == c_winnings)// if they are the same the tied the game
				{
					cout<<"\n"<<endl;
					
					cout<<"This was a tied game"<<endl;// display they tied

					cout<<"\n"<<endl;

				}
				else// else that means computer won the game
				{
					cout<<"\n"<<endl;
					
					cout<<"Computer won it had "<<c_winnings<<" cards compared to "<<p_winnings<<
					" Players cards"<<endl;// displays that winner won
					cout<<"\n"<<endl;

				}
				break;
				
			case 10:// if they are done with the program
				done = 1;// exits loop
				break;
		}
	}
	return 0;
}
int card_define(int card)// gives each card their own value as card
{
	if(card == 1)// if one its an Ace card
	{
		// displays value of card
		cout<<"Your card was an Ace"<<endl;
	}
	else if(card == 11)// if its an 11 its a jake
	{
		// displays value of card
		cout<<"Your card was an Jake"<<endl;
	}
	else if(card == 12)// teh card is a queen
	{
		// displays value of card
		cout<<"Your card is a Queen"<<endl;
	}
	else if(card == 13)// card is a king
	{
		// displays value of card
		cout<<"Your card is a King"<<endl;
	}
	else// else its just a number card
	{
		// displays value of card
		cout<<"Your card is a  "<<card<<endl;
	}
}
