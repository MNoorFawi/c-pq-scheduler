sc = ./source_code/

all: cprint proc_pq

cprint.o: cprint.c
	gcc -c $^

cprint: cprint.o
	gcc $^ -o $@

pq.o: $(sc)pq.c $(sc)pq.h
	gcc -c $<

proc_pq.o: proc_pq.c $(sc)pq.h
	gcc -c $<

libpq.a: pq.o
	$(shell mkdir -p ./lib)
	ar rcs ./lib/$@ $^

proc_pq: proc_pq.o libpq.a
	gcc $< -L./lib -lpq -o $@

clean:
	rm *.o *.a