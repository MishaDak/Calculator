calc: bin/calc

bin/calc: build/main.o build/input.o build/func.o
	gcc -Wall -Werror build/main.o build/input.o build/func.o -o bin/calc

build/main.o: src/main.c
	gcc -Wall -Werror -c src/main.c -o build/main.o

build/input.o: src/input.c
	gcc -Wall -Werror -c src/input.c -o build/input.o

build/func.o: src/func.c
	gcc -Wall -Werror -c src/func.c -o build/func.o

.PHONY: clean

clean:
	rm -rf build/*.o
