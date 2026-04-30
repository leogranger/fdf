GREEN		= \033[0;32m

NAME = libft.a

PART1 = ft_tolower.c \
		ft_toupper.c \
		ft_isprint.c \
		ft_isascii.c \
		ft_isalnum.c \
		ft_isdigit.c \
		ft_isalpha.c \
		ft_atoi.c \
		ft_strlen.c \
		ft_strlcat.c \
		ft_strncmp.c \
		ft_strdup.c \
		ft_calloc.c \
		ft_memcpy.c \
		ft_strchr.c \
		ft_strrchr.c \
		ft_strnstr.c \
		ft_bzero.c \
		ft_memchr.c \
		ft_memcmp.c \
		ft_memset.c \
		ft_memmove.c \
		ft_strlcpy.c \

PART2 = ft_itoa.c \
		ft_atoi_base.c \
		ft_strjoin.c \
		ft_split.c \
		ft_striteri.c \
		ft_strmapi.c \
		ft_substr.c \
		ft_strtrim.c \
		ft_putchar_fd.c \
		ft_putstr_fd.c \
		ft_putendl_fd.c \
		ft_putnbr_fd.c \

PRINTF = ft_checkchar.c \
		ft_printchar.c \
		ft_printf.c \
		ft_printint.c \
		ft_printvd.c \

GNL =	get_next_line.c \

BONUS = ft_lstnew.c \
		ft_lstadd_front.c \
		ft_lstsize.c \
		ft_lstlast.c \
		ft_lstadd_back.c \
		ft_lstdelone.c \
		ft_lstclear.c \
		ft_lstiter.c \
		ft_lstmap.c \

DIR_BIN = ./bin

SRC = ${PART1} ${PART2} ${PRINTF} ${GNL} ${BONUS}

OBJS = ${addprefix $(DIR_BIN)/, $(SRC:.c=.o)}
BONUS_OBJS = ${addprefix $(DIR_BIN)/, $(BONUS:.c=.o)}

CC = cc
RM = rm -rf
CFLAGS = -Wall -Wextra -Werror -g
INCLUDE = -I .

all: ${NAME} 

$(NAME): ${OBJS} | $(DIR_BIN)
	@ar rcs -s ${NAME} ${OBJS}
	@ar rcs -s ${NAME} ${OBJS} ${BONUS_OBJS}
	@echo "$(GREEN)Libft compiled successfully!"

$(DIR_BIN)/%.o: %.c | $(DIR_BIN)
	@${CC} ${CFLAGS} ${INCLUDE} -c $^ -o $@
	

bonus:	${OBJS} ${BONUS_OBJS} | $(DIR_BIN)
	

$(DIR_BIN):
	@mkdir -p $@

clean:
	@${RM} $(DIR_BIN)

fclean: clean
	@${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re bonus
