all: cprint proc_pq

cprint.o: cprint.c
	gcc -c cprint.c

cprint: cprint.o
	gcc cprint.o -o cprint

pq.o: pq.c pq.h
	gcc -c $<

proc_pq.o: proc_pq.c pq.h
	gcc -c proc_pq.c

libpq.a: pq.o
	ar rcs $@ $^
    
proc_pq: proc_pq.o libpq.a
	gcc proc_pq.o -L./ -lpq -o proc_pq

clean:
	rm *.o *.a