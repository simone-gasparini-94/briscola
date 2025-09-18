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
	player->hand = malloc(sizeof(t_card) * HAND_SIZE);
	if (player->hand == NULL)
		return (NULL);
	player->hand_size = HAND_SIZE;
	return (player);
}
