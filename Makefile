NAME = push_swap

BNAME = checker

LIBFT = libft/libft.a

CC = cc

CFLAGS = -Wall -Werror -Wextra #-fsanitize=address -g

RM = rm -rf

SRC = push_swap.c check_args.c check_args2.c instruct.c small_sort.c big_sort.c

OBJ = $(SRC:.c=.o)

BOBJ = $(BSRC:.c=.o)

all : $(NAME)

$(NAME) : $(OBJ) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME) 

$(LIBFT) :
	make -C libft

clean :
	make clean -C libft
	$(RM) $(OBJ) $(BOBJ)

fclean : clean
	make fclean -C libft
	$(RM) $(NAME) $(BNAME)

re : fclean all

