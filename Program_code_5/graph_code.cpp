/*
	Luis Cervantes Oropeza
	6/7/19
	In this program we use a graph an adjacency list of vertices 
	The purpose of this program is to write a scavanger hunt using a graph like this we can connext up vertices and put them into a LLL
*/
#include "graph.h"
using namespace std;
graph::graph(int size)
{
	adjacency_list = new vertex[size];// allocates array of vertices
	int loop = 0;
	while(loop < size)// sets all data to NULL
	{
		adjacency_list[loop].option = NULL;// to NULL
		adjacency_list[loop].head = NULL;// to NULL
		loop++;//adds one
	}
	char tmp[500];
	char * option;
	char * result;
	scavenger test;
	//sets up variables
	ifstream file_ins("Scavanger.txt");// reads in from file
	loop = 0;
	if(file_ins)
	{
		file_ins.get(tmp,500,':');// primes the pump
		file_ins.ignore();
		loop++;

		while(!file_ins.eof() && file_ins)// checks if file exists and reads in data until the end
		{
			option = new char[strlen(tmp) +1];//allocates memory
			strcpy(option,tmp);// copys

			file_ins.get(tmp,500,'\n');//reads in data
			file_ins.ignore();

			result = new char[strlen(tmp) +1];//allocates memory
			strcpy(result,tmp);//copys data

			test.new_outcome(result,option);//adds to class
			insert(test);//inserts into graph
			loop++;

			file_ins.get(tmp,500,':');
			file_ins.ignore();
		}
	}
}
graph::~graph()
{
	int i = 0;
	while(i < list_size)//deletes all of the data in the graph
	{
		if(adjacency_list[i].option != NULL)//checks if its not NULL
		{
			if(adjacency_list[i].head != NULL)//checks if head is NULL
			{
				while(adjacency_list[i].head != NULL)
				{
					node * tmp = adjacency_list[i].head;// makes a tmp varianle
					adjacency_list[i].head = adjacency_list[i].head->next;//points it to the next one
					delete tmp;//deletes the memory
				}
			}
		}
		i++;
	}

}
int graph::insert(const scavenger & adding)
{
	int loop = 0;
	while (loop < list_size)// traverses entire array
	{
		if(adjacency_list[loop].option == NULL)// sets to NULL
		{
			adjacency_list[loop].option = new scavenger;// allocates memory
			adjacency_list[loop].option->copy(adding);// copys data
			loop = list_size;// exits loo[p
		}
		else
		{
			loop++;// adds to lopp
		}
	}
}
int graph::insert_edge()//inserts into the edge
{
	if(adjacency_list[9].option == NULL) return 0;// sets if NULL
	int loop = 0;
	while(loop <= 8)//
	{
		if(adjacency_list[9].head == NULL)// if head is NULL
		{
			node * tmp = new node;//allocates memory
			tmp->adjacency = &adjacency_list[loop];//gets data
			tmp->next = NULL;// sets to NULL
			adjacency_list[9].head = tmp;// gets tmp value
		}
		else
		{
			//add_at_end(adjacency_list[9].head,adjacency_list[loop]);
			node * tmp = adjacency_list[9].head;//tmp node
			while(tmp->next != NULL)
			{
				tmp = tmp->next;
			}
			node * temp = new node;// new node
			temp->adjacency = &adjacency_list[loop];// gets data
			temp->next = NULL;// insets at head
			tmp->next = temp;// gets value
			//adjacency_list[9].head = temp;// gets value
		}
		loop++;
	}
}
int graph::add_at_end(node * & head,vertex & adding)
{
	if(head == NULL) return 0;
	if(head->next == NULL) 
	{
			node * tmp = new node;// new node
			//tmp->adjacency = adding;// gets data
			tmp->next = NULL;// insets at head
			head->next = tmp;// gets value	
			return 1;
	}
	add_at_end(head->next,adding);
}
int graph::display_possibilities(node * head,int & loop)// recursve function
{
	if(head == NULL) return 0;// checks if NULl
	cout<<loop<<":"<<endl;// dispplays
	head->adjacency->option->display_option();// displays option
	loop++;//adds one
	display_possibilities(head->next,loop);//recursive call
}
int graph::display_possibilities()
{
	if(adjacency_list[9].option == NULL) return 0;// checks if NULL
	int loop = 1;
	cout<<"1: "<<endl;
	adjacency_list[9].option->display_option();// displays option
	node * tmp = adjacency_list[9].head;//tmp node
	loop++;// adds to loop
	display_possibilities(tmp,loop);// calls recursive function
}
int graph::display_options(int loop)
{
	int count = 0;
	if(adjacency_list[9].option == NULL) return 0;// if NULL exits
	node * tmp = adjacency_list[9].head;// tmp node
	if(loop == 1)
	{
		loop = loop -1;
	}
	else
	{
		loop = loop -2;
	}
		//loop = (loop -9) * -1;// traverses to the right one
	display_options(loop, tmp,count);// calls recursive function
}
int graph::display_options(int loop,node * head,int & count)//displays options recursive function
{
	if(head == NULL) return 0;// if NULL exits
	if(loop == count)// if they traversed to the proper one
	{
		head->adjacency->option->display_result();// diplays result
	}
	count++;// adds one
	display_options(loop,head->next,count);//recurive call
}
