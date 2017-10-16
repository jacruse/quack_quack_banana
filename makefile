all: list.c headers.h
	gcc -o list_test list.c

run: all
	./list_test
