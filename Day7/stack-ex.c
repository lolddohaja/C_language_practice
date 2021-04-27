#include <stdio.h>
#include <stdbool.h>

typedef int data_t;

typedef struct stack
{
    int size;
    int top;
    data_t *arr;
} Stack;

void init_stack(Stack *stack, unsigned int size);
void push_stack(Stack *stack, data_t value);
void pop_stack(Stack *stack, data_t value);
bool is_full_stack(Stack *stack);
bool is_empty_stack(Stack *stack);
void destroy_stack(Stack *stack);

int main(){
    Stack stack;

    init_stack(&stack, 20);
    push_stack(&stack,1);

    stack.size = 100;
    stack.top = -1;
    bool empty = is_empty_stack(&stack);

}