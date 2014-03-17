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

int				sh_next(char *str, int type, char **tab, int index)
{
	int		i;

	if (type == IS_ARG)
	{
		i = 1;
		ft_printf("is_arg: %c\n", str[0]);
		while (str[i] && str[i] != str[0])
			i++;
		tab[index] = ft_strtrim(ft_strsub(str, 1, i - 1));
		return (i + 1);
	}
	else if (type == IS_CMD)
	{
		ft_printf("is_cmd\n");
		i = 0;
		while (str[i] && !(ft_count(SPLIT, str[i]) || 
			ft_count(ARGS, str[i]) || ft_count(OPR, str[i])))
			i++;
		tab[index] = ft_strsub(str, 0, i);
		return (i);
	}
	else 
		return (0);
}


void			sh_scanner(char *line, char **data)
{
	int		curs;
	int		type;
	int		tmp;
	int		i;

	curs = 0;
	i = 0;
	while (line[curs])
	{
		if (ft_count(SPLIT, line[curs]))
			curs++;
		else if (ft_count(OPR, line[curs]))
		{
			tmp = (line[curs + 1] == line[curs] ? 2 : 1);
            data[i++] = ft_strsub(line, curs, tmp);
            curs += tmp;
        }
		else
		{
			type = ft_count(ARGS, line[curs]) ? IS_ARG : IS_CMD;
			if ((tmp = sh_next(&line[curs], type, data, i++)))
				curs += tmp;
			else
				curs ++;
		}
	}
}

char			**sh_lexer(char **line)
{
	int			i;
	//int			len;
	char		*axiom;
	char		**data;

	i = 0;
	axiom = *line;
	//len = ft_count(*line, ' ');
	data = (char **) malloc(sizeof(char *) * 512);
	ft_arrayset(data);
	if (ft_strequ(axiom, "exit") || ft_strequ(axiom, "quit"))
		kill(0, SIGUSR1);
	else
	{
		sh_scanner(*line, data);
		while (data[i])
			ft_printf("word: %s\n", data[i++]);
	}
	return (data);
}
