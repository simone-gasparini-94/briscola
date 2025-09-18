#ifndef PLAYER_H
# define PLAYER_H

# include <stdbool.h>
# include "deck.h"

typedef struct s_player
{
	t_card	hand[3];
	char	*name;
	size_t	points;
	size_t	index_played;
	bool	dealer;
}	t_player;

t_player *player_create(char *name);

#endif
