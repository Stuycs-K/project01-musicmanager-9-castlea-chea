run: main
	@./main
main compile: main.o linkedList.o library.o
	@gcc -Wall -o main main.o linkedList.o library.o
main.o: main.c linkedList.h library.h
	@gcc -Wall -c main.c
linkedList.o: linkedList.c
	@gcc -Wall -c linkedList.c
library.o: library.c linkedList.h
	@gcc -Wall -c library.c
clean:
	@rm -f main *.o