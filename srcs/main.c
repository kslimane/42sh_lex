/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evilsbol <evilsbol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/25 14:22:04 by evilsbol          #+#    #+#             */
/*   Updated: 2014/02/25 14:22:06 by evilsbol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mshell.h"

static void		sig_handler(int signal)
{
	if (signal == SIGINT)
		return ;
	if (signal == SIGUSR1)
		exit (EXIT_SUCCESS);
}

static void		mshell(char **env)
{
	char	*line;
	char 	**av;
	pid_t	father;

	(void)env;
	while (get_next_line(0, &line) > 0)
	{
		father = fork();
		if (father != 0)
		{
			signal(SIGUSR1, sig_handler);
			wait(&father);
		}
		else
		{
			av = sh_lexer(&line);
		}
		free(line);
		ft_prompt(PROMPT, BLUE);
	}
}

int				main(int argc, char **argv, char **environ)
{
	char	**env;

	argc = 0;
	argv = NULL;
	env = ft_arraydup(environ);
	signal(SIGINT, sig_handler);
	ft_prompt(PROMPT, BLUE);
	mshell(env);
	return (0);
}