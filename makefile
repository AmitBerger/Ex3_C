FLAGS = -Wall -Werror -g
CC = gcc
.PHONY = all clean
all: stringProg
stringProg: FuncAndMain.c
	$(CC) $(FLAGS) FuncAndMain.c -o stringProg
clean:
	rm -f *.o *.a stringProg
