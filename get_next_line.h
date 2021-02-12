#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

int get_next_line(int fd, char **line);

int ft_endl(char **temp, int size);

int ft_strlen(char *s);

int ft_linelen(char *s);

int ft_clear(char **buf, int a);

int	trouble_shooting(int status, int i, char **buf, char **line);

#endif
