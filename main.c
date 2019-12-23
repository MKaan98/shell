#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "parentheses_check.h"

#define MAXSTRLEN 512
#define MAXARGUMENT 64
//separetes each token from input and places them into argv
void separete_tokens(char input[],int *argc,char *argv[]){

    char *token;
    *argc=0;

    token = strtok(input," ");

    while(token!=NULL){
        argv[*argc]=token;
        token = strtok(NULL," ");
        *argc = *argc+1;
    }
}
//prints all tokens that are in argv
void print_tokens (int argc, char *argv[]){
    for(int i=0; i<argc; i++)
        printf("%s\n", argv[i]);
}
//clears input and argv arrays
void clear_input(char *input[],char *argv[]){
    int i = 0;
    //clears input array
    while(input[i]!=NULL)
        input[i++]=NULL;
    i=0;
    //clears argv array
    while(argv[i]!=NULL)
        argv[i++]=NULL;
}
//runs system commands
void run_commands (int argc, char *argv[]){
    //putting all tokens into a string
    char commands[MAXSTRLEN]="";
    for(int i=1;i<argc;i++){
        strcat(commands,argv[i]);
        strcat(commands," ");
    }
    //commands execution
    system(commands);
}
//calls calculator.sh
void calculate (int argc, char *argv[]){
    //preparing system input
    char commands[MAXSTRLEN]="";
    strcat(commands,"./calculator.sh ");
    for(int i=1;i<argc;i++){
        strcat(commands,argv[i]);
        strcat(commands," ");
    }
    //giving the script all the permisions and then execute it
    system("chmod 777 calculator.sh");
    system(commands);
}
//find the word count in given file
void word_count (int argc, char *argv[]){
    //preparing system input
    char commands[MAXSTRLEN]="";
    strcat(commands,"./word_count.sh ");
    for(int i=1;i<argc;i++){
        strcat(commands,argv[i]);
        strcat(commands," ");
    }
    //giving the script all the permisions and then execute it
    system("chmod 777 word_count.sh");
    system(commands);
}
//add more details
void print_info(){
printf("\navailable commands are;\n");
printf("1. parentheses_check file_path\n");
printf("2. run_commands any_commands\n");
printf("3. calculate number arithmetic_operator number\n");
printf("4. word_count word file_path\n");
printf("5. help\n\n");
}

int main()
{
    char input[MAXSTRLEN];
    char *argv[MAXARGUMENT];
    int argc;

    printf("Welcome\n\n");
    print_info();

    //main loop
    while (1){

    printf("shell>>>");
    //getting input
    fgets(input, MAXSTRLEN, stdin);
    if(strlen(input)!=1)
        input[strcspn(input, "\n")] = '\0';

    separete_tokens(input,&argc,argv);

    if(strcmp(argv[0],"exit")==0){
        puts("Good by");
        return 0;
    }
    else if(strcmp(argv[0],"parentheses_check")==0)
        parentheses_check(argv[1]);

    else if(strcmp(argv[0],"run_commands")==0)
        run_commands(argc,argv);

    else if(strcmp(argv[0],"calculate")==0)
        calculate(argc,argv);

    else if(strcmp(argv[0],"word_count")==0)
        word_count(argc,argv);

    else if(strcmp(argv[0],"help")==0)
        print_info();

    clear_input(&input,argv);
    }
}
