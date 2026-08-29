all: test/test

test/test: alphanumsort.c alphanumsort.h test/test.c
	cc -Wall -I. -o test/test alphanumsort.c test/test.c
	./test/test

clean:
	rm -f test/test
