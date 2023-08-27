
// linear representation of graph 
// Adjacency  matrix of undirected list & directed list
#include <stdio.h>
#include <conio.h>

struct graph
{
	int v;
	int e;
	int **adj;
};

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
	
	for(i=0;i<g->v;i++)
		g->adj[i]=(int*)malloc(sizeof(int)*g->e);	// creating 2D array by assigning 1d array in each index of 1D array created above
		
	
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
	viewGraph(g);
	}
	printf("\nGraph create successfully \n");
	
	return g;
}

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
void main()
{
 struct graph *g;
 g=adjacencyMatrix();	
 viewGraph(g);
}
