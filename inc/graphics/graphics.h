#ifndef GRAPHICS_H
# define GRAPHICS_H

# include <sys/types.h>
# include "raylib.h"

typedef struct s_data	t_data;
typedef struct s_card	t_card;

typedef enum e_screen
{
	LOAD_SCREEN,
	PLAY_SCREEN
}	t_screen;

typedef struct s_wndw
{
	size_t	width;
	size_t	height;
}	t_wndw;

typedef struct s_txt
{
	char	*s;
	size_t	font_size;
}	t_txt;

typedef struct s_btn
{
	t_txt	txt;
	Rectangle rectangle;
}	t_btn;


typedef struct s_grph
{
	t_wndw	window;	
	t_btn	play_btn;
	Color	white;
	Color	yellow;
	Color	orange;
	Color	red;
	Color	blue;
	Color	black;
	Font	font;
}	t_grph;

t_grph *create_graph_data(void);
void	destroy_graph_data(t_grph *graph_data);
void	init(t_data *data, t_grph *graph_data);
void	draw_load_screen(t_grph *graph_data);
bool	is_play_btn_clicked(t_btn play_btn);
void	draw_play_screen(t_data *data, t_grph *graph_data);
#endif
