#ifndef CRATES_H
#define CRATES_H

#include "../blib.h"
#include "stack.h"
#include "main.h"
#include <ctype.h>

t_stack	**create_crate_stacks(FILE *stream);
void	fill_crate_stacks(FILE *stream, t_stack **stacks);

#endif