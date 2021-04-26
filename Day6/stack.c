#include <stdio.h>

#define SIZE 10

typedef struct satck
{

}Stack;

int push(int stack[], int val, int top);

int pull(int stack[],int top);

int main()
{
    int top = 0;
    int stack[SIZE]={0};
    for (int i = 1; i < 6; i++)
    {
        top = push(stack,i*19,top);
    }
    top = push(stack,10,top);
    top = push(stack, 100, top);
    for (int i = 0; i < SIZE; i++)
    {
        printf("%d\n", stack[i]);
    }
    printf("%d\n", top);
    
    top = pull(stack, top);
    top = pull(stack, top);
    top = pull(stack, top);
    
    printf("\n");
    for (int i = 0; i < SIZE; i++)
    {
        printf("%d\n", stack[i]);
    }
    printf("%d\n", top);
    
    
}

int push(int stack[], int val, int top)
{
    stack[top]=val;
    return top + 1 ;
}

int pull(int stack[],int top)
{
    stack[top-1]=0;
    return top - 1;
}