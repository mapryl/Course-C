#include "rush00.h"
#include "rush01.h"
#include "rush02.h"
#include "rush03.h"
#include "rush04.h"
#include "utils.h"
#include "stream.h"

int get_dimensions(t_stream *stream, int *x, int *y)
{
	int last_dimension;
	char* pos;

	pos = stream->str;
	*x = 0;
	*y = 0;
	last_dimension = 0;
	while (*pos != '\0')
	{
		if (*pos == '\n')
		{
			if (last_dimension && last_dimension != *x)
				return (-1);
			last_dimension = *x;
			*x = 0;
			*y += 1;
			pos++;
			continue;
		}
		*x += 1;
		pos++;
	}
	*x = last_dimension;
	return 0;
}

# define RUSH_COUNT 5

int compare_rush(int rush_number, int x, int y, t_stream *input)
{
	int cmp_result;
	t_stream rush_output;
	void(*rushes[RUSH_COUNT])(int, int);

	rushes[0] = &rush00;
	rushes[1] = &rush01;
	rushes[2] = &rush02;
	rushes[3] = &rush03;
	rushes[4] = &rush04;

	stream_init(&rush_output);

	g_output_stream = &rush_output;
	rushes[rush_number](x, y);
	g_output_stream = 0;

	cmp_result = stream_compare(input, &rush_output);
	stream_free(&rush_output);

	return cmp_result;
}

void print_rush_info(int rush_number, int x, int y)
{
	ft_putstr("[rush-0");
	ft_putnbr(rush_number);
	ft_putstr("] [");
	ft_putnbr(x);
	ft_putstr("] [");
	ft_putnbr(y);
	ft_putstr("]");
}

void compare_rushes(int x, int y, t_stream *input)
{
	int i;
	int found;

	found = 0;
	i = 0;
	while (i < RUSH_COUNT)
	{
		if ( compare_rush(i, x, y, input) == 0 )
		{
			if (found)
				ft_putstr(" || ");
			print_rush_info(i, x, y);
			found = 1;
		}
		i++;
	}

	if (!found)
		ft_putstr("aucune");

	ft_putchar('\n');
}

int main(void)
{
	int xdim;
	int ydim;
	int result;
	char c;
	t_stream input_stream;

	stream_init(&input_stream);

	while (std::cin.get(c)) // while(read(1, &c, 1);
	{
		stream_put(&input_stream, c);
	}

	result = get_dimensions(&input_stream, &xdim, &ydim);

	if (result == -1 || input_stream.str[0] == '\0')
	{
		ft_putstr("aucune\n");
		return 0;
	}

	compare_rushes(xdim, ydim, &input_stream);
}