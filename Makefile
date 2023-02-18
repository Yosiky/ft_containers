CC			=	g++
CFLAGS		=	-Wall -Wextra --std=c++98 -O0

SRC			=	main

OBJ			=	$(SRC:=.o)

HEADER_DIR	=	include
HEADER		=	$(shell find include -type f -name '*.hpp')

INCLUDE		=	-I $(HEADER_DIR)

NAME		=	test.out

.PHONY: all clean fclean re

all: $(NAME)

clean:
	rm -rf $(OBJ)
	rm -rf compile.log

fclean: clean
	rm -rf $(NAME)

re: fclean all

$(OBJ): %.o: %.cpp $(HEADER) Makefile
	@printf "Compile obj file: %s\n" $<
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@ -fdiagnostics-color=always 2>compile.log

$(NAME): $(OBJ) Makefile
	@printf "Link executeble file: %s\n" $@
	@$(CC) $< -o $@

