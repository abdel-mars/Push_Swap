CC		= gcc
CFLAGS	= -Wall -Werror -Wextra -I.
NAME	= push_swap
LIBFT = ./libft/libft.a
LIBFTDIR = ./libft
SRC_DIR	= src/
SRC		= $(SRC_DIR)push_swap.c \
		  $(SRC_DIR)check_input.c $(SRC_DIR)check_input_utils.c \
		  $(SRC_DIR)init.c \
		  $(SRC_DIR)stack.c \
		  $(SRC_DIR)swap.c $(SRC_DIR)push.c $(SRC_DIR)rotate.c $(SRC_DIR)reverse_rotate.c \
		  $(SRC_DIR)tiny_sort.c $(SRC_DIR)sort.c \
		  $(SRC_DIR)position.c $(SRC_DIR)cost.c $(SRC_DIR)do_moves.c \
		  $(SRC_DIR)utils.c
OBJS	= $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFTDIR)

$(SRC_DIR)%.o: $(SRC_DIR)%.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(MAKE) clean -C $(LIBFTDIR)
	rm -f $(OBJS)

fclean: clean
	$(MAKE) fclean -C $(LIBFTDIR)
	rm -f $(NAME)

re: fclean all

test2:				$(NAME)	
					$(eval ARG = $(shell shuf -i 0-100 -n 2))
					./push_swap $(ARG) | ./checker_linux $(ARG)
					@echo -n "Instructions: "
					@./push_swap $(ARG) | wc -l

test3:				$(NAME)	
					$(eval ARG = $(shell shuf -i 0-100 -n 3))
					./push_swap $(ARG) | ./checker_linux $(ARG)
					@echo -n "Instructions: "
					@./push_swap $(ARG) | wc -l

test5:				$(NAME)	
					$(eval ARG = $(shell shuf -i 0-5000 -n 5))
					./push_swap $(ARG) | ./checker_linux $(ARG)
					@echo -n "Instructions: "
					@./push_swap $(ARG) | wc -l

test100:			$(NAME)	
					$(eval ARG = $(shell shuf -i 0-5000 -n 100))
					./push_swap $(ARG) | ./checker_linux $(ARG)
					@echo -n "Instructions: "
					@./push_swap $(ARG) | wc -l

test500:			$(NAME)	
					$(eval ARG = $(shell shuf -i 0-5000 -n 500))
					./push_swap $(ARG) | ./checker_linux $(ARG)
					@echo -n "Instructions: "
					@./push_swap $(ARG) | wc -l

test1000:			$(NAME)	
					$(eval ARG = $(shell shuf -i 0-5000 -n 1000))
					./push_swap $(ARG) | ./checker_linux $(ARG)
					@echo -n "Instructions: "
					@./push_swap $(ARG) | wc -l


.PHONY: all clean fclean re test2 test3 test5 test100 test500 test1000