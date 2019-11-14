all: main.o
	gcc -o stattest.exe main.o

main.o: main.c
	gcc -c main.c

run:
	./stattest.exe

clean:
	rm *.o
	rm *~
