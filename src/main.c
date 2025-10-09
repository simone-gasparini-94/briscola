#include <stdio.h>
#include "data.h"
#include "deck.h"
#include "play.h"
#include "player.h"
#include "print.h"
#include "raylib.h"

int	main(void)
{
	t_data *data;

	data = create_data();
	play(data->deck, data->player1, data->player2);
	print_score(data->player1, data->player2);
	destroy_data(data);
	return (0);
}
