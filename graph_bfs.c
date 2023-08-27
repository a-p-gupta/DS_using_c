
// linear representation of graph 
// Adjacency  matrix of undirected list & directed list
// breadth first search   * BFS also called level order traversing
#include <stdio.h>
#include <conio.h>
#include <stdbool.h>
struct graph
{
	int v;
	int e;
	int **adj;
	int *visit;
};

struct queue
{
	int *q, start, rear,size;
};

//--------------------------------creating graph--------------------------------------------------
struct graph* adjacencyMatrix()
{
	int u,v,i;
	struct graph *g;
	g=(struct graph*)malloc(sizeof(struct graph));	// creating dynamically graph variable
	printf("\nEnter number of vertex : ");
	scanf("%d",&g->v);
	printf("\nEnter number of edge : ");
	scanf("%d",&g->e);
	
	g->adj=(int*)malloc((g->v)*sizeof(int));		// creating 1d array
	g->visit=(int*)malloc((g->v)*sizeof(int));
	
	for(i=0;i<g->v;i++)
	{
		g->adj[i]=(int*)malloc(sizeof(int)*g->e);	// creating 2D array by assigning 1d array in each index of 1D array created above
		g->visit[i]=0;
	}
		
	
	for(u=0;u<g->v;u++)
		for(v=0;v<g->e;v++)							// assigning 0 in 2D arrray
			g->adj[u][v]=0;
		
	viewGraph(g);
	printf("\nEnter u and v of edges ");
	for(i=0;i<g->e; i++)
	{
	printf("\ne%d : ",i);							// assigning edges connecting nodes
	scanf("%d%d",&u,&v);
	g->adj[u][v]=1;
	g->adj[v][u]=1;									// by commenting this line we create adjacency matrix of directed list
	}
	printf("\nGraph create successfully \n");
	
	return g;
}

//----------------------------queue functions --------------------------------------
struct queue* createQueue()				// create variable of queue
{
	struct queue *q;
	q=(int*)malloc(sizeof(int)*50);
	q->start=-1;
	q->rear=-1;
	q->size=50;
	return q;
}
void addElementQueue(struct queue *qu,int a)		// add element in queue
{
	if(qu->rear == qu->size-1)
	{
		printf("\nqueue is empty");
		return;
	}
	if(qu->start==-1)
		qu->start++;
	qu->q[++qu->rear]=a;
	printf("\n%d add in queue",a);
}

int removeElementQueue(struct queue *q)			// remove element of queue
{
	int r;
	if(q->start== -1 || q->start>q->rear)
	{
		printf("\nqueue is empty");
		return;
	}
	else
	{
		r=q->q[q->start++];
		printf("\n%d remove from queue ",r);
		return r;
	}
}

int isEmpty(struct queue *q)				// checks queue is empty or not
{
	if(q->rear == -1 || q->start>q->rear)
	return 1;
	else 
	return 0;
}


//-------------------------------create BFS traverse function--------------------------------------
void bfs(struct graph *g)
{
	int i,j ;
	struct queue *q;
	q=createQueue();				// we create a queue
		for(j=0;j<g->v;j++)
		g->visit[j]=1;				// step 1 => Initialise all to be in ready state [status 1 ] 
		
	addElementQueue(q,0);			// step 2=>add first node in a queue to be traverse, and change it state to waiting state [status 2]
		g->visit[0]=2;
		
	while(!isEmpty(q))
	{
		j=removeElementQueue(q);	// step 3=> Removing element from queue, and cjange it state to processing state [status 3]
		g->visit[j]=3;
		viewVisit(g);	
		for(i=0;i<g->v;i++)
		{
			printf("\t for");
			if( g->adj[j][i]==1 && g->visit[i]==1)
			{
					addElementQueue(q,i);	// step 4 => add all direct connected /neighbors  nodes in a queue which are in ready state
					g->visit[i]=2;
			}
		}
	}
		viewVisit(g);
}

//-------------------------------------View Graph------------------
void viewGraph(struct graph *g)
{
	int u,v;
	for(u=0;u<g->v;u++)
	{
		for(v=0;v<g->v;v++)
		printf("\t %d",g->adj[u][v]);
		printf("\n");
	}
}

void viewVisit(struct graph *g)
{
	int i,j;
	for(i=0;i<g->v;i++)
	{
		printf("\t %d",g->visit[i]);
	}
}
void main() 
{
 struct graph *g;
 g=adjacencyMatrix();	
 viewGraph(g);
 bfs(g);
 viewVisit(g);
 printf("\n main");
}
