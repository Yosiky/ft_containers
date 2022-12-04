COMPILER	=	g++
CFLAGS		=	--std=c++98#-Wall -Wextra -Werror
DEBUG		=	-g3
OPT			=	-o3

LIBRARY		=	-lc

NAME		=	libcontainers.a

DIR_INC		=	inc
HEADERS		=	philo.h
CHEADER		=	$(addprefix -I,$(DIR_INC))
LIST_HEADER	=	$(addprefix $(DIR_INC)/,$(HEADERS))

DIR_SRC 	=	src
SRC			=		

DIR_OBJ		=	obj
OBJ			=	$(addprefix $(DIR_OBJ)/,$(SRC:.c=.o))

all: $(DIR_OBJ) $(NAME)

clean: 
	rm -rf $(DIR_OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

$(DIR_OBJ):
	mkdir -p $@

$(DIR_OBJ)/%.o: $(DIR_SRC)/%.c $(LIST_HEADER) Makefile
	$(COMPILER) $(CFLAGS) $(DEBUG) $(CHEADER) $< -c -o $@

$(NAME): $(OBJ) $(LIST_HEADER) Makefile
	ar -rc $@ $(OBJ)
	ranlib $@

test: $(NAME)
	$(COMPILER) -L. -lcontainers test/main.cpp -o test

.PHONY: all clean fclean re