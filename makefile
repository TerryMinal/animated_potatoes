all: LL.h LL.c
	gcc -o LL LL.c

LL.o: LL.h
	gcc -c LL.h

tg: tg.c LL.c LL.h
	gcc -g -o tg tg.c

qx: qx.c LL.c LL.h
		gcc -g -o qx qx.c

runtg: tg
	./tg

debugtg: tg
	valgrind --leak-check=yes ./tg

runqx: qx
	./qx

debugqx: qx
	valgrind --leak-check=yes ./qx

run: all
	./LL

clean:
	rm *\#; rm *.gch; rm *~; rm *.o; rm qx; rm tg; rm LL; rm vgcore*
