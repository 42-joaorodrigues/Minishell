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

# Mandatory Files
NAME		= minishell
M_INC		= -Iinclude
M_SRC		= src/main/main.c \
			  src/main/init.c \
			  src/parser/lexer.c \
			  src/parser/parser.c \
			  src/util/token_util.c \
			  src/util/error.c \
			  src/test/test_tokens.c
M_OBJ		= $(M_SRC:src/%.c=$(O_DIR)/$(notdir %.o))

# Lib Files
JAL			= lib/libjal.a
JAL_O_DIR	= lib/.obj
ADD_LIBS	= -L lib -l jal \
			  -L usr/include/readline -l readline -l ncurses
LIBS_INC	= -I lib/include \
			  -I /usr/include/readline

# Mandatory Rules
all: $(header) $(JAL) $(NAME)

$(O_DIR)/%.o: src/%.c
	@mkdir -p $(dir $@)
	@printf "Compiling [$(y)$(NAME)$(r)]: $(notdir $@)$(c)\r"
	@$(CC) $(CFLAGS) -c $< -o $@ $(M_INC) $(LIBS_INC)

$(NAME): $(M_OBJ)
	@printf "Compiling [$(y)$(NAME)$(r)]: executable$(c)\r"
	@$(CC) $(CFLAGS) $(M_OBJ) -o $@ $(ADD_LIBS)
	@printf "Compiling [$(y)$(NAME)$(r)]: $(g)Success$(r)$(c)\n"

clean:
	@if [ ! -d $(JAL_O_DIR) ] && [ ! -d $(O_DIR) ]; then printf "Nothing to remove\n"; fi
	@if [ -d $(JAL_O_DIR) ]; then make -C lib clean --no-print-directory; fi
	@if [ -d $(O_DIR) ]; then make .remove tname="minishell objects" t1=$(O_DIR) --no-print-directory; fi

fclean:
	@if [ ! -d $(JAL_O_DIR) ] && [ ! -f $(JAL) ] \
		&& [ ! -d $(O_DIR) ] && [ ! -f $(NAME) ]; then \
		printf "Nothing to remove\n"; \
	fi
	@if [ -d $(JAL_O_DIR) ] || [ -f $(JAL) ]; then make -C lib fclean --no-print-directory; fi
	@if [ -d $(O_DIR) ] || [ -f $(NAME) ]; then make .remove tname=$(NAME) t1=$(NAME) t2=$(O_DIR) --no-print-directory; fi

re: fclean all

# Lib Rule
$(JAL):
	@make -C lib --no-print-directory

# Custom Rules
.remove:
	@$(RM) $(t1)
	@$(RM) $(t2)
	@printf "Removing [$(p)$(tname)$(r)]: $(g)Success$(r)\n"

valgrind:
	@if [ ! -f $(valgrind) ] || [ ! -f $(supp) ]; then \
		printf "Generating [$(y)$(valgrind)$(r)]: executable$(c)\r"; \
		echo "{" > $(supp); \
		echo "readline" >> $(supp); \
		echo "Memcheck:Leak" >> $(supp); \
		echo "..." >> $(supp); \
		echo "fun:readline" >> $(supp); \
		echo "}" >> $(supp); \
		echo "{" >> $(supp); \
		echo "add_history" >> $(supp); \
		echo "Memcheck:Leak" >> $(supp); \
		echo "..." >> $(supp); \
		echo "fun:add_history" >> $(supp); \
		echo "}" >> $(supp); \
		echo "#!/bin/bash" > $(valgrind); \
		echo "valgrind --leak-check=full --track-origins=yes --show-leak-kinds=all --suppressions=$(supp) ./minishell" >> $(valgrind); \
		chmod +x $(valgrind); \
		printf "Generating [$(y)$(valgrind)$(r)]: $(g)Success$(r)$(c)\n"; \
	else \
		printf "make: 'valgrind' is up to date.\n"; \
	fi;

remove_valgrind:
	@if [ -f $(valgrind) ] || [ -f $(supp) ]; then \
  		make .remove tname=$(valgrind) t1=$(valgrind) t2=$(supp) --no-print-directory; \
  	else \
  		printf "Nothing to remove\n"; \
  	fi

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
