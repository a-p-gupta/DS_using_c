// representation of graph by adjacency of list 
// adjacency list of directed and undirected graph 
#include <stdio.h>
#include <conio.h>

struct linked
{
	int vertex;
	struct linked *next;
};

struct graph
{
	int v; 		// vertexes
	int e;		// edges
	struct linked *adj;	// linked type pointer , who points vertex and their edges
};

struct graph* adjacencyList()
{
	int i,x,y;
	struct graph *g;		// first we create graph pointer 
	struct linked *temp , *t;
	g=(struct graph*)malloc(sizeof(struct graph));	// create graph variable dynamically
	printf("\nEnter a number of vertex : ");
	scanf("%d",&g->v);
	printf("\nEnter a number of edges : ");
	scanf("%d",&g->e);
	g->adj=(struct linked* )malloc(sizeof(struct linked)*g->v);	// create linked array to points each vertex and their edges
	
	for(i=0;i<g->v;i++)
	{
		t=(g->adj+i);
		t->vertex=i;				// we assign values in vertex of linked variable
		t->next=g->adj+i;			// pointer next member variable of linked points itself
	}

	printf("\n\n\n\t\tEnter vertex connected by edges \n");
	for(i=0;i<g->e;i++)
	{
		printf("\nEnter vertex connected by e%d : ",i);
		scanf("%d%d",&x,&y);
		temp=(struct linked*)malloc(sizeof(struct linked)); // we create new linked variable dynamically
		temp->vertex=y;				// a edges points two nodes x-----y , x is vertex who is already created, we create a y and assigning value of second node
		temp->next=g->adj+x;		//  second node means y variable points x through next pointer of y variable
		
		for(t=g->adj+x;t->next != g->adj+x;t=t->next);		// we find last node of x variable pointing
		t->next=temp;				// now, here we joint the  x and y , we assign the y variable address to x->next pointer
		
		
		/*
		temp=(struct linked*)malloc(sizeof(struct linked));
		temp->vertex=x;
		temp->next=g->adj+y;
															// by removing this comment we create adjacency list of  undirected graph 
		for(t=g->adj+y;t->next != g->adj+y;t=t->next);
			t->next=temp;
			viewGraph(g);
		*/
	}
	printf("\nGraph create successfully ");
	return g;
}

void viewGraph(struct graph *g)
{
	 struct linked *t;
	 int i;
	 printf("\n\n\n\t View Graph \n\n");
	for(i=0;i<g->v;i++)
	{
	t=g->adj+i;
	do
	{	
		printf("\t %d =>",t->vertex);
		t=t->next;
	}while(	t != g->adj+i);
	printf("NULL\n");
	}
	getch();
}

void main()
{
	struct graph *g;
	g=adjacencyList();
	viewGraph(g);
}
