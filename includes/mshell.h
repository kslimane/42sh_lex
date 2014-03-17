/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mshell.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evilsbol <evilsbol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/25 14:22:43 by evilsbol          #+#    #+#             */
/*   Updated: 2014/03/13 22:52:08 by evilsbol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MSHELL_H
# define MSHELL_H

# include <signal.h>		/* kill() */
# include <sys/wait.h>		/* wait() */
# include "libft.h"
# include "libprt.h"
# include "gnl.h"

# define S_NAME	"[msh]"
# define PROMPT "[msh] > "
# define COMMANDS "cd ls cat echo"
# define OPR "<>|&;\\"
# define ARGS "\"\'"
# define SPLIT " \t"
# define IS_ARG		1
# define IS_CMD		2
# define IS_OPR		3
# define INT		1
# define PTR		2
# define CMD		1
# define ARG		2
# define RUN		1
# define STOP		2

typedef enum	e_boolean
{
	false,
	true
}				e_boolean;

/*
** mh_exec
*/
char		**sh_lexer(char **line);

#endif /* !MSHELL_H */
