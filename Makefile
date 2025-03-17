#
# ░█▄█░▀█▀░█▀█░▀█▀░█▀▀░█░█░█▀▀░█░░░█░░
# ░█░█░░█░░█░█░░█░░▀▀█░█▀█░█▀▀░█░░░█░░
# ░▀░▀░▀▀▀░▀░▀░▀▀▀░▀▀▀░▀░▀░▀▀▀░▀▀▀░▀▀▀
#               by joao-alm & vigde-ol

# Compiler Settings
CC			= cc
CFLAGS		= -Wall -Werror -Wextra -g
RM			= rm -rf
O_DIR		= .obj
header		= .obj/header
sleep		= 0.01

# Lib Files
JAL			= lib/libjal.a
ADD_LIBS	= -L lib -l jal \
			  -L usr/include/readline -l readline -l ncurses
LIBS_INC	= -I lib/include \
			  -I /usr/include/readline

# Mandatory Files
NAME	= minishell
M_SRC	= src/main/main.c \
		  src/main/error.c \
		  src/main/exit.c
M_INC	= -Iinclude
M_OBJ	= $(M_SRC:src/%.c=$(O_DIR)/$(notdir %.o))

# Mandatory Rules
all: $(header) $(JAL) $(NAME)

$(NAME): $(M_OBJ)
	@printf "Compiling [$(y)$(NAME)$(r)]: executable$(c)\r"
	@$(CC) $(CFLAGS) $(M_OBJ) -o $@ $(ADD_LIBS)
	@printf "Compiling [$(y)$(NAME)$(r)]: $(g)Success$(r)$(c)\n"

$(O_DIR)/%.o: src/%.c
	@mkdir -p $(dir $@)
	@printf "Compiling [$(y)$(NAME)$(r)]: $(notdir $@)$(c)\r"
	@$(CC) $(CFLAGS) -c $< -o $@ $(M_INC) $(LIBS_INC)

clean:
	@make -C lib clean --no-print-directory
	@printf "Removing [$(p).objs$(r)]: $(O_DIR)$(c)\r"
	@sleep $(sleep)
	@$(RM) $(O_DIR)
	@printf "Removing [$(p).objs$(r)]: $(g)Success$(r)$(c)\n"

fclean:
	@make -C lib fclean --no-print-directory
	@printf "Removing [$(p).objs$(r)]: $(O_DIR)$(c)\r"
	@sleep $(sleep)
	@$(RM) $(O_DIR)
	@printf "Removing [$(p)$(NAME)$(r)]: $(NAME)$(c)\r"
	@sleep $(sleep)
	@$(RM) $(NAME)
	@printf "Removing [$(p)$(NAME)$(r)]: $(g)Success$(r)$(c)\n"

re: fclean all

# Lib Rule
$(JAL):
	@make -C lib --no-print-directory

# Colours
c	= \033[K
p	= \033[38;2;231;133;190m
y	= \033[38;2;255;248;147m
g	= \033[38;2;129;223;164m
b	= \033[1m
r	= \033[0m

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

# Phony
.PHONY: all clean fclean re

