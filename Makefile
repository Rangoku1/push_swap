NAME = push_swap
BONUS = checker

LIBFT = libft/libft.a

CC = cc

CFLAGS = -Wall -Werror -Wextra 

RM = rm -rf

SRC = mandatory/push_swap.c mandatory/check_args.c mandatory/check_args2.c mandatory/instruct.c mandatory/small_sort.c mandatory/big_sort.c mandatory/big_sort2.c

BSRC = bonus/check_args.c bonus/check_args2.c bonus/instruct.c bonus/instruct2.c bonus/gnl.c bonus/gnl_utils.c bonus/checker.c 

OBJ = $(SRC:.c=.o)

BOBJ = $(BSRC:.c=.o)

all : $(NAME)

bonus : $(BONUS)
	$(CC) $(CFLAGS) $(BOBJ) $(LIBFT) -o $(BONUS)

$(BONUS) : $(BOBJ) $(LIBFT)
	$(CC) $(CFLAGS) $(BOBJ) $(LIBFT) -o $(BONUS)

$(NAME) : $(OBJ) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME) 

$(LIBFT) :
	make -C libft

clean :
	make clean -C libft
	$(RM) $(OBJ) $(BOBJ)

fclean : clean
	make fclean -C libft
	$(RM) $(NAME) $(BONUS)

re : fclean all

