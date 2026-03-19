HEAD = ./tinyfiledialogs/tinyfiledialogs.h ./passfile.h 
SRC = ./tinyfiledialogs/tinyfiledialogs.c ./test.c ./passfile.c
FLAGS = -Wall -Wextra
INCL = -lcrypto -lm

passfile: $(HEAD) $(SRC)
	gcc $(SRC) $(FLAGS) -o $@ $(INCL) 

