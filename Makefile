
#makefile

CFLAGS = -Wall -Werror -Wextra -std=c11 -g

prog: main.c de.o stats.o
	gcc $(CFLAGS) main.c de.o stats.o -o prog

de.o: de.c
	gcc $(CFLAGS) de.c -c

stats.o: stats.c
	gcc $(CFLAGS) stats.c -c

clean:
	rm -f prog