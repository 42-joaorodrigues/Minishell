########################################################################################
#                                      ▗▖   ▗▄▄▄▖▗▄▄▖                                  #
#                                      ▐▌     █  ▐▌ ▐▌                                 #
#                                      ▐▌     █  ▐▛▀▚▖                                 #
#                                      ▐▙▄▄▖▗▄█▄▖▐▙▄▞▘                                 #
########################################################################################

# Compiler Settings
NAME  	= libmylib.a
LIBC  	= ar rcs
CC    	= cc
CFLAGS	= -Wall -Werror -Wextra -g
RM    	= rm -rf
O_DIR	= .obj
sleep	= 0.01

# Files
SRC	= $(wildcard src/**/*.c)
INC	= -Iinclude
OBJ	= $(SRC:src/%.c=$(O_DIR)/%.o)

# Mandatory Rules
all: $(NAME)

$(NAME): $(OBJ)
	@printf "Compiling [$(y)$(NAME)$(r)]: executable$(c)\r"
	@$(LIBC) $@ $(OBJ)
	@printf "Compiling [$(y)$(NAME)$(r)]: $(g)Success$(r)$(c)\n"

$(O_DIR)/%.o: src/%.c
	@mkdir -p $(dir $@)
	@printf "Compiling [$(y)$(NAME)$(r)]: $(notdir $@)$(c)\r"
	@$(CC) $(CFLAGS) -c $< -o $@ $(INC)

clean:
	@printf "Removing [$(p)$(NAME)$(r)]: $(O_DIR)$(c)\r"
	@sleep $(sleep)
	@$(RM) $(O_DIR)
	@printf "Removing [$(p)$(NAME)$(r)]: $(g)Success$(r)$(c)\n"

fclean:
	@printf "Removing [$(p)$(NAME)$(r)]: $(NAME)$(c)\r"
	@sleep $(sleep)
	@$(RM) $(NAME)
	@printf "Removing [$(p)$(NAME)$(r)]: $(O_DIR)$(c)\r"
	@sleep $(sleep)
	@$(RM) $(O_DIR)
	@printf "Removing [$(p)$(NAME)$(r)]: $(g)Success$(r)$(c)\n"

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
