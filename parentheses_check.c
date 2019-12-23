#include "my_stack.h"
#include "parentheses_check.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void parentheses_check(char* path){
    //if path is empty exit
    if (path == NULL){
        printf("please enter a file path after your command\n") ;
        return;
    }

    int maxstrlen = 128;

    //opening a file
    FILE *fp ;
    fp = fopen( path, "r" ) ;
    //if it doesn't exist
    if ( fp == NULL ){
            printf("file does not exist\n") ;
            return;
    }

    /*parentheses checking*/

    struct my_stack *stack = create_stack();
    char temp, character, data[maxstrlen];
    int i, line=1, stack_over_flow=0;

    while(fgets ( data, maxstrlen, fp ) != NULL){
    i = 0;
        while (data[i]!= '\0'){

            character = data[i];
            /*exceptional conditions*/

            //checks if there is any double slash (//) used for comments
            if(data[i]=='/' && data[i+1]=='/' )
                break;
            // checks if "/*" is used for comments
            if(data[i]=='/' && data[i+1]=='*') {
                //find "*/"
                int temp = line;
                while (!(data[i]=='*' && data[i+1]=='/')) {
                    if (data[i]==NULL) {
                        if(fgets ( data, maxstrlen, fp ) == NULL){
                            printf("multi line comment at line %d does not have an ending\n",temp);
                            break;
                        }
                        line++;
                        i=0;
                        continue;
                    }
                    i++;
                }
            }
            //checks the double quotes
            if(data[i]=='\"') {
                if(data[i-1]=='\\' && data[i-2]== '\'' && data[i+1]== '\'' || data[i-1]=='\'' && data[i+1]== '\'' )
                    continue;
                int j = i;
                i++;
                //searches for end double quotes
                while (!(data[i]=='\"')) {
                    //if there isn't any
                    if (data[i]== NULL) {
                        printf("double quotes are missing misused at line %d\n",line);
                        i=j;
                        break;
                    }
                    //ignores if any \" is used in the text
                    if(data[i]=='\\')
                        i++;
                    i++;
                }
            }
            //checks the quotes
            if(data[i]=='\'') {
                if(data[i-1]=='\\' && data[i-2]== '\'' && data[i+1]== '\'' || data[i-1]=='\'' && data[i+1]== '\'' )
                    continue;
                //if there isn't any end quotes
                if (data[i+3] == '\'')
                    i=i+3;
                else if (data[i+2] == '\'')
                    i=i+2;
                else
                    printf("quotes are missing or misused at line %d\n",line);
	    		}
            /*parentheses checking*/
            //if there is any ( or { ,then push it in the stack
            if (character == '(' || character == '{' || character == '[')
                stack_over_flow=push(stack,character,line);
            //if there is any )
            else if (character==')'){
                temp = peek(stack);
                if(temp =='(')
                pop(stack);
                //if not add it to the stack
                else
                    stack_over_flow=push(stack,character,line);
            }
            //if there is any }
            else if (character=='}') {
                temp = peek(stack);
                if(temp =='{')
                    pop(stack);
                //if not add it to the stack
                else
                    stack_over_flow=push(stack,character,line);
            }
            else if (character==']'){
                temp = peek(stack);
                if(temp =='[')
                pop(stack);
                //if not add it to the stack
                else
                    stack_over_flow=push(stack,character,line);
            }
            if(stack_over_flow==1){
                printf("file size is bigger than expected, please try smaller files");
                return;
            }
            i++;
        }
        line++;
    }
    //results
    if (size_of_stack(stack)==0)
        printf("parenthesis and curly brackets in your code is correct\n\n");
    else{
        printf("parenthesis and curly brackets in your code is incorrect at given lines;\n");
        print_stack(stack);
        printf("\n");
    }
    fclose(fp);
    free(stack);
}
