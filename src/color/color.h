#ifndef LEM_IN_COLOR_H
#define LEM_IN_COLOR_H

typedef enum	e_colors
{
	RED = 0,
	GREEN,
	YELLOW,
	BLUE,
	MAGENTA,
	CYAN,
	CLEAR
}				t_colors;

void			print_color(t_colors color);

#endif
