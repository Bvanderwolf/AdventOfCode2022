#ifndef BLIB_H
#define BLIB_H

#define TRUE 1
#define FALSE 0

#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

int		open_input(FILE **stream);
char	*strrchr_pred(char *str, int (*predicate)(int c));
char	*strchr_pred_n(char *str, int (*predicate)(int c), int n);

#endif