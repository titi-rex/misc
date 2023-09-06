/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   encoder.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 13:45:21 by tlegrand          #+#    #+#             */
/*   Updated: 2022/12/24 14:42:46 by tlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fraction.h"
#include <stdio.h>
#include <string.h>

static int	ft_strlen(char *str)
{
	int	n;

	n = 0;
	if (!str)
		return (0);
	while (str[n])
		n++;
	return (n);
}

static void	ft_bzero(void *s, size_t n)
{
	while (n-- > 0)
		*(unsigned char *)(s + n) = 0;
}

static void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;

	if (size > 0 && count >= SIZE_MAX / size)
		return (NULL);
	ptr = malloc(count * size);
	if (!ptr)
		return (ptr);
	ft_bzero(ptr, count * size);
	return (ptr);
}

char	*encoder(char *line)
{
	char	*dec;
	int		i;
	int		tmp;

	if (!line)
		return (NULL);
	dec = (char *)ft_calloc(2 * ft_strlen(line) + 1 ,sizeof(char));
	if (!dec)
		return (NULL);
	i = 0;
	while (*line)
	{
		tmp = *line;
		dec[i] = tmp / 10 + 48;
		dec[i + 1] = tmp % 10 + 48;
		i += 2;
		line++;
	}
	return (dec);
}

char	*decoder(char	*dec)
{
	char	*txt;
	int		i;
	int		n;
	int		tmp;

	if (!dec)
		return (NULL);
	n = ft_strlen(dec) / 2 ;
	txt = (char *)ft_calloc(n, sizeof(char));
	if (!txt)
		return (NULL);
	i = 0;
	while (i < n)
	{
		tmp = (*dec - 48) * 10 + (*(dec + 1) - 48);
		txt[i] = tmp;
		i++;
		dec += 2;
	}
	return (txt);
}
