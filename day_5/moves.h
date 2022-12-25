#ifndef MOVES_H
#define MOVES_H

#include "../blib.h"
#include "stack.h"
#include "main.h"

t_llist	*create_moves(FILE *stream);
void	apply_moves_to_stacks(t_llist *moves, t_stack **stacks);

#endif