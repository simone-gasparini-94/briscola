#include "player.h"
#include <stdlib.h>

t_player *player_create(char *name)
{
	t_player *player;

	player = malloc(sizeof(*player));
	if (player == NULL)
		return (NULL);
	player->name = name;
	player->points = 0;
	return (player);
}
