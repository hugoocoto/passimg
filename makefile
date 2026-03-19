HEAD = ./tinyfiledialogs/tinyfiledialogs.h ./passimg.h 
SRC = ./tinyfiledialogs/tinyfiledialogs.c ./test.c ./passimg.c
FLAGS = -Wall -Wextra
INCL = -lcrypto -lm

passimg: $(HEAD) $(SRC)
	gcc $(SRC) $(FLAGS) -o $@ $(INCL) 

