
CFLAGS = -g `sdl2-config --cflags`
LDFLAGS  = `sdl2-config --libs` -lSDL2_gfx -lSDL2_ttf -lm
PROG = game
CXX = gcc

#Il faudra ensuite lier tous les fichiers .c et .o


# top-level rule to create the program.
all: $(PROG)
# compiling other source files.

$(PROG): main.c
	$(CXX) main.c -o $(PROG) $(LDFLAGS)
# cleaning everything that can be automatically recreated with "make"
clean:
	rm $(PROG) *.o

