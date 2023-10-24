run: main
	@./main
main compile: main.o linkedList.o
	@gcc -Wall -o main main.o linkedList.o
main.o: main.c linkedList.h
	@gcc -Wall -c main.c
linkedList.o: linkedList.c
	@gcc -Wall -c linkedList.c
clean:
	@rm -f main *.o