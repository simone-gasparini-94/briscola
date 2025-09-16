#include "player.h"
#include <stdlib.h>

t_player *player_create(void)
{
	t_player *player;

	player = malloc(sizeof(*player));
	if (player == NULL)
		return (NULL);
	player->points = 0;
	return (player);
}
