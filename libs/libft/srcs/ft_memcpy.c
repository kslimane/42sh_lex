/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evilsbol <evilsbol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/24 16:55:29 by evilsbol          #+#    #+#             */
/*   Updated: 2013/11/25 15:20:58 by evilsbol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

void	*ft_memcpy(void *s1, const void *s2, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		((char *) s1)[i] = ((char *) s2)[i];
		i++;
	}
	return (s1);
}
