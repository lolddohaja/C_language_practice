#include <cstdio>
#include <cstdbool>
#include <cstdlib>

typedef int data_t;

class Stack
{
private:
    int size;
    int top;
    data_t *arr;

public:

    void init(unsigned int size){
        this->top = 0;
        this->size = 0;
        this -> arr = (data_t*)malloc(size * sizeof(data_t));
    }

    void push(data_t value){
        if(this -> is_full() == false)
        {
            this->arr[this->top] = value;
            this->top++;
        }
    }

    bool is_full(){

    }

};

// void init_stack(Stack *stack, unsigned int size);
// void push_stack(Stack *stack, data_t value);
// void pop_stack(Stack *stack, data_t value);
// bool is_full_stack(Stack *stack);
// bool is_empty_stack(Stack *stack);
// void destroy_stack(Stack *stack);

int main(){
    Stack stack = Stack();

    stack.init(10);
    stack.push(1);

    return 0;

}