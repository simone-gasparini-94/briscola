#ifndef GET_INPUT_H
# define GET_INPUT_H

# include <sys/types.h>

typedef struct s_player t_player;
typedef struct s_deck t_deck;

size_t	get_input(t_player *player, t_deck *deck);

#endif
