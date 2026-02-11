NAME	=	push_swap

SRC		=	push_swap.c linked_list.c op_switch_elements_in_stack.c op_rotate_stack.c op_swap_stacks.c radix_sort.c edge_and_sorted.c new_numbers.c free.c input_checker.c lst_functions.c

OBJS	=	${SRC:.c=.o}

CC		=	gcc

RM		=	rm -f

CFLAGS	=	-Wall -Werror -Wextra -g

INPUT:=$(shell seq -5 4 | sort -R)
INPUT1:=$(shell seq 0 2 | sort -R)
INPUT2:=$(shell seq -4 0 | sort -R)
INPUT3:=$(shell seq -50 49 | sort -R)
INPUT4:=$(shell seq -250 249 | sort -R)

all: ${NAME}

${NAME}: ${OBJS}
	make all -C tools/libft
	cp tools/libft/libft.a .
	${CC} ${CFLAGS} ${OBJS} -o ${NAME} libft.a

clean:
	${RM}	${OBJS}
	make clean -C tools/libft

fclean: clean
	${RM}	${NAME} libft.a
	make fclean -C tools/libft

check: $(NAME)
	@printf " running with 3 numbers... \t"
	#@valgrind --leak-check=full --show-leak-kinds=all ./$(NAME) $(INPUT1) | ./checker_Mac $(INPUT1)
	@printf " number of instructions... \t"
	@./$(NAME) $(INPUT1) | wc -l | tr -d "[:blank:]"
	@printf "\n running with 5 numbers... \t"
	#@valgrind --leak-check=full --show-leak-kinds=all ./$(NAME) $(INPUT2) | ./checker_Mac $(INPUT2)
	@printf " number of instructions... \t"
	@./$(NAME) $(INPUT2) | wc -l | tr -d "[:blank:]"
	@printf "\n running with 100 numbers... \t"
	#@valgrind --leak-check=full --show-leak-kinds=all ./$(NAME) $(INPUT3) | ./checker_Mac $(INPUT3)
	@printf " number of instructions... \t"
	@./$(NAME) $(INPUT3) | wc -l | tr -d "[:blank:]"
	@printf "\n running with 500 numbers... \t"
	#@valgrind --leak-check=full --show-leak-kinds=all ./$(NAME) $(INPUT4) | ./checker_Mac $(INPUT4)
	@printf " number of instructions... \t"
	@./$(NAME) $(INPUT4) | wc -l | tr -d "[:blank:]"

re: fclean all