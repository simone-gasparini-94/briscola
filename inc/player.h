#ifndef PLAYER_H
# define PLAYER_H

# include <stdbool.h>
# include "deck.h"

typedef struct s_player
{
	t_card	hand[3];
	t_card	played;
	char	*name;
	size_t	points;
	size_t	index;
	bool	dealer;
	bool	first;
}	t_player;

t_player *player_create(char *name);

#endif
