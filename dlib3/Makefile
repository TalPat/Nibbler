CC=clang++
CFLAGS= -Wall -Werror -Wextra
BINS=sdl2.dylib
LIB= SDL2
LIBLINK=  $(shell pkg-config --cflags --libs sdl2)
HEADER		=	../includes/
INCLUDES	=	-I $(HEADER)

all: $(BINS)

%.dylib: %.cpp
	$(CC) $(CFLAGS) -fPIC -shared -o $@ $^ $(LIBLINK) $(INCLUDES)

clean:
	rm $(BINS)

re: clean all