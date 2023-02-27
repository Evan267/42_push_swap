SRCS	= main.c error.c utils.c free.c list.c swap.c push.c rotate.c reverse_rotate.c algo_tri.c insert_sort.c sort_3.c sort_2.c quick_sort.c merge_sort.c ft_lstadd_back.c ft_lstadd_front.c ft_lstclear.c ft_lstdelone.c ft_lstiter.c ft_lstlast.c ft_lstmap.c ft_lstnew.c ft_lstsize.c ft_putendl_fd.c ft_split.c ft_atoi.c ft_itoa.c ft_strchr.c ft_strlen.c ft_strlcpy.c ft_isdigit.c

OBJS	= ${SRCS:.c=.o}

HEAD	= push_swap.h

NAME	= push_swap

CC		= gcc

CFLAGS	= -Wall -Wextra -Werror

.c.o:		${CC} ${CFLAGS} -I-${HEAD} -c $< -o ${<:.c=.o}

${NAME} :	${OBJS}
			${CC} -o ${NAME} ${OBJS}

all :		${NAME}

clean :		
			${RM} ${OBJS}

fclean :	clean
			${RM} ${NAME}

re :		fclean all

.PHONY : all clean fclean re
