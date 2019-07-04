NAME			=	nibbler
SRCDIR		=	./src/
SRC				= 	main.cpp\
					Game.cpp\
					Entity.cpp\
					Food.cpp\
					Snake.cpp

SRCPATH		:=	$(addprefix $(SRCDIR), $(SRC))
OBJDIR		=	obj/
OBJ				=	$(SRC:%.cpp=%.o)
OBJPATH		:=	$(addprefix $(OBJDIR), $(OBJ))

HEADER		=	./includes/
CFLAGS		= #-Wall -Werror -Wextra
CC				=	clang++
INCLUDES	=	-I $(HEADER)

LIB			= 
LIBLINK		= $(addprefix -l, $(LIB))

all: $(NAME) libs

$(NAME): $(OBJPATH)
	$(CC) -o $(NAME) $(SRCPATH) $(INCLUDES) $(CFLAGS) $(LIBLINK) -ldl

$(OBJDIR)%.o: $(SRCDIR)%.cpp
	mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) -c -o $@ $< $(INCLUDES)

libs: dependancies
	make -C ./dlib1
	make -C ./dlib2
	make -C ./dlib3

dependancies:
	#sh -c "$(curl -fsSL https://raw.githubusercontent.com/Tolsadus/42homebrewfix/master/install.sh)" to install brew
	brew list sdl2 || brew install sdl2
	brew list pkg-config || brew install pkg-config
clean:
	rm -rf $(OBJPATH)

fclean:	clean
	rm -rf $(NAME)
	make clean -C ./dlib1
	make clean -C ./dlib2
	make clean -C ./dlib3

re: fclean all