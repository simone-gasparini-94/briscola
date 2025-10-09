#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include "player.h"
#include "deck.h"

#ifndef BUF_LEN
# define BUF_LEN 8
#endif

static char	*get_next_line(void);
static char *append_to_str(char *first, char *second);
static char	*get_line(char *str);
static char	*update_buffer(char *buffer);

size_t	get_input(t_player *player, t_deck *deck)
{
	char 	*line;
	size_t	i;

	while (1)
	{
		printf("PLAY A CARD:	");
		fflush(stdout);
		line = get_next_line();
		printf("\n");
		if (strncmp(line, "EXIT", strlen("EXIT")) == 0)
		{
			free(line);
			free(deck->player1->hand);
			free(deck->player2->hand);
			exit(EXIT_SUCCESS);
		}
		i = atoi(line) - 1;
		free(line);
		if (i <= player->hand_size - 1)
			break ;
		printf("SELECT A NUMBER BETWEEN 1 AND %zu\n\n",
				player->hand_size);
	}
	return (i);
}

static char	*get_next_line(void)
{
	static char	*buf;
	char		*tmp;
	char		*new_line;
	char		b[BUF_LEN + 1];
	int			num_read;

	if (buf == NULL)
	{
		buf = calloc(1, 1);
		if (buf == NULL)
			return (NULL);
	}
	while ((tmp = strchr(buf, '\n')) == NULL)
	{
		num_read = read(STDIN_FILENO, b, BUF_LEN);
		if (num_read == -1)
		{
			perror("read");
			if (buf != NULL)
				free(buf);
			return (NULL);
		}
		if (num_read == 0)
			break ;
		b[num_read] = '\0';
		buf = append_to_str(buf, b);
	}
	new_line = get_line(buf);
	buf = update_buffer(buf);
	return (new_line);
}

static char *append_to_str(char *first, char *second)
{
	char	*new;
	size_t	len_new;
	size_t	len_first;
	size_t	len_second;

	len_first = strlen(first);
	len_second = strlen(second);
	len_new = len_first + len_second;
	new = malloc(len_new + 1);
	if (new == NULL)
		return (NULL);
	strcpy(new, first);
	free(first);
	strcat(new, second);
	return (new);
}

static char	*get_line(char *str)
{
	char	*line;
	size_t	len;
	
	if (str[0] == '\0')
		return (NULL);
	len = 0;
	while (str[len] != '\n' && str[len] != '\0')
		len++;
	if (str[len] == '\n')
		len++;
	line = malloc(len + 1);
	if (line == NULL)
		return (NULL);
	memcpy(line, str, len);
	line[len] = '\0';
	return (line);
}

static char	*update_buffer(char *buffer)
{
	char	*new;
	size_t	len;

	if (buffer == NULL)
		return (NULL);
	len = 0;
	while (buffer[len] != '\0' && buffer[len] != '\n')
		len++;
	if (buffer[len] == '\0')
	{
		free(buffer);
		return (NULL);
	}
	new = strdup(buffer + len + 1);
	free(buffer);
	return (new);
}
