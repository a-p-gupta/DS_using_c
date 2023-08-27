
// linear representation of graph 
// Adjacency  matrix of undirected list & directed list
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
struct graph
{
	int v;
	int e;
	int **adj;
	int *visit;
};

struct stack 
{
	int top ;
	int size;
	int *a;
};
//----------------------------------create graph-------------------------------------
struct graph* adjacencyMatrix()
{
	int u,v,i;
	struct graph *g;
	g=(struct graph*)malloc(sizeof(struct graph));	// creating dynamically graph variable
	printf("\nEnter number of vertex : ");
	scanf("%d",&g->v);
	printf("\nEnter number of edge : ");
	scanf("%d",&g->e);
	
	g->adj=malloc((g->v)*sizeof(int));		// creating 1d array
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
//	g->adj[v][u]=1;									// by commenting this line we create adjacency matrix of directed list
	}
	printf("\nGraph create successfully \n");
	
	return g;
}
//---------------------------------------Stack Functions ------------------------------------------------
struct stack* createStack()		// create a stack 
{
	struct stack *s;
	s=(struct stack*)malloc(sizeof(struct stack));
	s->size=25;
	s->top=-1;
	s->a=(int*)malloc(sizeof(int)*s->size);
	return s;
}

void addStackElement(struct stack *stack, int data)		// add data in stack
{
	if(stack->top == stack->size-1)
	{
		printf("\nStack is overflow");
	 	return;
	}
	else
	{
		stack->a[++stack->top]=data;
		printf("\n %d add ",stack->a[stack->top]);
	}
}

int removeStackElement(struct stack *stack)			// remove daya from stack
{
	int r;
	if(stack->top == -1)
	{
		printf("\nstack is underflow");
		return;
	}
	else
	{
		r=stack->a[stack->top--];
		printf("\n%d remove ",r);
		return r;
	}
}

int isEmpty(struct stack *stack)
{
	if(stack->top == -1)
		return 1;
	else 
		return 0;
}
//---------------------------------------DFS traverse ------------------------------------------------

void dfs(struct graph *g)
{
	int i,node; 
	struct stack *stack;
	stack=createStack();
	for(i=0;i<g->v;i++)		
		g->visit[i]=1;			// step 1 => all nodes in a ready state [status 1]
	
	addStackElement(stack,0);	// step 2 => add first node in a stack and change it state to waiting state [status 2]
	g->visit[0]=2;

	while(!isEmpty(stack))
	{
		printf("\nwhile");
		node=removeStackElement(stack); 	// step 3 => remove element from stack and change it state to processed state [status 3]
		g->visit[node]=3;
		
		for(i=0;i<g->v;i++)
		{
			printf("\nfor");
			if(g->adj[node][i] == 1 && g->visit[i] == 1)
			{
				addStackElement(stack , i);		// step 4 => adding connected / neighbors nodes in a stack 
				g->visit[i]=2;
			}
		}
		
	}
	viewVisit(g);
}

void viewVisit(struct graph *g)
{
	int i;
	printf("\n\n\t\tView Visit\n\n");
	for(i=0;i<g->v;i++)
	printf("\t %d",g->visit[i]);
}

void viewGraph(struct graph *g)
{
	int u,v;
		printf("\n\n\t\tView Graph\n\n");
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
 dfs(g);
}
