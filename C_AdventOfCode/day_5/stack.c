#include "../blib.h"
#include "stack.h"

t_stack **stack_create_n(int n)
{
	t_stack	**stacks;
	int	i;

	i = 0;
	stacks = (t_stack **)malloc(sizeof(t_stack *) * (n + 1));
	if (stacks == NULL)
		return (NULL);
	while (i < n)
	{
		stacks[i] = stack_create();
		if (stacks[i] == NULL)
		{
			while (i >= 0)
			{
				i--;
				free(stacks[i]);
			}
			free(stacks);
			return (NULL);
		}
		i++;
	}
	stacks[i] = NULL;
	return (stacks);
}

void	stacks_free(t_stack **stacks)
{
	int	i;

	i = 0;
	while (stacks[i] != NULL)
	{
		free(stacks[i]);
		i++;
	}
	free(stacks);
}

t_stack	*stack_create()
{
	t_stack *stack;

	stack = (t_stack *)malloc(sizeof(t_stack));
	if (stack == NULL)
		return (NULL);
	stack->top = -1;
	return (stack);
}

void	stack_shove(t_stack *stack, char c)
{
	int		i;

	stack->top++;
	i = stack->top;
	while (i > 0)
	{
		stack->arr[i] = stack->arr[i - 1];
		i--;
	}
	stack->arr[i] = c;
}

void	stack_push(t_stack *stack, char c)
{
	stack->top++;
	stack->arr[stack->top] = c;
}

char	stack_pop(t_stack *stack)
{
	char	c;
	if (stack->top == -1)
	{
		perror("ERROR");
		exit(1);
	}
	c = stack->arr[stack->top];
	stack->top--;
	return (c);
}

char	stack_peek(t_stack *stack)
{
	return (stack->arr[stack->top]);
}

int		stack_is_emtpy(t_stack *stack)
{
	return (stack->top == -1);
}

void	print_stacks(t_stack **stacks)
{
	for (int i = 0; stacks[i] != NULL; i++)
	{
		for (int j = 0; j <= stacks[i]->top; j++)
			printf("%c", stacks[i]->arr[j]);
		printf("\n");
	}
}