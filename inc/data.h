#ifndef DATA_H
# define DATA_H

typedef struct s_player t_player;
typedef struct s_deck t_deck;

typedef struct s_data
{
	t_deck *deck;
	t_player *player1;
	t_player *player2;
}	t_data;

t_data	*create_data(void);
void	destroy_data(t_data *data);

#endif
