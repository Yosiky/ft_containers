CC			=	g++
CFLAGS		=	-Wall -Wextra -Werror --std=c++98

SRC			=	test.cpp

OBJ			=	$(SRC:.cpp=.o)

INCLUDE		=	-I../inc -I../enable_if -I../integral_constant\
				-I. -I../iterator -I../is_type

HEADERS		=	../inc/defines.hpp								\
				../integral_constant/integral_constant.hpp		\
				../is_type/is_integral.hpp						\
				../iterator/random_iterator.hpp					\
				../enable_if/enable_if.hpp						\
				vector.hpp

DEPS		=	$(SRC:.cpp=.d)

NAME		=	test

-include $(DEPS)

.PHONY: all clean fclean re

all: $(NAME)

%.o: %.cpp Makefile
	@printf "Compile obj file: %s\n" $<
	@echo "$(CC) $(CFLAGS) $(INCLUDE) -MMD -MT $@ -c -o $@ -fdiagnostics-color=always @()" > compile.log
	$(CC) $(CFLAGS) $(INCLUDE) -MMD -MT $@ -c -o $@ -fdiagnostics-color=always $< 2>>compile.log

$(NAME): $(OBJ) $(SRC)
	@printf "Link executeble file: %s\n" $@
	@$(CC) $(OBJ) -o $@.out

clean:
	rm -rf $(OBJ)
	rm -rf compile.log
	rm -rf $(NAME).d

fclean: clean
	rm -rf $(NAME)

re: fclean all
