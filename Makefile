# Windows users run: gcc -Wall seint.c crypto.c utilities.c sort.c -o seint

seint: seint.c crypto.o utilities.o sort.o reqs.h
	gcc -Wall seint.c crypto.o utilities.o sort.o -o seint

crypto.o: crypto.c
	gcc -Wall -c crypto.c

utilities.o: utilities.c
	gcc -Wall -c utilities.c

sort.o: sort.c
	gcc -Wall -c sort.c