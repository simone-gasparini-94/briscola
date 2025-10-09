#ifndef PLAY_H
# define PLAY_H

# include <sys/types.h>

typedef struct s_player t_player;

void	play(t_deck *deck, t_player *player1, t_player *player2);
void	draw(t_player *player, t_deck *deck, size_t i);	

#endif
