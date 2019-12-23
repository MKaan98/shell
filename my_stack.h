#ifndef MY_STACK_H_
#define MY_STACK_H_

#define MAX_LENGHT 512

struct my_stack {
    int top;
    int lines[MAX_LENGHT];
    char array[MAX_LENGHT];
};

//creating a stack
struct my_stack* create_stack();

//return 1 if full
int is_full(struct my_stack* stack);

//return 1 if empty
int is_empty(struct my_stack* stack);

//pushes an item on top of stack returns 0, if stack is full return 1
int push(struct my_stack* stack, char item, int line);

//returns the top item of a stack and removes it
char pop(struct my_stack* stack);
////returns top line integer of a stack
int get_line(struct my_stack* stack);

//returns the top item of a stack without removing it
char peek(struct my_stack* stack);

//prints the stack
void print_stack(struct my_stack* stack);

//returns the size of a stack
int size_of_stack(struct my_stack* stack);

#endif
