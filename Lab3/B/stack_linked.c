#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};


struct Node *push(struct Node *top, int value)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = top;
    top = newNode;
    return top;
}

struct Node * pop(struct Node * top) 
{
    if (top==NULL) 
  {
        printf("Stack Underflow! Cannot pop\n");
        return NULL; 
    }
   else 
  {
   struct Node *newNode;
   newNode=top;
   top=top->next;
   free(newNode);
    return top;
   }
}


void display(struct Node *top)
{
    struct Node *temp = top;
    while (temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main()
{
    struct Node *stack = NULL; 

    
    stack = push(stack, 10);
    stack = push(stack, 20);
    stack = push(stack, 30);

    
    printf("Stack: ");
    display(stack);
   
    stack=pop(stack);
    display(stack);

    return 0;
}
