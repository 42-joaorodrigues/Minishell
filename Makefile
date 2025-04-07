#
# ░█▄█░▀█▀░█▀█░▀█▀░█▀▀░█░█░█▀▀░█░░░█░░
# ░█░█░░█░░█░█░░█░░▀▀█░█▀█░█▀▀░█░░░█░░
# ░▀░▀░▀▀▀░▀░▀░▀▀▀░▀▀▀░▀░▀░▀▀▀░▀▀▀░▀▀▀
#               by joao-alm & vigde-ol

# Compiler Settings
header			= .obj/header
CC				= cc
CFLAGS			= -Wall -Werror -Wextra -g
RM				= rm -rf
O_DIR			= .obj
VALGRIND_SH		= valgrind.sh
VALGRIND_SUPP	= valgrind.supp
col1pad			= 12
col2pad			= 15

# Mandatory Files
NAME			= minishell
INC				= -Iinclude
SRC_BUILTIN		= src/builtin/builtin.c \
				  src/builtin/cd.c \
				  src/builtin/echo.c \
				  src/builtin/pwd.c
SRC_COMMAND		= src/command/command_list.c \
				  src/command/command_list_util.c \
				  src/command/exec_command.c
SRC_MAIN		= src/main/main.c
SRC_TEST		= src/test/test_tokens.c \
				  src/test/test_commands.c
SRC_TOKEN		= src/token/expander.c \
				  src/token/expander_util.c \
				  src/token/token.c \
				  src/token/token_char_util.c \
				  src/token/token_util.c
SRC_UTIL		= src/util/env_util.c \
				  src/util/error.c \
				  src/util/quote_util.c
SRC				= $(SRC_BUILTIN) $(SRC_COMMAND) $(SRC_MAIN) $(SRC_TEST) $(SRC_TOKEN) $(SRC_UTIL)
OBJ				= $(SRC:src/%.c=$(O_DIR)/$(notdir %.o))

# Lib Files
JAL				= lib/libjal.a
JAL_O_DIR		= lib/.obj
ADD_LIBS		= -L lib -l jal \
				  -L usr/include/readline -l readline -l ncurses
LIBS_INC		= -I lib/include \
				  -I /usr/include/readline

# Mandatory Rules
all: $(header) $(JAL) $(NAME) valgrind_script

$(O_DIR)/%.o: src/%.c
	@mkdir -p $(dir $@)
	@make .print_start print_color="$(y)" print_action="Compiling" print_name=$(NAME) print_file=$(notdir $@) --no-print-directory
	@$(CC) $(CFLAGS) -c $< -o $@ $(INC) $(LIBS_INC)

$(NAME): $(OBJ)
	@make .print_start print_color="$(y)" print_action="Compiling" print_name=$(NAME) print_file=$(NAME) --no-print-directory
	@$(CC) $(CFLAGS) $(OBJ) -o $@ $(ADD_LIBS)
	@make .print_end print_color="$(y)" print_action="Compiling" print_name=$(NAME) --no-print-directory

clean:
	@if [ ! -d $(O_DIR) ]; then printf "Nothing to remove\n"; fi
	@if [ -d $(O_DIR) ]; then make .remove tname="minishell_objects" t1=$(O_DIR) --no-print-directory; fi

fclean:
	@if [ ! -d $(O_DIR) ] && [ ! -f $(NAME) ]; then printf "Nothing to remove\n"; fi
	@if [ -d $(O_DIR) ] || [ -f $(NAME) ]; then make .remove tname=$(NAME) t1=$(NAME) t2=$(O_DIR) --no-print-directory; fi

re: fclean all

# Lib Rules
lib: $(JAL)

$(JAL):
	@make -C lib col1pad=$(col1pad) col2pad=$(col2pad) --no-print-directory

lib_clean:
	@if [ ! -d $(JAL_O_DIR) ]; then printf "Nothing to remove\n"; fi
	@if [ -d $(JAL_O_DIR) ]; then make -C lib clean col1pad=$(col1pad) col2pad=$(col2pad) --no-print-directory; fi

lib_fclean:
	@if [ ! -d $(JAL_O_DIR) ] && [ ! -f $(JAL) ]; then printf "Nothing to remove\n"; fi
	@if [ -d $(JAL_O_DIR) ] || [ -f $(JAL) ]; then make -C lib fclean col1pad=$(col1pad) col2pad=$(col2pad) --no-print-directory; fi

lib_re: lib_fclean lib

# Valgrind Helper Rules
valgrind:
	@echo "Use \`make valgrind_script\` instead of \`make valgrind\`."
	@false

valgrind_script: $(VALGRIND_SH) $(VALGRIND_SUPP)

$(VALGRIND_SH):
	@make .print_start print_color="$(g)" print_action="Downloading" print_name=$(VALGRIND_SH) print_file=$(VALGRIND_SH) --no-print-directory
	@wget -q https://raw.githubusercontent.com/joao-alm/42/refs/heads/main/Minishell/Joao/valgrind.sh
	@chmod +x $(VALGRIND_SH)
	@make .print_end print_color="$(g)" print_action="Downloading" print_name=$(VALGRIND_SH) --no-print-directory

$(VALGRIND_SUPP):
	@make .print_start print_color="$(g)" print_action="Downloading" print_name=$(VALGRIND_SUPP) print_file=$(VALGRIND_SUPP) --no-print-directory
	@wget -q https://raw.githubusercontent.com/joao-alm/42/refs/heads/main/Minishell/Joao/valgrind.supp
	@make .print_end print_color="$(g)" print_action="Downloading" print_name=$(VALGRIND_SUPP) --no-print-directory

valgrind_clean:
	@if [ ! -f $(VALGRIND_SH) ] && [ !  -f $(VALGRIND_SUPP) ]; then printf "Nothing to remove\n"; fi
	@if [ -f $(VALGRIND_SH) ]; then make .remove tname=$(VALGRIND_SH) t1=$(VALGRIND_SH) --no-print-directory; fi
	@if [ -f $(VALGRIND_SUPP) ]; then make .remove tname=$(VALGRIND_SUPP) t1=$(VALGRIND_SUPP) --no-print-directory; fi

# Universal clean
fullclean:
	@if [ ! -d $(JAL_O_DIR) ] && [ ! -f $(JAL) ] && [ ! -d $(O_DIR) ] && [ ! -f $(NAME) ] && [ ! -f $(VALGRIND_SH) ] && [ !  -f $(VALGRIND_SUPP) ] ; then printf "Nothing to remove\n"; fi
	@if [ -d $(JAL_O_DIR) ] || [ -f $(JAL) ]; then make -C lib fclean col1pad=$(col1pad) col2pad=$(col2pad) --no-print-directory; fi
	@if [ -d $(O_DIR) ] || [ -f $(NAME) ]; then make .remove tname=$(NAME) t1=$(NAME) t2=$(O_DIR) --no-print-directory; fi
	@if [ -f $(VALGRIND_SH) ]; then make .remove tname=$(VALGRIND_SH) t1=$(VALGRIND_SH) --no-print-directory; fi
	@if [ -f $(VALGRIND_SUPP) ]; then make .remove tname=$(VALGRIND_SUPP) t1=$(VALGRIND_SUPP) --no-print-directory; fi

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
