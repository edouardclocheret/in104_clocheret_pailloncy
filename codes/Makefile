CFLAGS = -g `sdl2-config --cflags`
LDFLAGS = `sdl2-config --libs` -lSDL2_gfx -lSDL2_ttf -lm
PROG = game
CXX = gcc
OBJS = initialisation.o entree_clavier.o down.o rotation.o pre_render.o main.o collision.o
# top-level rule to create the program.
all: $(PROG)
# compiling other source files.
%.o: %.c %.h
	$(CXX) $(CFLAGS) -c $<
# linking the program
$(PROG): $(OBJS)
	$(CXX) $(OBJS) -o $(PROG) $(LDFLAGS)
# cleaning everything that can be automatically recreated with "make"
clean:
	rm $(PROG) *.o