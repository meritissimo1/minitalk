CC = gcc
CFLAGS = -Wall -Wextra -Werror

all: server client

server:
	$(CC) $(CFLAGS) server.c utils.c -o server

client: 
	$(CC) $(CFLAGS) client.c utils.c -o client

bonus:
		$(CC) $(CFLAGS) server_bonus.c utils.c -o server_bonus
		$(CC) $(CFLAGS) client_bonus.c utils.c -o client_bonus
clean:
	rm -rf server client

fclean: clean
	rm client_bonus server_bonus

re: fclean all

.PHONY: all client server fclean clean re
