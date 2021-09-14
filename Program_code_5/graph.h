/*
	Luis Cervantes Oropeza
	6/7/19
	In this program we use a graph an adjacency list of vertices 
	The purpose of this program is to write a scavanger hunt using a graph like this we can connext up vertices and put them into a LLL
*/
#include "scavanger_hunt.h"
struct vertex//
{
	scavenger * option;// ceates a pointer to a class
	struct node * head;//head to a LLL
};
struct node // LLL
{
	vertex * adjacency;// vertex of LLL
	node * next;// next pointer
};
class graph
{
	public:
		graph(int size = 10);// constructor
		~graph();// destructor
		int insert(const scavenger & adding);// inserts into the graph
		int insert_edge();//inserts into the edge 
		int display_possibilities();// displays the possiblilies 
		int display_options(int loop);// displays the rours they can choose from
		
	private:
		vertex * adjacency_list;// vertex to adjacency list
		int list_size = 10;// size of the graph
		int display_possibilities(node * head,int & loop);// resursive function
		int display_options(int loop,node * head,int & count);//recursive function
		int add_at_end(node * & head,vertex &  adding);
	
};
