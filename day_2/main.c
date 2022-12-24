#include "../blib.h"
#include "main.h"

static t_result	get_player_result(char c)
{
	if (c == 'A')
		return (ROCK);
	if (c == 'B')
		return (PAPER);
	if (c == 'C')
		return (SCISSORS);
	return (0);
}

static t_result	get_opponent_result(char c)
{
	if (c == 'X')
		return (ROCK);
	if (c == 'Y')
		return (PAPER);
	if (c == 'Z')
		return (SCISSORS);
	return (0);
}

static void	set_match_values(char *line, t_match *match)
{
	match->opponent = get_player_result(line[0]);
	match->player = get_opponent_result(line[2]);
}

static int	get_played_score(t_match *match)
{
	if (match->player == ROCK)
		return (1);
	if (match->player == PAPER)
		return (2);
	if (match->player == SCISSORS)
		return (3);
	return (0);
}

static int	get_outcome_score(t_match *match)
{
	const int result_grid[3][3] = {
		{ 3, 6, 0 },
		{ 0, 3, 6 },
		{ 6, 0, 3 },
	};
	return (result_grid[(int)match->opponent][(int)match->player]);
}

static int	score_match(char *line, t_match *match)
{
	int	score;

	score = 0;
	set_match_values(line, match);
	score += get_played_score(match);
	score += get_outcome_score(match);
	return (score);
}

static unsigned long	get_total_score(FILE *stream, t_match *match)
{
	unsigned long	score;
	char			*line;
	size_t			len;
	ssize_t			read;

	len = 0;
	read = 1;
	score = 0UL;
	while (read != -1)
	{
		read = getline(&line, &len, stream);
		if (read != -1)
			score += score_match(line, match);
	}
	free(line);
	return (score);
}

int	main(void)
{
	unsigned long	total_score;
	FILE			*stream;
	t_match			*match;

	if (!open_input(&stream))
		return (EXIT_FAILURE);
	match = (t_match *)malloc(sizeof(t_match));
	if (match == NULL)
		return (EXIT_FAILURE);
	total_score = get_total_score(stream, match);
	free(match);
	fclose(stream);
	printf("%zu\n", total_score);
	return (EXIT_SUCCESS);
}