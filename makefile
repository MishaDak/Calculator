calc: main.o func.o
	gcc -Wall -Werror main.o func.o -o calc

main.o: main.c
	gcc -Wall -Werror -c main.c -o main.o

func.o: func.c
	gcc -Wall -Werror -c func.c -o func.o

clean:
	rm -rf *.o