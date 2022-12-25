#include "moves.h"
#include <ctype.h>

void	move_crates(t_stack *from, t_stack *to, int count)
{
	char	crate;

	while (count > 0)
	{
		crate = stack_pop(from);
		stack_push(to, crate);
		count--;
	}
}

void	apply_moves_to_stacks(t_llist *moves, t_stack **stacks)
{
	t_llist			*crnt_lst_item;
	t_crate_move 	*move;

	crnt_lst_item = moves;
	while (crnt_lst_item != NULL)
	{
		move = (t_crate_move *)crnt_lst_item->content;
		move_crates(stacks[move->from - 1], stacks[move->to - 1], move->count);
		crnt_lst_item = crnt_lst_item->next;
	}
}

t_crate_move	*move_create(char *line)
{
	t_crate_move	*move;

	move = (t_crate_move *)malloc(sizeof(t_crate_move));
	if (move == NULL)
		return (NULL);
	strtok(line, " ");
	move->count = atoi(strtok(NULL, " "));
	strtok(NULL, " ");
	move->from = atoi(strtok(NULL, " "));
	strtok(NULL, " ");
	move->to = atoi(strtok(NULL, " "));
	return (move);
}

t_llist	*create_moves(FILE *stream)
{
	t_llist			*moves_lst;
	t_llist			*move_lst_item;
	t_crate_move	*move;
	char			*line;
	size_t			len;
	ssize_t			read;

	len = 0UL;
	read = 0L;
	moves_lst = NULL;
	getline(&line, &len, stream);
	while (read != -1)
	{
		read = getline(&line, &len, stream);
		if (read != -1)
		{
			move = move_create(line);
			if (move == NULL)
				return (NULL);
			move_lst_item = llist_new(move);
			if (move_lst_item == NULL)
				return (NULL);
			llist_add_back(&moves_lst, move_lst_item);
		}
	}
	free(line);
	return (moves_lst);
}