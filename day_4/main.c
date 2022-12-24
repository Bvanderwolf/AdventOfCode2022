#include "../blib.h"
#include "main.h"

static int	section_overlaps(t_section *s1, t_section *s2)
{
	return ((s1->start <= s2->start && s1->end >= s2->end)
		|| (s2->start <= s1->start && s2->end >= s1->end));
}

static t_section	*create_section(char *str)
{
	t_section	*section;

	section = (t_section *)malloc(sizeof(t_section));
	section->start = atoi(strtok(str, "-"));
	section->end = atoi(strtok(NULL, "-"));
	return (section);
}

static int	has_overlapping_sections(char *line)
{
	t_section 	*s1;
	t_section 	*s2;
	char		*saveptr;
	int			overlapping;

	s1 = create_section(strtok_r(line, ",", &saveptr));
	s2 = create_section(strtok_r(NULL, ",", &saveptr));
	overlapping = section_overlaps(s1, s2);
	free(s1);
	free(s2);
	return (overlapping);
}

static int	count_overlapping_pairs(FILE *stream)
{
	int		pair_count;
	char	*line;
	size_t	len;
	ssize_t	read;

	len = 0UL;
	read = 1L;
	pair_count = 0;
	while (read != -1)
	{
		read = getline(&line, &len, stream);
		if (read != -1)
			pair_count += has_overlapping_sections(line);
	}
	free(line);
	return (pair_count);
}

int	main(void)
{
	int		pair_count;
	FILE	*stream;

	if (!open_input(&stream))
		return (EXIT_FAILURE);
	pair_count = count_overlapping_pairs(stream);
	fclose(stream);
	printf("%d\n", pair_count);
	return (EXIT_SUCCESS);
}