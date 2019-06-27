CC=clang++
CFLAGS=#-Wall -Werror -Wextra
BINS=ncurses.dylib
LIB= ncurses
LIBLINK= -l$(LIB)
HEADER		=	../includes/
INCLUDES	=	-I $(HEADER)

all: $(BINS)

%.dylib: %.cpp
	$(CC) $(CFLAGS) -fPIC -shared -o $@ $^ $(LIBLINK) $(INCLUDES)

clean:
	rm $(BINS)

re: clean all