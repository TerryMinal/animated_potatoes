all: LL.h LL.c
	gcc -o LL LL.c

LL.o: LL.h
	gcc -c LL.h

tg: tg.c LL.c LL.h
	gcc -o tg tg.c

qx: qx.c LL.c LL.h
		gcc -o qx qx.c

runtg: tg
	./tg

runqx: qx
	./qx

run: all
	./LL

clean:
	rm *.gch
	rm *~
	rm *.o
