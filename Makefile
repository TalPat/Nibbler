NAME			=	nibbler
SRCDIR		=	./src/
SRC				=	main.cpp\
						Game.cpp\
						Entity.cpp\
						Food.cpp\
						Snake.cpp

SRCPATH		:=	$(addprefix $(SRCDIR), $(SRC))
OBJDIR		=	obj/
OBJ				=	$(SRC:%.cpp=%.o)
OBJPATH		:=	$(addprefix $(OBJDIR), $(OBJ))

HEADER		=	./includes/
CFLAGS		=	#-Wall -Werror -Wextra
CC				=	clang++
INCLUDES	=	-I $(HEADER)

LIB			= 
LIBLINK		= $(addprefix -l, $(LIB))

all: $(NAME)

$(NAME): $(OBJPATH)
	$(CC) -o $(NAME) $(SRCPATH) $(INCLUDES) $(CFLAGS) $(LIBLINK)

$(OBJDIR)%.o: $(SRCDIR)%.cpp
	mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) -c -o $@ $< $(INCLUDES)

clean:
	rm -rf $(OBJPATH)

fclean:	clean
	rm -rf $(NAME)

re: fclean all