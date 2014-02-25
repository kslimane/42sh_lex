/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strclr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evilsbol <evilsbol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/25 15:29:34 by evilsbol          #+#    #+#             */
/*   Updated: 2013/12/01 19:35:11 by evilsbol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

void	ft_strclr(char *s)
{
	size_t		i;

	i = 0;
	if (s)
	{
		while (s[i])
		{
			s[i] = '\0';
			i++;
		}
	}
	return ;
}
