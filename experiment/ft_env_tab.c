/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env_tab.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegrand <tlegrand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 12:58:06 by tlegrand          #+#    #+#             */
/*   Updated: 2023/03/28 16:24:19 by tlegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"
/*
int	ft_path_splitlen(char **split)
{
	int	len;
	len = 0;
	while (split[len])
		len++;
	return (len);
}*/

char	**ft_env_create(char **env_ext)
{
	char	**env;
	int		i;

	if (!env_ext)
		return (ft_env_create_std());
	env = ft_calloc(ft_path_splitlen(env_ext), sizeof(void *));
	if (!env)
		return (NULL);
	i = 0;
	while (env_ext[i])
	{
		env[i] = ft_strdup(env_ext[i]);
		if (env[i])
		{
			ft_free2d(env, 0);
			return (NULL);
		}
		i++;
	}
	return (env);
}

char	*env_search(char **env, char *name)
{
	int	i;

	i = 0;
	while (env[i] && !ft_strncmp(env[i], name, ft_strlen(name)))
		i++;
	if (env[i])
		return (env[i]);
	return (NULL);
}

int	ft_env_value_add(char **env, char *name, char *value)
{
	char	**buff;
	char	*pos;
	int		end;

	pos = env_search(env, "@deleted");
	if (pos)
		return (ft_env_value_change(env, pos, value, name));
	buff = ft_calloc(2, sizeof(void *));
	if (!buff)
		return (1);
	buff[0] = ft_strjoin3(name, "=", value);
	buff[1] = NULL;
	if (!buff[0])
	{
		ft_free2d((void **)buff, 0);
		return (1);
	}
	end = ft_path_splitlen(env);
	free(env[end]);
	env[end] = buff[0];
	return (0);
}

int	ft_env_value_del(char **env, char *name, char *value)
{
	char	*buff;
	char	*to_del;

	to_del = env_search(env, name);
	if (!to_del)
		return (0);
	free(to_del);
	to_del = ft_strdup("@deleted");
	return (0);
}

int	ft_env_value_change(char **env, char *name, char *value, char *new_name)
{
	char	*buff;
	char	*pos;

	pos = env_search(env, name);
	if (!pos)
		return (ft_env_value_add(env, name, value));
	if (!new_name)
		buff = ft_strjoin3(name, "=", value);
	else
		buff = ft_strjoin3(new_name, "=", value);
	if (!buff)
		return (1);
	free(pos);
	pos = buff;
	return (0);
}
