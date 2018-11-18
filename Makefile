CFLAGS = -std=c99 -Wall -Wextra -pedantic -g

TARGETS =

all: $(TARGETS)

tests: p_constants.h cli/readMap.c cli/readMap.h
	gcc $(CFLAGS) -o tests/readMap.test cli/readMap.c

clean:
	rm -rf $(TARGETS) *.o *.test core
