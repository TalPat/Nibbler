CC=clang++
CFLAGS=#-Wall -Werror -Wextra
BINS=glfw.dylib
LIBLINK= $(shell --cflags --libs glfw)
HEADER		=	../includes/
INCLUDES	=	-I $(HEADER)

all: $(BINS)

%.dylib: %.cpp
	$(CC) $(CFLAGS) -fPIC -shared -o $@ $^ $(LIBLINK) $(INCLUDES)

clean:
	rm $(BINS)

re: clean all