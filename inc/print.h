#ifndef PRINT_H
# define PRINT_H

typedef struct s_deck t_deck;
typedef struct s_player t_player;

void	print_hand(t_deck *deck, t_player *player);
void	print_briscola(t_deck *deck);

#endif
