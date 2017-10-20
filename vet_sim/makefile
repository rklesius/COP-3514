records: records.o readline.o dogs.o
	gcc -o records records.o readline.o dogs.o

records.o: records.c readline.h dogs.h
	gcc -c records.c

dogs.o: dogs.c dogs.h readline.h
	gcc -c dogs.c

readline.o: readline.c readline.h
	gcc -c readline.c
