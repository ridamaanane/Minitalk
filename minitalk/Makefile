CC = cc
CFLAGS = -Wall -Wextra -Werror
SRC = server.c client.c

OBJ = $(SRC:%.c=%.o)
NAME = client
NAME1 = server
RM = rm -f

all: $(NAME) $(NAME1)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)
	
$(NAME1): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME1)

clean:
	@$(RM) $(OBJ)

fclean: clean
	@$(RM) $(NAME) $(NAME1)

re: fclean all

.SECONDARY: $(OBJ)
.PHONY: all clean fclean re