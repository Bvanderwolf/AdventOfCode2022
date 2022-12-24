#include "../blib.h"

void	find_largest(const char *line, unsigned long *lrgst, unsigned long *acu)
{
	if (strcmp(line, "\n") != 0)
	{
		*acu = *acu + atol(line);
	}
	else
	{
		if (*lrgst < *acu)
			*lrgst = *acu;
		*acu = 0L;
	}
}

void	print_largest_number(FILE *stream)
{
	unsigned long	lrgst;
	unsigned long	acu;
	char			*line;
	size_t			len;
	ssize_t			read;

	len = 0;
	read = 1;
	lrgst = 0L;
	acu = 0L;
	while (read != -1)
	{
		read = getline(&line, &len, stream);
		if (read != -1)
			find_largest(line, &lrgst, &acu);
	}
	free(line);
	printf("%zu", lrgst);
}

int	main()
{
	FILE	*stream;

	if (!open_input(&stream))
		return (EXIT_FAILURE);
	print_largest_number(stream);
	fclose(stream);
	return (EXIT_SUCCESS);
}