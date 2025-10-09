CC      = gcc
CFLAGS  = -Wall -Wextra -Werror -Iinc/logic -Iinc/graphics  -I/opt/homebrew/include
LDFLAGS = -L/opt/homebrew/lib -lraylib -framework OpenGL -framework Cocoa -framework IOKit

BIN     = briscola
OBJ_DIR = obj

SRCS    = src/main.c							\
		  src/logic/computer.c					\
		  src/logic/data.c						\
		  src/logic/deck.c						\
		  src/logic/get_input.c					\
		  src/logic/play.c						\
		  src/logic/player.c					\
		  src/logic/print.c						\
		  src/logic/set_up.c					\
		  src/graphics/graphics_data.c		

OBJS    = $(SRCS:src/%.c=$(OBJ_DIR)/%.o)

all: $(BIN)

$(BIN): $(OBJS)
	@$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)

$(OBJ_DIR)/%.o: src/%.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -rf $(OBJ_DIR)

fclean:
	@rm -rf $(OBJ_DIR) $(BIN)

re: fclean all
