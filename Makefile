#
# ░█▄█░▀█▀░█▀█░▀█▀░█▀▀░█░█░█▀▀░█░░░█░░
# ░█░█░░█░░█░█░░█░░▀▀█░█▀█░█▀▀░█░░░█░░
# ░▀░▀░▀▀▀░▀░▀░▀▀▀░▀▀▀░▀░▀░▀▀▀░▀▀▀░▀▀▀
#               by joao-alm & vigde-ol

# Compiler Settings
header		= .obj/header
CC			= cc
CFLAGS		= -Wall -Werror -Wextra -g
RM			= rm -rf
O_DIR		= .obj
valgrind	= valgrind.sh
supp		= valgrind.supp
col1pad		= 12
col2pad		= 15

# Mandatory Files
NAME		= minishell
INC			= -Iinclude
SRC_MAIN	= src/main/main.c \
			  src/main/init.c
SRC_PARSER	= src/parser/expander.c \
			  src/parser/expander_util.c \
			  src/parser/lexer.c \
			  src/parser/parser.c \
			  src/parser/quote_handler.c \
			  src/parser/quote_util.c \
			  src/parser/token_util.c
SRC_COMMAND	= src/command/command.c \
			  src/command/command_util.c
SRC_UTIL	= src/util/error.c
SRC_TEST	= src/test/test_tokens.c
SRC			= $(SRC_MAIN) $(SRC_PARSER) $(SRC_COMMAND) $(SRC_UTIL) $(SRC_TEST)
OBJ		= $(SRC:src/%.c=$(O_DIR)/$(notdir %.o))

# Lib Files
JAL			= lib/libjal.a
JAL_O_DIR	= lib/.obj
ADD_LIBS	= -L lib -l jal \
			  -L usr/include/readline -l readline -l ncurses
LIBS_INC	= -I lib/include \
			  -I /usr/include/readline

# Mandatory Rules
all: $(header) $(JAL) $(NAME) $(valgrind) $(supp)

$(O_DIR)/%.o: src/%.c
	@mkdir -p $(dir $@)
	@make .print_start print_color="$(y)" print_action="Compiling" print_name=$(NAME) print_file=$(notdir $@) --no-print-directory
	@$(CC) $(CFLAGS) -c $< -o $@ $(INC) $(LIBS_INC)

$(NAME): $(OBJ)
	@make .print_start print_color="$(y)" print_action="Compiling" print_name=$(NAME) print_file=$(NAME) --no-print-directory
	@$(CC) $(CFLAGS) $(OBJ) -o $@ $(ADD_LIBS)
	@make .print_end print_color="$(y)" print_action="Compiling" print_name=$(NAME) --no-print-directory

clean:
	@if [ ! -d $(JAL_O_DIR) ] && [ ! -d $(O_DIR) ]; then printf "Nothing to remove\n"; fi
	@if [ -d $(JAL_O_DIR) ]; then make -C lib clean col1pad=$(col1pad) col2pad=$(col2pad) --no-print-directory; fi
	@if [ -d $(O_DIR) ]; then make .remove tname="minishell_objects" t1=$(O_DIR) --no-print-directory; fi

fclean:
	@if [ ! -d $(JAL_O_DIR) ] && [ ! -f $(JAL) ] \
		&& [ ! -d $(O_DIR) ] && [ ! -f $(NAME) ] \
		&& [ ! -f $(valgrind) ] && [ !  -f $(supp) ] ; then \
		printf "Nothing to remove\n"; \
	fi
	@if [ -d $(JAL_O_DIR) ] || [ -f $(JAL) ]; then make -C lib fclean col1pad=$(col1pad) col2pad=$(col2pad) --no-print-directory; fi
	@if [ -d $(O_DIR) ] || [ -f $(NAME) ]; then make .remove tname=$(NAME) t1=$(NAME) t2=$(O_DIR) --no-print-directory; fi
	@if [ -f $(valgrind) ]; then make .remove tname=$(valgrind) t1=$(valgrind) --no-print-directory; fi
	@if [ -f $(supp) ]; then make .remove tname=$(supp) t1=$(supp) --no-print-directory; fi

re: fclean all

# Lib Rule
$(JAL):
	@make -C lib col1pad=$(col1pad) col2pad=$(col2pad) --no-print-directory

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

$(valgrind):
	@make .print_start print_color="$(g)" print_action="Downloading" print_name=$(valgrind) print_file=$(valgrind) --no-print-directory
	@wget -q https://raw.githubusercontent.com/joao-alm/42/refs/heads/main/Minishell/Joao/valgrind.sh
	@chmod +x $(valgrind)
	@make .print_end print_color="$(g)" print_action="Downloading" print_name=$(valgrind) --no-print-directory

$(supp):
	@make .print_start print_color="$(g)" print_action="Downloading" print_name=$(supp) print_file=$(supp) --no-print-directory
	@wget -q https://raw.githubusercontent.com/joao-alm/42/refs/heads/main/Minishell/Joao/valgrind.supp
	@make .print_end print_color="$(g)" print_action="Downloading" print_name=$(supp) --no-print-directory

# Headers
$(header):
	@mkdir -p $(O_DIR)
	@printf "$(y)\n"
	@printf "░█▄█░▀█▀░█▀█░▀█▀░█▀▀░█░█░█▀▀░█░░░█░░\n"
	@printf "░█░█░░█░░█░█░░█░░▀▀█░█▀█░█▀▀░█░░░█░░\n"
	@printf "░▀░▀░▀▀▀░▀░▀░▀▀▀░▀▀▀░▀░▀░▀▀▀░▀▀▀░▀▀▀\n"
	@printf "              by joao-alm & vigde-ol\n"
	@printf "$(r)\n"
	@touch $(header)

# Colours
c	= \033[K
p	= \033[38;2;231;133;190m
y	= \033[38;2;255;248;147m
g	= \033[38;2;129;223;164m
b	= \033[1m
r	= \033[0m

# Phony
.PHONY: all clean fclean re
