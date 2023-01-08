CC			=	clang++
CFLAGS		=	--std=c++98 # -Wall -Wextra -Werror	
# CFLAGS		+=	-g3
# CFLAGS		+=	-O3

DIR			=	$$(TEST_DIR)
DIR_INC		=	inc

SRC_INC		=	defines.hpp
PATH_INC	=	$(addprefix $(DIR_INC)/$(SRC_INC))

SRC			=	test.cpp
HEADER		=	$(DIR).hpp
PATH_HEADER	=	$(addprefix $(DIR)/$(HEADER))

OBJ			=	$(addprefix $(DIR)/$(SRC:.cpp=.o))

NAME		=	$(addprefix test_$(DIR))

$(NAME): 

all: $(NAME)

clean:
	@printf "rm %s" $(DIR)/$(NAME).o
	@rm $(DIR)/$(NAME).o

fclean:	clean
	@printf "rm %s" $(DIR)/$(NAME)
	@rm $(DIR)/$(NAME)

re: fclean all

.PHONY: all clean fclean re