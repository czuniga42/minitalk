#Variables
CC = cc
CFLAGS = -Wall -Wextra -Werror -Ilibft
LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a
#LIBFT_OBJS = $(LIBFT_SRC:%.c=%.o)

NAME_CLIENT = client
CLIENT_SRC = client.c
CLIENT_OBJ = $(CLIENT_SRC:%.c=%.o)

NAME_SERVER = server
SERVER_SRC = server.c
SERVER_OBJ = $(SERVER_SRC:%.c=%.o)

# Reglas
all: $(LIBFT) $(NAME_CLIENT) $(NAME_SERVER)

# Compilar cliente
$(NAME_CLIENT): $(CLIENT_OBJ)
	$(CC) $(CFLAGS) $(CLIENT_OBJ) $(LIBFT) -o $(NAME_CLIENT)

# compilar servidor
$(NAME_SERVER): $(SERVER_OBJ)
	$(CC) $(CFLAGS) $(SERVER_OBJ) $(LIBFT) -o $(NAME_SERVER)

# Compilar libft
$(LIBFT):
		@make -C $(LIBFT_DIR)

%.o: %.c
	$(CC) $(CFLAGS)	-c $< -o $@

clean:
	@rm -f $(CLIENT_OBJ) $(SERVER_OBJ)
	make clean -C $(LIBFT_DIR)

fclean: clean
	@rm -f $(NAME_CLIENT) $(NAME_SERVER)
	make fclean -C $(LIBFT_DIR)

re: fclean all

.PHONY: all clean fclean re