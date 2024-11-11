NAME = libftprintf.a
SRC = *.c
BONUS = *_bonus.c
OBJ = $(SRC:.c=.o)
OBJ_BONUS = $(SRC:.c=.o) $(BONUS:.c=.o)
FLAGS = -Wall -Wextra -Werror

.PHONY: all clean fclean re bonus

all : $(NAME)
	@true

$(NAME) :
	gcc $(FLAGS) -c $(SRC)
	ar rcs $(NAME) $(OBJ)

bonus : clean
	gcc $(FLAGS) -c $(SRC) $(BONUS)
	ar rcs $(NAME) $(OBJ_BONUS)

clean : fclean
	rm -f $(NAME)

fclean : clean
	rm -rf $(OBJ) $(OBJ_BONUS)

re : fclean all

dev :
	git add .; git commit -m 'auto update'; git push; /home/hallfana/francinette/tester.sh