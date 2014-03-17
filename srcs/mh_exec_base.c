/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mh_exec.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evilsbol <evilsbol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/26 15:36:41 by evilsbol          #+#    #+#             */
/*   Updated: 2014/03/13 22:52:04 by evilsbol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mshell.h"

void		ft_arrayset(char **array)
{
	int		i;

	i = 0;
	while (array[i])
		ft_bzero(array[i++], 10);
}
int				ft_next_arg(char *str, int *flag)
{
	int		i;

	i = -1;
	if (*flag == ARG)
	{
		while (str[++i] && *flag == ARG)
		{
			if (str[i] == '"')
				*flag = CMD;
		}
	}
	return (i);

}

/*
** Return index of first space in string
*/
int				ft_next_cmd(char *str, int *flag)
{
	int		i;
	int		j;

	i = -1;
	j = 0;
	if (*flag == CMD)
	{
		while (j == 0 && str[++i] && *flag == CMD)
		{
			if (str[i] == ' ' && *flag == CMD)
				j = 1;
			if (str[i + 1] == '"')
				*flag = ARG;
		}
	}
	return (i);
}

void			sh_scanner(char **data, char *line)
{
	int		j;
	int		cursor;
	int		jump;
	int		*flag;
	char	*word;

	j = 0;
	cursor = 0;
	flag = ft_singleton(CMD);
	while (line[cursor])
	{
		if (*flag == CMD)
			jump = ft_next_cmd(&line[cursor], flag);
		else if (*flag == ARG)
			jump = ft_next_arg(&line[cursor], flag);
		if (jump)
		{
			word = ft_strsub(&line[cursor], 0, jump);
			data[j++] = word;
		}
		cursor += jump + 1;
	}
	data[j] = '\0';
	return ;
}

char			**sh_lexer(char **line)
{
	int			i;
	int			len;
	char		*axiom;
	char		**data;

	i = 0;
	axiom = *line;
	len = ft_count(*line, ' ');
	data = (char **) malloc(sizeof(char *) * len + 1);
	ft_arrayset(data);
	if (ft_strequ(axiom, "exit") || ft_strequ(axiom, "quit"))
		kill(0, SIGUSR1);
	else
	{
		sh_scanner(data, *line);
		while (data[i])
			ft_printf("word: %s\n", data[i++]);
	}
	return (data);
}
