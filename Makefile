
output.o: main.o parentheses_check.o my_stack.o
	gcc -o output.o main.o parentheses_check.o my_stack.o
main.o: main.c parentheses_check.h
	gcc -c main.c
parentheses_check.o: parentheses_check.c parentheses_check.h my_stack.h
	gcc -c parentheses_check.c
my_stack.o: my_stack.c my_stack.h
	gcc -c my_stack.c
clean:
	rm output.o main.o parentheses_check.o my_stack.o


