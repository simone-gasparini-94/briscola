#ifndef PRINT_H
# define PRINT_H

# include <sys/types.h>

typedef struct s_deck t_deck;
typedef struct s_player t_player;

void	print_hand(t_deck *deck, t_player *player);
void	print_card(t_deck *deck, t_player *player, size_t i);
void	print_briscola(t_deck *deck);
void	print_score(t_player *player1, t_player *player2);

#endif
