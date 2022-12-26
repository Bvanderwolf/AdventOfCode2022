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

// Returns the pointer from the last instance of a character
// in a string that meets the given predicate's condition.
char	*strrchr_pred(char *str, int (*predicate)(int c))
{
	int		i;
	char	*ptr;

	i = 0;
	ptr = NULL;
	while (str[i] != '\0')
	{
		if (predicate(str[i]))
			ptr = &str[i];
		i++;
	}
	return (ptr);
}

// Returns the pointer from a "n't' instance of a character 
// in a string that meets the given predicate's condition.
char	*strchr_pred_n(char *str, int (*predicate)(int c), int n)
{
	int		i;
	int		count;

	i = 0;
	count = 1;
	while (str[i] != '\0')
	{
		if (predicate(str[i]))
		{
			if (count >= n)
				return (&str[i]);
			count++;
		}
		i++;
	}
	return (NULL);
}