#include "get_next_line.h"

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 1
#endif

int	get_next_line(int fd, char **line)
{
	int			i;
	int			status;
	static char	*buf;

	if ((fd < 0) || (BUFFER_SIZE == 0) || !line)
		return (-1);
	status = 1;
	while (((i = ft_endl(&buf, BUFFER_SIZE)) >= 0) &&
	(status = read(fd, &(buf[i]), BUFFER_SIZE)) > 0)
		buf[status + i] = '\0';
	if ((i = trouble_shooting(status, i, &buf, line)) != 1)
		return (i);
	i = 0;
	while ((buf[i] != '\n') && buf[i])
	{
		(*line)[i] = buf[i];
		i++;
	}
	(*line)[i] = '\0';
	if (ft_clear(&buf, i) < 0)
		return (-1);
	if (!buf && !status)
		return (0);
	return (1);
}

int	trouble_shooting(int status, int i, char **buf, char **line)
{
	if (status < 0)
	{
		free(*buf);
		return (status);
	}
	if (!i && (status == 0))
	{
		*line = (char *)malloc(1);
		**line = '\0';
		free(*buf);
		*buf = NULL;
		return (status);
	}
	i = ft_linelen(*buf) + 1;
	if ((!(*line = (char *)malloc(sizeof(char) * i))))
	{
		free(*buf);
		return (-1);
	}
	return (1);
}
