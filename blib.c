#include "blib.h"

int	open_input(FILE **stream)
{
	*stream = fopen("input.txt", "r");
	if (stream == NULL)
	{
		perror("failed opening input file.");
		return (0);
	}
	return (1);
}