#ifndef MAIN_H
#define MAIN_H

typedef enum e_result
{
	ROCK = 0,
	PAPER = 1,
	SCISSORS = 2
}	t_result;

typedef struct s_match
{
	t_result	opponent;
	t_result	player;
}				t_match;

#endif