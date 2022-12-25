#include "crates.h"

static int	find_crate_count(char *line)
{
	char	*last_number;

	last_number = strrchr_pred(line, &isdigit);
	return (atoi(last_number));
}

static void	push_crates(t_stack **stacks, char *line, size_t len)
{
	int		stack_i;
	size_t	crate_i;

	crate_i = 1;
	stack_i = 0;
	while (crate_i < len)
	{
		if (line[crate_i] >= 'A' && line[crate_i] <= 'Z')
			stack_shove(stacks[stack_i], line[crate_i]);
		crate_i += 4;
		stack_i++;
	}
}

t_stack	**create_crate_stacks(FILE *stream)
{
	char	*line;
	int		stack_count;
	t_stack	**stacks;
	size_t	len;
	ssize_t	read;

	len = 0UL;
	read = 0L;
	while (read != -1)
	{
		read = getline(&line, &len, stream);
		if (line[1] == '1')
			break;
	}
	stack_count = find_crate_count(line);
	stacks = stack_create_n(stack_count);
	if (stacks == NULL)
		return (NULL);
	free(line);
	rewind(stream);
	return (stacks);
}

void	fill_crate_stacks(FILE *stream, t_stack **stacks)
{
	char	*line;
	size_t	len;
	ssize_t	read;

	len = 0UL;
	read = 0L;
	while (read != -1)
	{
		read = getline(&line, &len, stream);
		push_crates(stacks, line, read);
		if (line[1] == '1')
			break;
	}
	free(line);
}