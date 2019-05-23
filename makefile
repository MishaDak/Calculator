all: bin/calc

bin/calc: build/main.o build/func.o

bin/calc: build/main.o build/input.o build/func.o build/uifunc.o
	gcc -Wall -Werror build/main.o build/uifunc.o build/input.o build/func.o -o bin/calc `pkg-config --cflags --libs gtk+-2.0` -lm

build/main.o: src/main.c
	gcc -Wall -Werror -c src/main.c -o build/main.o `pkg-config --cflags --libs gtk+-2.0`

build/uifunc.o: src/uifunc.c
	gcc -Wall -Werror -c src/uifunc.c -o build/uifunc.o `pkg-config --cflags --libs gtk+-2.0`

build/input.o: src/input.c
	gcc -Wall -Werror -c src/input.c -o build/input.o `pkg-config --cflags --libs gtk+-2.0`

build/func.o: src/func.c
	gcc -Wall -Werror -c src/func.c -o build/func.o -lm

.PHONY: clean

clean:
	rm -rf build/*.o
