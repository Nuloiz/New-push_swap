NAME	=	push_swap

SRC		=	push_swap.c linked_list.c op_switch_elements_in_stack.c op_rotate_stack.c op_swap_stacks.c radix_sort.c edge_and_sorted.c new_numbers.c free.c input_checker.c lst_functions.c turk_sort.c find_op.c calculation.c target_node.c

OBJS	=	${SRC:.c=.o}

CC		=	gcc

RM		=	rm -f

CFLAGS	=	-Wall -Werror -Wextra -g

INPUT1:=$(shell seq 0 2 | sort -R)
INPUT2:=$(shell seq -4 0 | sort -R)
INPUT3:=$(shell seq -5 4 | sort -R)
INPUT4:=$(shell seq -50 49 | sort -R)
INPUT5:=$(shell seq -250 249 | sort -R)
INPUT6:=$(shell seq -500 499 | sort -R)
INPUT7:=$(shell seq -3 2 | sort -R)

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
	#@valgrind --leak-check=full --show-leak-kinds=all ./$(NAME) $(INPUT1) | ./checker_linux $(INPUT1)
	@printf " number of instructions... \t"
	@./$(NAME) $(INPUT1) | wc -l | tr -d "[:blank:]"
	@printf "\n running with 5 numbers... \t"
	#@valgrind --leak-check=full --show-leak-kinds=all ./$(NAME) $(INPUT2) | ./checker_linux $(INPUT2)
	@printf " number of instructions... \t"
	@./$(NAME) $(INPUT2) | wc -l | tr -d "[:blank:]"
	@printf "\n running with 10 numbers... \t"
	#@valgrind --leak-check=full --show-leak-kinds=all ./$(NAME) $(INPUT3) | ./checker_linux $(INPUT3)
	@printf " number of instructions... \t"
	@./$(NAME) $(INPUT3) | wc -l | tr -d "[:blank:]"
	@printf "\n running with 100 numbers... \t"
	#@valgrind --leak-check=full --show-leak-kinds=all ./$(NAME) $(INPUT4) | ./checker_linux $(INPUT4)
	@printf " number of instructions... \t"
	@./$(NAME) $(INPUT4) | wc -l | tr -d "[:blank:]"
	@printf "\n running with 500 numbers... \t"
	#@valgrind --leak-check=full --show-leak-kinds=all ./$(NAME) $(INPUT5) | ./checker_linux $(INPUT5)
	@printf " number of instructions... \t"
	@./$(NAME) $(INPUT5) | wc -l | tr -d "[:blank:]"
	@printf "\n check correctness... \t"
	@./$(NAME) $(INPUT1) | ./checker_linux $(INPUT1)
	@./$(NAME) $(INPUT2) | ./checker_linux $(INPUT2)
	@./$(NAME) $(INPUT3) | ./checker_linux $(INPUT3)
	@./$(NAME) $(INPUT4) | ./checker_linux $(INPUT4)
	@./$(NAME) $(INPUT5) | ./checker_linux $(INPUT5)

small_check: $(NAME)
	@printf " running with 3 numbers... \t"
	#@valgrind --leak-check=full --show-leak-kinds=all ./$(NAME) $(INPUT1) | ./checker_linux $(INPUT1)
	@printf " number of instructions... \t"
	@./$(NAME) $(INPUT1) | wc -l | tr -d "[:blank:]"
	@printf "\n running with 5 numbers... \t"
	#@valgrind --leak-check=full --show-leak-kinds=all ./$(NAME) $(INPUT2) | ./checker_linux $(INPUT2)
	@printf " number of instructions... \t"
	@./$(NAME) $(INPUT2) | wc -l | tr -d "[:blank:]"
	@printf "\n running with 6 numbers... \t"
	#@valgrind --leak-check=full --show-leak-kinds=all ./$(NAME) $(INPUT7) | ./checker_linux $(INPUT7)
	@printf " number of instructions... \t"
	@./$(NAME) $(INPUT7) | wc -l | tr -d "[:blank:]"
	@printf "\n running with 10 numbers... \t"
	#@valgrind --leak-check=full --show-leak-kinds=all ./$(NAME) $(INPUT3) | ./checker_linux $(INPUT3)
	@printf " number of instructions... \t"
	@./$(NAME) $(INPUT3) | wc -l | tr -d "[:blank:]"
	@printf "\n check correctness... \t"
	@./$(NAME) $(INPUT1) | ./checker_linux $(INPUT1)
	@./$(NAME) $(INPUT2) | ./checker_linux $(INPUT2)
	@./$(NAME) $(INPUT7) | ./checker_linux $(INPUT7)
	@./$(NAME) $(INPUT3) | ./checker_linux $(INPUT3)

re: fclean all