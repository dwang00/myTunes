all: main.o functionsllist.o functionsarray.o
	gcc -o myTunes main.o functionsllist.o functionsarray.o

main.o: main.c headerllist.h headerarray.h
	gcc -c main.c headerllist.h headerarray.h

functionsllist.o: functionsllist.c
	gcc -c functionsllist.c

functionsarray.o: functionsarray.c
	gcc -c functionsarray.c

run:
	./myTunes

clean:
	del *.exe
	del *.o
	del *.gch
