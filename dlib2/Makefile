CC=clang++
CFLAGS=#-Wall -Werror -Wextra
BINS=sfml.dylib
LIBLINK= $(shell pkg-config --cflags --libs sfml-graphics sfml-window)
HEADER		=	../includes/
INCLUDES	=	-I $(HEADER)

all: $(BINS)

%.dylib: %.cpp
	$(CC) $(CFLAGS) -fPIC -shared -o $@ $^ $(LIBLINK) $(INCLUDES)

clean:
	rm $(BINS)

re: clean all