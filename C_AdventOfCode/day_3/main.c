#include "../blib.h"

static int		get_item_priority(char item)
{
	if (item >= 'a' && item <= 'z')
		return (item - 'a' + 1);
	if (item >= 'A' && item <= 'Z')
		return (item - 'A' + 27);
	return (0);
}

static char	*strnchr(char *str, char c, size_t n)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0' && i < n)
	{
		if (str[i] == c)
			return (&str[i]);
		i++;
	}
	return (NULL);
}

static int	get_priority(char *line, size_t len)
{
	int	priority;
	int	compartment_size;
	int	i;
	
	compartment_size = (int)(len * 0.5f);
	i = 0;
	priority = 0;
	while (i < compartment_size)
	{
		if (strchr(line + compartment_size, line[i]) != NULL
			&& strnchr(line, line[i], i) == NULL)
			priority += get_item_priority(line[i]);
		i++;
	}
	return (priority);
}

static unsigned long	find_total_priority(FILE *stream)
{
	unsigned long	total_priority;
	char			*line;
	size_t			len;
	ssize_t			read;

	read = 1;
	len = 0UL;
	total_priority = 0UL;
	while (read != -1)
	{
		read = getline(&line, &len, stream);
		if (read != -1)
			total_priority += get_priority(line, read);
	}
	free(line);
	return (total_priority);
}

int	main(void)
{
	FILE			*stream;
	unsigned long	total_priority;

	if (!open_input(&stream))
		return (EXIT_FAILURE);
	total_priority = find_total_priority(stream);
	fclose(stream);
	printf("%zu\n", total_priority);
	return (EXIT_SUCCESS);
}