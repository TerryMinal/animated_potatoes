all: music_library.c music_library.o LL.h LL.c
	gcc -o music_library music_library.c

LL.o: LL.h
	gcc -c LL.h

tg: tg.c LL.c LL.h
	gcc -g -o tg tg.c

qx: qx.c LL.c LL.h
		gcc -g -o qx qx.c

music_library.o: music_library.h
	gcc -c music_library.h

runtg: tg
	./tg

debugtg: tg
	valgrind --leak-check=yes ./tg

runqx: qx
	./qx

debugqx: qx
	valgrind --leak-check=yes ./qx

run: all
	./music_library

clean:
	rm *\#; rm *.gch; rm *~; rm *.o; rm qx; rm tg; rm LL; rm vgcore*
