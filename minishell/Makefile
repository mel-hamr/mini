NAME = minishell

NAMA = minishell.a

SRC = main.c utils.c get_next_line.c get_next_line_utils.c ft_split.c ft_split_1.c env.c

OBJ = $(SRC:.c=.o)

CFLAGS = -Wall -Wextra -Werror 

all : $(NAME)

$(NAME) : $(OBJ)
	@ar rcs $(NAMA) $(OBJ)
	gcc $(CFLAGS) $(NAMA) -o $(NAME)
	@echo 'SUCCESS!' 
clean :
	rm -rf $(OBJ)
fclean : clean
	@rm -rf $(NAME)
	@rm -rf $(NAMA)
re : fclean all