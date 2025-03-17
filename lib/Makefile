#
# ░▀▀█░█▀█░█▀█░█▀█░░░░░█▀█░█░░░█▄█░░░░░█░░░▀█▀░█▀▄
# ░░░█░█░█░█▀█░█░█░▄▄▄░█▀█░█░░░█░█░░░░░█░░░░█░░█▀▄
# ░▀▀░░▀▀▀░▀░▀░▀▀▀░░░░░▀░▀░▀▀▀░▀░▀░▀▀▀░▀▀▀░▀▀▀░▀▀░
#                                      by joao-alm

# Compiler Settings
NAME			= libjal.a
DISPLAY_NAME	= joao-alm_lib
LIBC			= ar rcs
CC				= cc
CFLAGS			= -Wall -Werror -Wextra -g
RM				= rm -rf
O_DIR			= .obj
sleep			= 0.01

# Char Files
SRC_CHAR 		= src/char/ft_isalnum.c \
				  src/char/ft_isalpha.c \
				  src/char/ft_isascii.c \
				  src/char/ft_isdigit.c \
				  src/char/ft_isprint.c
# Conversion Files
SRC_CONV		= src/conversion/atoll_valid.c \
				  src/conversion/ft_atoi.c \
				  src/conversion/ft_itoa.c \
				  src/conversion/ft_tolower.c
# GetNextLine Files
SRC_GNL			= src/gnl/get_next_line.c \
                  src/gnl/get_next_line_utils.c
# List Files
SRC_LIST		= src/list/ft_lstadd_back_bonus.c \
                  src/list/ft_lstadd_front_bonus.c \
                  src/list/ft_lstclear_bonus.c \
                  src/list/ft_lstdelone_bonus.c \
                  src/list/ft_lstiter_bonus.c \
                  src/list/ft_lstlast_bonus.c \
                  src/list/ft_lstmap_bonus.c \
                  src/list/ft_lstnew_bonus.c \
                  src/list/ft_lstsize_bonus.c \
                  src/list/lstdel_safely.c \
                  src/list/lstdetach.c \
                  src/list/lstdup.c \
                  src/list/lstget_int.c \
                  src/list/lstnew_int.c
# Memory Files
SRC_MEM			= src/memory/free_matrix.c \
                  src/memory/ft_bzero.c \
                  src/memory/ft_calloc.c \
                  src/memory/ft_memchr.c \
                  src/memory/ft_memcmp.c \
                  src/memory/ft_memcpy.c \
                  src/memory/ft_memmove.c \
                  src/memory/ft_memset.c \
                  src/memory/realloc.c \
                  src/memory/sort_tab.c
# Print Files
SRC_PRINT		= src/print/ft_printf.c \
                  src/print/put_characters.c \
                  src/print/put_numbers.c
# String Files
SRC_STRING		= src/string/ft_split.c \
                  src/string/ft_strchr.c \
                  src/string/ft_strcmp.c \
                  src/string/ft_strdup.c \
                  src/string/ft_striteri.c \
                  src/string/ft_strjoin.c \
                  src/string/ft_strlcat.c \
                  src/string/ft_strlcpy.c \
                  src/string/ft_strlen.c \
                  src/string/ft_strmapi.c \
                  src/string/ft_strncmp.c \
                  src/string/ft_strnstr.c \
                  src/string/ft_strrchr.c \
                  src/string/ft_strtrim.c \
                  src/string/ft_substr.c \
                  src/string/strcpy.c

# Files
SRC				= $(SRC_CHAR) $(SRC_CONV) $(SRC_GNL) $(SRC_LIST) \
				  $(SRC_MEM) $(SRC_PRINT) $(SRC_LIST)
INC				= -Iinclude
OBJ				= $(SRC:src/%.c=$(O_DIR)/%.o)

# Mandatory Rules
all: $(NAME)

$(NAME): $(OBJ)
	@printf "Compiling [$(y)$(DISPLAY_NAME)$(r)]: executable$(c)\r"
	@$(LIBC) $@ $(OBJ)
	@printf "Compiling [$(y)$(DISPLAY_NAME)$(r)]: $(g)Success$(r)$(c)\n"

$(O_DIR)/%.o: src/%.c
	@mkdir -p $(dir $@)
	@printf "Compiling [$(y)$(DISPLAY_NAME)$(r)]: $(notdir $@)$(c)\r"
	@$(CC) $(CFLAGS) -c $< -o $@ $(INC)

clean:
	@printf "Removing [$(p)$(DISPLAY_NAME)$(r)]: $(O_DIR)$(c)\r"
	@sleep $(sleep)
	@$(RM) $(O_DIR)
	@printf "Removing [$(p)$(DISPLAY_NAME)$(r)]: $(g)Success$(r)$(c)\n"

fclean:
	@printf "Removing [$(p)$(DISPLAY_NAME)$(r)]: $(NAME)$(c)\r"
	@sleep $(sleep)
	@$(RM) $(NAME)
	@printf "Removing [$(p)$(DISPLAY_NAME)$(r)]: $(O_DIR)$(c)\r"
	@sleep $(sleep)
	@$(RM) $(O_DIR)
	@printf "Removing [$(p)$(DISPLAY_NAME)$(r)]: $(g)Success$(r)$(c)\n"

re: fclean all

# Colours
c	= \033[K
p	= \033[38;2;231;133;190m
y	= \033[38;2;255;248;147m
g	= \033[38;2;129;223;164m
b	= \033[1m
r	= \033[0m

# Phony
.PHONY: all clean fclean re
