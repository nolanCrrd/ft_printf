CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = libftprintf.a

SRCS_FOLDER = srcs/
INCLUDES_FOLDER = includes/
OBJECTS_FOLDER = objects/

SRCS = $(SRCS_FOLDER)ft_printf.c \
	$(SRCS_FOLDER)/converters/xtoa.c \
	$(SRCS_FOLDER)/converters/ulltoa.c \
	$(SRCS_FOLDER)/converters/lltoa.c \
	$(SRCS_FOLDER)/utils/printing_utils.c \

OBJS = $(addprefix $(OBJECTS_FOLDER),$(SRCS:.c=.o))

AR = ar
ARFLAGS = rcs
RM = rm -rf

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(ARFLAGS) $(NAME) $(OBJS)

$(OBJECTS_FOLDER)%.o: %.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -I $(INCLUDES_FOLDER) -c $< -o $@

clean:
	$(RM) $(OBJECTS_FOLDER)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
