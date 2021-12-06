# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dzivanov <dzivanov@student.42wolfsburg.de> +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/03 04:54:13 by dzivanov          #+#    #+#              #
#    Updated: 2021/12/03 04:54:13 by dzivanov         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC			= gcc
#CFLAGS		= -g3
CFLAGS		= -Wall -Wextra -Werror
#CFLAGS		=
RM			= rm -f
SRCD		= ./srcs/
SRC			= pipex.c ft_file_checker.c ft_cmd_check.c ft_handlers.c ft_utilities_1.c ft_mem_handlers.c ft_utilities_2.c
# Command to add the source folder prefix (instead of having it added manually to SRC)
SRCF		= $(addprefix $(SRCD),$(SRC))
OBJD		= ./objs/
# for every SRCF file which is an .c file an o file will be created according to the implicit rule (see $(OBJD)%.o: $(SRCD)%.c)
OBJF		= $(SRCF:$(SRCD)%.c=$(OBJD)%.o)
BUILD		= $(OBJF:$(OBJD)%.o)

NAME		= pipex
HEADD		= ./incl/
HEADF		= pipex.h

LIBFTD		= ./libft/
LIBFT_OBJD	= objs
LIBFT_SRCD	= srcs/
LIBFTL		= libft.a

LIBFT_OBJF    = ${LIBFTD}${LIBFT_OBJD}/*.o
LIBFT_MAKE    = make -C ${LIBFTD}

#if to the respective c file in the source directory no matching o file in the object
#directory is available, then create it according to the following rules:
#Note: the object directory will only be created if not existing already. -p flag throws no errors when already there
$(OBJD)%.o: $(SRCD)%.c
	@mkdir -p $(OBJD)
	$(CC) $(CFLAGS) -I ${HEADD} -c -o $@ $<

# $(NAME):	${OBJF}
# 			make libftmake
# 			$(CC) $(CFLAGS) $(SRCF) -o $(NAME) $(HEADD)$(HEADF) $(LIBFTD)$(LIBFTL)
$(NAME):	${OBJF}
			make libftmake
			$(CC) $(CFLAGS) $(SRCF) -o $(NAME) -L $(HEADD) $(LIBFTD)$(LIBFTL)


all:		${NAME}

libftmake:
			${LIBFT_MAKE}

clean:
			${RM} ${OBJD}*.o
			make -C ${LIBFTD} clean

fclean:		clean
			${RM} ${NAME}
			${RM} ${LIBFTD}${LIBFTL}
			${RM} ${HEADD}pipex.h.gch

re:			fclean all

.PHONY:		all clean fclean re