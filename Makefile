all: clean file.o luhn.o
	gcc file.o luhn.o ./src/main.c -o main

file.o: ./src/lib/file.h
	gcc -c ./src/file.c

luhn.o: ./src/lib/luhn.h
	gcc -c ./src/luhn.c

clean:
	rm -rf *.o main

run:
	./main
