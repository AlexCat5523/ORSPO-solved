.PHONY: clean run

main: clean
	gcc -c main.c
	gcc main.o -o $@
clean:
	rm -f main.o

run: main
	./main