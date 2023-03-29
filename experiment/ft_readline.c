/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_readline.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 21:06:26 by tlegrand          #+#    #+#             */
/*   Updated: 2023/03/24 12:10:35 by tlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	*ft_realloc(void *addr, int new_count, int size)
{
	if (addr)
		free(addr);
	addr = ft_calloc(new_count, size);
	return (addr);
}

void	*ft_realloc_cpy(void *addr, int new_count, int size)
{
	void	*tmp;

	tmp = NULL;
	tmp = ft_memmove(tmp, addr, sizeof(*addr));
	addr = ft_realloc(addr, new_count, size);
	if (!addr)
		return (NULL);
	addr = ft_memmove(addr, tmp, sizeof(*tmp));
	return (addr);
}

char	*ft_readline(char *prompt)
{
	char	c_buff;
	char	*line;
	int		n_read;

	line = NULL;
	n_read = 0;
	c_buff = 'a';
	ft_putstr_fd(prompt, 1);
	while (c_buff != '\n' || c_buff != '\0')
	{
		if (read(0, &c_buff, 1) == -1)
		{
			if (line)
				free(line);
			perror("Error ");
			return (NULL);
		}
		if (n_read % 100 == 0)
			line = ft_realloc_cpy(line, (n_read + 1) % 100 * 128, sizeof(char));
		if (!line)
			return (NULL);
		line[n_read] = c_buff;
		n_read++;
	}
	return (line);
}
