#
# ░▀▀█░█▀█░█▀█░█▀█░░░░░█▀█░█░░░█▄█░░░░░█░░░▀█▀░█▀▄
# ░░░█░█░█░█▀█░█░█░▄▄▄░█▀█░█░░░█░█░░░░░█░░░░█░░█▀▄
# ░▀▀░░▀▀▀░▀░▀░▀▀▀░░░░░▀░▀░▀▀▀░▀░▀░▀▀▀░▀▀▀░▀▀▀░▀▀░
#                                      by joao-alm

# Compiler Settings
NAME			= libjal.a
LIBC			= ar rcs
CC				= cc
CFLAGS			= -Wall -Werror -Wextra -g
RM				= rm -rf
O_DIR			= .obj

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
				  src/print/ft_putchar_fd.c \
				  src/print/ft_putendl_fd.c \
				  src/print/ft_putnbr_fd.c \
				  src/print/ft_putstr_fd.c \
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
                  src/string/strcpy.c \
                  src/string/strndup.c \
                  src/string/strjoin_free.c \
                  src/string/intlen.c

# Files
SRC				= $(SRC_CHAR) $(SRC_CONV) $(SRC_GNL) $(SRC_LIST) \
				  $(SRC_MEM) $(SRC_PRINT) $(SRC_STRING)
INC				= -I include
OBJ				= $(SRC:src/%.c=$(O_DIR)/%.o)

# Mandatory Rules
all: $(NAME)

$(O_DIR)/%.o: src/%.c
	@mkdir -p $(dir $@)
	@make .print_start print_color="$(y)" print_action="Compiling" print_name=$(NAME) print_file=$(notdir $@) --no-print-directory
	@$(CC) $(CFLAGS) -c $< -o $@ $(INC)

$(NAME): $(OBJ)
	@make .print_start print_color="$(y)" print_action="Compiling" print_name=$(NAME) print_file=$(NAME) --no-print-directory
	@$(LIBC) $@ $(OBJ)
	@make .print_end print_color="$(y)" print_action="Compiling" print_name=$(NAME) --no-print-directory

clean:
	@if [ ! -d $(O_DIR) ]; then printf "Nothing to remove\n"; fi
	@if [ -d $(O_DIR) ]; then make .remove tname="joao-alm_lib_objects" t1=$(O_DIR) t2=$(O_DIR) --no-print-directory; fi

fclean:
	@if [ ! -d $(O_DIR) ] && [ ! -f $(NAME) ]; then printf "Nothing to remove\n"; fi
	@if [ -d $(O_DIR) ] || [ -f $(NAME) ]; then make .remove tname="joao-alm_lib" t1=$(O_DIR) t2=$(NAME) --no-print-directory; fi

re: fclean all

# Custom Rules
.print_start:
	@printf "$(print_color)%-$(col1pad).$(col1pad)s$(r) %-$(col2pad).$(col2pad)s %s$(c)\r" "$(print_action)" "$(print_name)" "$(print_file)"

.print_end:
	@printf "$(print_color)%-$(col1pad).$(col1pad)s$(r) %-$(col2pad).$(col2pad)s $(g)Success$(r)$(c)\n" "$(print_action)" "$(print_name)"

.remove:
	@make .print_start print_color="$(p)" print_action="Removing" print_name=$(tname) print_file=$(t1) --no-print-directory
	@$(RM) $(t1)
	@make .print_start print_color="$(p)" print_action="Removing" print_name=$(tname) print_file=$(t2) --no-print-directory
	@$(RM) $(t2)
	@make .print_end print_color="$(p)" print_action="Removing" print_name=$(tname) --no-print-directory

# Colours
c	= \033[K
p	= \033[38;2;231;133;190m
y	= \033[38;2;255;248;147m
g	= \033[38;2;129;223;164m
b	= \033[1m
r	= \033[0m

# Phony
.PHONY: all clean fclean re
