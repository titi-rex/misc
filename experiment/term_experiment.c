/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   term_experiment.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 19:29:46 by tlegrand          #+#    #+#             */
/*   Updated: 2023/03/28 20:02:07 by tlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"
#include <termcap.h>

int	term_putchar(int n)
{
	char	c;

	c = n;
	return (write(1, &c, 1));
}

void	term_init_termcap(char *data)
{
	char	*term;
	int		tget_status;

	term = getenv("TERM");
	if (!term)
		return ((void) ft_putendl_fd("Error : TERM not set", 2));
	tget_status = tgetent(data, term);
	if (tget_status == -1)
		return ((void) ft_putendl_fd("Error : couldn't acces termcap database", \
			2));
	if (tget_status == 0)
		return ((void) ft_putendl_fd("Error : termcap database has too few info \
			or term is not in", 2));
}

void	term_clear(void)
{
	char	*str;

	str = tgetstr("cl", NULL);
	tputs(str, 1, term_putchar);
}
