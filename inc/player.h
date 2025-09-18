#ifndef PLAYER_H
# define PLAYER_H

# include <stdbool.h>
# include "deck.h"

# define HAND_SIZE 3

typedef struct s_player
{
	t_card	*hand;
	t_card	played;
	char	*name;
	size_t	points;
	size_t	index;
	size_t	hand_size;
	bool	dealer;
	bool	first;
}	t_player;

t_player *player_create(char *name);

#endif
