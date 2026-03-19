
passfile: ./test.c ./tinyfiledialogs/tinyfiledialogs.c ./tinyfiledialogs/tinyfiledialogs.h 
	gcc test.c tinyfiledialogs/tinyfiledialogs.c -Wall -Wextra -o passfile -lcrypto

