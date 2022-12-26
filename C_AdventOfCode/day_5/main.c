#include "../blib.h"
#include "crates.h"
#include "moves.h"
#include "stack.h"
#include "main.h"

char	*get_top_crates(t_stack **crates)
{
	char	*top_crates;
	int		i;
	int		size;

	size = 0;
	while (crates[size] != NULL)
		size++;
	top_crates = (char *)malloc(sizeof(char) * (size + 1));
	if (top_crates == NULL)
		return (NULL);
	i = 0;
	while (i < size)
	{
		top_crates[i] = crates[i]->arr[crates[i]->top];
		i++;
	}
	top_crates[i] = '\0';
	return (top_crates);
}

char	*find_top_crates(FILE *stream)
{
	char	*top_crates;
	t_stack	**crate_stacks;
	t_llist	*moves;

	crate_stacks = create_crate_stacks(stream);
	fill_crate_stacks(stream, crate_stacks);
	moves = create_moves(stream);
	apply_moves_to_stacks(moves, crate_stacks);
	top_crates = get_top_crates(crate_stacks);
	stacks_free(crate_stacks);
	llist_clear(&moves, &free);
	return (top_crates);
}

int	main(void)
{
	char	*top_crates;
	FILE	*stream;

	if (!open_input(&stream))
		return (EXIT_FAILURE);
	top_crates = find_top_crates(stream);
	fclose(stream);
	printf("%s\n", top_crates);
	free(top_crates);
	return (EXIT_SUCCESS);
}