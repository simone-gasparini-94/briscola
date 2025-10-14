#include <stdlib.h>
#include "data.h"
#include "deck.h"
#include "player.h"

t_data *create_data(void)
{
	t_data *data;

	data = malloc(sizeof(t_data));
	if (data == NULL)
		return (NULL);
	data->player1 = player_create("PLAYER1");
	data->player2 = player_create("PLAYER2");
	data->deck = deck_create(data->player1, data->player2);
	return (data);
}

void	destroy_data(t_data *data)
{
	if (data->deck != NULL)
		free(data->deck);
	if (data->player1 != NULL)
		free(data->player1);
	if (data->player2 != NULL)
		free(data->player2);
	if (data != NULL)
		free(data);
}
