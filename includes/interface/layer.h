#ifndef LAYER_H
# define LAYER_H

# include "types.h"

typedef enum		e_filter
{
	FILTER_CIRCULAR_SHADOW,
	FILTER_CIRCULAR_BLEND,
	FILTER_LIGHT,
	FILTER_DARK,
	FILTER_BLEND,
	FILTER_NONE,
}					t_filter;

typedef struct	s_layer
{
	int			width;
	int			height;
	t_u32		*pixels;
}				t_layer;

#endif