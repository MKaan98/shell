#include <stdlib.h>
#include "my_stack.h"

//creating a stack
struct my_stack* create_stack(){

    struct my_stack* stack = malloc(sizeof(struct my_stack));

    stack->top = -1;

    return stack;
}

//return 1 if full
int is_full(struct my_stack* stack) {
   return stack->top == MAX_LENGHT;
}

//return 1 if empty
int is_empty(struct my_stack* stack) {
    return stack->top == -1;
}

//pushes an item on top of stack returns 0, if stack is full return 1
int push(struct my_stack* stack, char item, int line){
    if (stack->top==MAX_LENGHT)
        return 1;

    stack->top++;
    stack->lines[stack->top] = line;
    stack->array[stack->top] = item;
    return 0;
}

//returns the top item of a stack and removes it
char pop(struct my_stack* stack){
    if (stack->top==-1)
        return ' ';
    char result = stack->array[stack->top];
    stack->top--;
    return result;
}

////returns top line integer of a stack
int get_line(struct my_stack* stack){
    return stack->lines[stack->top];
}

//returns the top item of a stack without removing it
char peek(struct my_stack* stack){
    return stack->array[stack->top];
}

//prints the stack
void print_stack(struct my_stack* stack){
    int temp=-1;
    //prints each unique line
    for (int i=0;i<=stack->top;i++){
        if (temp !=stack->lines[i]){
            temp = stack->lines[i];
            printf("%d ",temp);
        }
        else
            continue;
    }
    printf("\ncurrent stack has %d items;\n",(stack->top+1));
    for (int i=0;i<=stack->top;i++){
        printf("%c",stack->array[i]);
    }
}

//returns the size of a stack
int size_of_stack(struct my_stack* stack){
    return (stack->top+1);
}


