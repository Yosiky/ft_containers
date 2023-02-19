CC			=	g++
CFLAGS		=	-Wall -Wextra --std=c++98 -g3 $(DEFINES)

SRC			=	main
SRC_MY_TEST	=	my_test

OBJ			=	$(SRC:=.o)
OBJ_MY_TEST	=	$(SRC_MY_TEST:=.o)

HEADER_DIR	=	include
HEADER		=	$(shell find include -type f -name '*.hpp' -d 1)

INCLUDE		=	-I $(HEADER_DIR)

NAME		=	test.out
MY_TEST		=	my_test.out

.PHONY: all clean fclean re

all: $(NAME) my_test

clean:
	rm -rf $(OBJ)
	rm -rf $(OBJ_MY_TEST)
	rm -rf compile2.log
	rm -rf compile1.log

fclean: clean
	rm -rf $(NAME)
	rm -rf $(MY_TEST)

re: fclean all

$(OBJ): %.o: %.cpp $(HEADER) Makefile
	@printf "Compile obj file: %s\n" $<
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@ -fdiagnostics-color=always 2>compile1.log

$(NAME): $(OBJ) Makefile
	@printf "Link executeble file: %s\n" $@
	@$(CC) $< -o $@

.PHONY: my_test
my_test: $(MY_TEST) 

$(OBJ_MY_TEST): %.o: %.cpp $(HEADER) Makefile
	@printf "Compile obj file: %s\n" $<
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@ -fdiagnostics-color=always 2>compile2.log

$(MY_TEST): $(OBJ_MY_TEST) Makefile
	@printf "Link executeble file: %s\n" $@
	@$(CC) $< -o $@
