
// linear representation of graph 
// Adjacency  matrix of labelled/weighted directed list 
// find sortest path between nodes using floys warshall algorithm 
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
	int u,v,i,cost;
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
			g->adj[u][v]=999;
		
	viewGraph(g);
	printf("\nEnter u and v of edges ");
	for(i=0;i<g->e; i++)
	{
	printf("\ne%d : ",i);							// assigning edges connecting nodes
	scanf("%d%d",&u,&v);
	printf("\nenter cost of %d-%d : ",u,v);
	scanf("%d",&cost);
	g->adj[u][v]=cost;
									// by commenting this line we create adjacency matrix of directed list

	}
	printf("\nGraph create successfully \n");
	
	return g;
}

void floydWarshall(struct graph *g)
{
	int k,i,j;

	for(k=0;k<g->v;k++)
	{
		for(i=0;i<g->v;i++)
		{
			for(j=0;j<g->v;j++)
			 {
			 	if(g->adj[i][k]+g->adj[k][j] < g->adj[i][j])
			 	g->adj[i][j]=g->adj[i][k]+g->adj[k][j];
			 }
		}

	}
viewGraph(g);

}
void viewGraph(struct graph *g)
{
	int u,v;
	printf("\n\n\n\t\tView Graph\n\n");
	for(u=0;u<g->v;u++)
	{
		for(v=0;v<g->v;v++)
		{
			if(g->adj[u][v]==999)
			 printf("\t N");
			 else
			 printf("\t %d",g->adj[u][v]);
		}
		printf("\n");
	}
}
void main()
{
 struct graph *g;
 g=adjacencyMatrix();	
 viewGraph(g);
 floydWarshall(g);
}
