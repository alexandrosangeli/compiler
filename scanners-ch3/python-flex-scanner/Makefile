CC=clang

scanner : main.o scanner.o
	$(CC) -o $@ $^

scanner.c : scanner.flex
	flex -o scanner.c $<

main.o : main.c
	$(CC) -c $<

scanner.o : scanner.c
	$(CC) -c $<

.PHONY: clean
clean:
	rm -rf *.o scanner scanner.c