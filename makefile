 all: LL.h LL.c
	gcc -o LL LL.c

LL.o: LL.h
	gcc -c LL.h

run: all
	./LL

clean:
	rm *.o
	rm *~
	rm *.gch
