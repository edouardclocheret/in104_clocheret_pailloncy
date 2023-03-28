FILES=main.c

EXE=$(patsubst %.c, %.x, $(FILES))

INC=$(HOME)/Library/SDL2-2.26.4/include
LIB=$(HOME)/Library/SDL2-2.26.4


CC=gcc
CFLAGS=-Wall -Werror -I$(INC)
LDFLAGS=-L$(LIB) -lin104_clocheret_pailloncy/src

all: $(EXE)

%.x: %.c
	$(CC) $(CFLAGS) $< -o $@ $(LDFLAGS)

clean:
	@rm -f *~
	@rm -f *.o

realclean: clean
	@rm -f *.x