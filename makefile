all: main.o
	gcc -o execvptest main.o

main.o: main.c
	gcc -c main.c

run:
	./execvptest

clean:
	rm *.o
	rm *~
