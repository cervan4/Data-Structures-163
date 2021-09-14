/*
	Luis Cervantes Oropeza
	6/7/19
	In this program we use a graph an adjacency list of vertices 
	The purpose of this program is to write a scavanger hunt using a graph like this we can connext up vertices and put them into a LLL
*/
#include "graph.h"
using namespace std;
int main()
{
	scavenger test;
	graph my_graph;
	int choice = 0;
	// Sets up variable
	cout<<'\n'<<endl;
	cout<<"PLEASE SELECT ONE OF THE PATHS"<<endl;
	cout<<"ENTER IN 100 TO EXIT"<<endl;
	cout<<'\n'<<endl;
	//Displays options
	my_graph.insert_edge();// inserts into edge 
	my_graph.display_possibilities();// displays possibilities

	while(choice != 100)//exits until the decide
	{
		cin>>choice;// reads in data
		cin.ignore();
		my_graph.display_options(choice);// displays result
	}

	return 0;
}
