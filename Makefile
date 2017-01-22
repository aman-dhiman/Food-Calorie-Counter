
# Flags that are sent to the compiler
# Do not change these
CFLAGS      =	-Wall  -pedantic -g -Iinclude -std=c99


diary:
	gcc $(CFLAGS)  src/main.c src/diary.c src/linkedList.c -o bin/diary

test: 
	gcc $(CFLAGS) src/maintest.c src/linkedList.c  -o bin/listTest

clean:
	@ rm *.o
