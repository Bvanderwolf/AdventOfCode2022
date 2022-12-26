#ifndef STACK_H
#define STACK_H

#define STACK_SIZE 1000

typedef struct s_stack
{
	char	arr[STACK_SIZE];
	int		top;
}			t_stack;

t_stack **stack_create_n(int n);
t_stack	*stack_create();
void	stacks_free(t_stack **stacks);
void	stack_shove(t_stack *stack, char c);
void	stack_push(t_stack *stack, char c);
char	stack_pop(t_stack *stack);
char	stack_peek(t_stack *stack);
int		stack_is_emtpy(t_stack *stack);
void	print_stacks(t_stack **stacks);

#endif