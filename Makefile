.PHONY: all clean fclean re

NAME=push_swap

CC=cc
CFLAGS= -g -Wall -Wextra -Werror

SRCS:=format_input.c push_swap.c check_input.c sort_operations.c utils.c \
		find_median.c sort.c opps_wrappers.c final.c
# final.c

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