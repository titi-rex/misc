/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 14:05:47 by tlegrand          #+#    #+#             */
/*   Updated: 2022/12/24 14:39:21 by tlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fraction.h"
#include <stdio.h>
#include <string.h>

int	main(void)
{
	char	*txt;
	char	*dec;
	char	*udec;

	txt = "SALUT";
	dec = encoder(txt);
	udec = decoder(dec);
	printf("txt : %s\ndec : %s\nudec : %s\n", txt, dec, udec);
	free(dec);
	free(udec);
}