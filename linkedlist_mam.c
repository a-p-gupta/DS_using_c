// Recursive C program to search an element in linked list

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>


/* Link list node */
struct Node
{
    int key;
    struct Node* next;
};
 
void push(struct Node** head_ref, int new_key)
{
    struct Node* new_node =(struct Node*) malloc(sizeof(struct Node));
new_node->key  = new_key;
      new_node->next = (*head_ref);
    (*head_ref)    = new_node;
}
 
bool printnode(struct Node* head)
{
        if (head == NULL)
        return false;
     
    	printf("\t%d",head->key );
       
 
        return printnode(head->next);
}
 
 bool search(struct Node* head, int x)
{
        if (head == NULL)
        return false;
     
        if (head->key == x)
        return true;
 
        return search(head->next, x);
}
 

int main()
{
        struct Node* head = NULL;
    int x = 21;
 
    /* 14->21->11->30->10  */
    push(&head, 10);
    push(&head, 30);
    push(&head, 11);
    push(&head, 21);
    push(&head, 14);
 
    printnode(head);
        search(head, 21)? printf("Yes") : printf("No");
    return 0;
}

