#-----------Dichiarazione di nomi e percorsi in variabili
SERVER            := server
CLIENT            := client
SERVER_BONUS      := server_bonus
CLIENT_BONUS      := client_bonus
LIB               := ft
LIB_TARGET        := libft/libft.a
INCS              := ./include
SRC_DIR           := src
SRC_DIR_BONUS     := src_bonus

#-----------File da compilare per server e client
SRCS_SERVER       := $(SRC_DIR)/server.c
SRCS_CLIENT       := $(SRC_DIR)/client.c
SRCS_SERVER_BONUS := $(SRC_DIR_BONUS)/server_bonus.c
SRCS_CLIENT_BONUS := $(SRC_DIR_BONUS)/client_bonus.c

BUILD_DIR         := .build
OBJS_SERVER       := $(SRCS_SERVER:$(SRC_DIR)/%.c=$(BUILD_DIR)/%.o)
OBJS_CLIENT       := $(SRCS_CLIENT:$(SRC_DIR)/%.c=$(BUILD_DIR)/%.o)
OBJS_SERVER_BONUS := $(SRCS_SERVER_BONUS:$(SRC_DIR_BONUS)/%.c=$(BUILD_DIR)/%.o)
OBJS_CLIENT_BONUS := $(SRCS_CLIENT_BONUS:$(SRC_DIR_BONUS)/%.c=$(BUILD_DIR)/%.o)
DEPS              := $(OBJS_SERVER:.o=.d) $(OBJS_CLIENT:.o=.d)
DEPS_BONUS        := $(OBJS_SERVER_BONUS:.o=.d) $(OBJS_CLIENT_BONUS:.o=.d)

CC                := cc
CFLAGS            := -Wall -Wextra -Werror
CPPFLAGS          := $(addprefix -I,$(INCS)) -MMD -MP
LDFLAGS           := $(addprefix -L,$(dir $(LIB_TARGET)))
LDLIB             := $(addprefix -l,$(LIB))

RM                := rm -rf
MAKEFLAGS         := --no-print-directory

DIR_DUP           := mkdir -p $(@D)

.PHONY: clean fclean re all bonus
.SILENT:
# Rules ----------------------------------------------------------------------->

all: clear_screen banner $(LIB_TARGET) $(SERVER) $(CLIENT)

$(SERVER): $(OBJS_SERVER) $(LIB_TARGET)
	$(CC) $(LDFLAGS) $^ $(LDLIB) -o $@
	${info ${BOLD}Creating  -> ${RED}$(SERVER)${NO_COLOR}}

$(CLIENT): $(OBJS_CLIENT) $(LIB_TARGET)
	$(CC) $(LDFLAGS) $^ $(LDLIB) -o $@
	${info ${BOLD}Creating  -> ${RED}$(CLIENT)${NO_COLOR}}

$(LIB_TARGET):
	$(MAKE) -C $(@D)

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	$(DIR_DUP) $(@D)
	$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@
	${info ${BOLD}Compiling -> ${BLUE}$@${NO_COLOR}}

-include $(DEPS)

clean:
	for f in $(dir $(LIB_TARGET)); do $(MAKE) -C $$f clean; done
	$(RM) $(BUILD_DIR)
	${info ${BOLD}${YELLOW}Cleaning in progress...${NO_COLOR}}

fclean: clean
	for f in $(dir $(LIB_TARGET)); do $(MAKE) -C $$f fclean; done
	$(RM) $(SERVER) $(CLIENT) $(SERVER_BONUS) $(CLIENT_BONUS)

bonus: clear_screen banner $(LIB_TARGET) $(SERVER_BONUS) $(CLIENT_BONUS)
$(SERVER_BONUS): $(OBJS_SERVER_BONUS) $(LIB_TARGET)
	$(CC) $(LDFLAGS) $^ $(LDLIB) -o $@
	${info ${BOLD}Creating  -> ${RED}$(SERVER_BONUS)${NO_COLOR}}

$(CLIENT_BONUS): $(OBJS_CLIENT_BONUS) $(LIB_TARGET)
	$(CC) $(LDFLAGS) $^ $(LDLIB) -o $@
	${info ${BOLD}Creating  -> ${RED}$(CLIENT_BONUS)${NO_COLOR}}

$(BUILD_DIR)/%.o: $(SRC_DIR_BONUS)/%.c
	$(DIR_DUP) $(@D)
	$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@
	${info ${BOLD}Compiling -> ${BLUE}$@${NO_COLOR}}

-include $(DEPS_BONUS)

re: fclean all

clear_screen:
	@clear

download:
	if [ ! -f test.sh ]; then \
		git clone https://github.com/CapSte42/utility.git > /dev/null 2>&1; \
		mv utility/minitalk/tester.sh .; \
		cat utility/minitalk/README.md; \
		echo "${YELLOW}${BOLD}credit: ---> https://github.com/ThibaudM13/minitalk-Tester.git <---${NO_COLOR}"; \
		rm -rf utility; \
	fi
	chmod +x+r *.sh

download_clean:
	if [ -f tester.sh ]; then \
		rm tester.sh; \
	fi

# Colors ---------------------------------------------------------------------->
RED 		:= ${shell tput setaf 1}
YELLOW		:= ${shell tput setaf 3}
BLUE		:= ${shell tput setaf 4}
NO_COLOR	:= ${shell tput sgr0}
BOLD		:= ${shell tput bold}
GREEN		:= ${shell tput setaf 2}
BLINK		:= ${shell tput blink}

banner:
	@echo '${GREEN}                           '
	@echo '  / \_/`\  __          __          '
	@echo ' /\      \/\_\    ___ /\_\         '
	@echo ' \ \ \__\ \/\ \ /  _ `\/\ \        '
	@echo '  \ \ \_/\ \ \ \/\ \/\ \ \ \       '
	@echo '   \ \_\\ \_\ \_\ \_\ \_\ \_\      '
	@echo '    \/_/ \/_/\/_/\/_/\/_/\/_/      '
	@echo '                                   '
	@echo '             _______               '
	@echo '            /\______\              '
	@echo '            \/______/              '
	@echo '                                   '
	@echo '  __             ___    __         '
	@echo ' /\ \__         /\_ \  /\ \        '
	@echo ' \ \ ,_\    __  \//\ \ \ \ \/ \    '
	@echo '  \ \ \/  / __`\  \ \ \ \ \ , <    '
	@echo '   \ \ \_/\ \L\.\_ \_\ \_\ \ \\`\  '
	@echo '    \ \__\ \__/.\_\/\____\\ \_\ \_\'
	@echo '     \/__/\/__/\/_/\/____/ \/_/\/_/'
	@echo '       ✨ ${BOLD}mini_talk ✨      '
	@echo '${NO_COLOR}'