.PHONY: all clean fclean re

NAME=push_swap

CC=cc
CFLAGS= -g  -Wall -Wextra -Werror

# -fsanitize=address

SRCS:=format_input.c push_swap.c check_input.c sort_operations.c utils.c utils2.c \
		find_median.c final.c sa_partition.c sb_partition.c specific_node_counts.c \
		b_part.c simple_sort.c
		

OBJS:=$(SRCS:%.c= %.o)

LIBFT_DIR=Libft
LIBFT_MAKE=make -C $(LIBFT_DIR)
LIBFT_LIB=$(LIBFT_DIR)/libft.a

all:$(NAME)

$(NAME): $(LIBFT_LIB) $(OBJS) 
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT_LIB) -o $(NAME)

$(LIBFT_LIB):
	$(LIBFT_MAKE) all

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)
	$(LIBFT_MAKE) clean

fclean: clean
	rm -f $(NAME)
	$(LIBFT_MAKE) fclean

re: fclean all