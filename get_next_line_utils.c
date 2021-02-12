#include "get_next_line.h"

int	ft_endl(char **buf, int size)
{
	int		out;
	char	*temp;

	if (!(*buf))
	{
		if (!(*buf = (char *)malloc(sizeof(char) * (size + 1))))
			return (-1);
		return (0);
	}
	out = 0;
	while ((*buf)[out])
		if ((*buf)[out++] == '\n')
			return (-2);
	if (!(temp = (char *)malloc(sizeof(char) * (size + ft_strlen(*buf) + 1))))
		return (-1);
	out = 0;
	while ((*buf)[out])
	{
		temp[out] = (*buf)[out];
		out++;
	}
	temp[out] = '\0';
	free(*buf);
	*buf = temp;
	return (out);
}

int	ft_strlen(char *s)
{
	size_t i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	ft_linelen(char *s)
{
	size_t i;

	if (!s)
		return (-1);
	i = 0;
	while ((s[i] != '\n') && s[i])
		i++;
	return (i);
}

int	ft_clear(char **buf, int a)
{
	int		i;
	char	*temp;

	if (!(*buf)[a++])
	{
		free(*buf);
		*buf = NULL;
		return (1);
	}
	if (!(temp = (char *)malloc(sizeof(char) * (ft_strlen(&(*buf)[a]) + 1))))
	{
		free(*buf);
		return (-1);
	}
	i = 0;
	while ((*buf)[a])
	{
		temp[i] = (*buf)[a];
		i++;
		a++;
	}
	temp[i] = '\0';
	free(*buf);
	*buf = temp;
	return (1);
}
