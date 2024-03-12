CC=clang
CFLAGS=-c -Wall -Wextra -pedantic -O0 -g3 -fsanitize=address -fno-omit-frame-pointer -fno-optimize-sibling-calls
LDFLAGS=-Wall -Wextra -pedantic -O0 -g3 -fsanitize=address -fno-omit-frame-pointer -fno-optimize-sibling-calls

ALL_OBJECTS= src/main.o
ALL_EXECUTABLES=main
ALL_TEST_EXECUTABLES= tests/test

main: src/main.o
	mkdir build
	gcc src/main.o -o build/main_output
	rm src/*.o

src/main.o: src/main.c
	gcc -c -I include src/main.c -o src/main.o

clean: 
	rm -f *.o ./tests/*.o ./src/*.o ${ALL_OBJECTS} ${ALL_TEST_EXECUTABLES} ${ALL_EXECUTABLES}
