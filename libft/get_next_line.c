/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: patigunt <patigunt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/04 10:46:00 by patigunt          #+#    #+#             */
/*   Updated: 2019/01/11 19:38:27 by patigunt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	t_list	*get_list(t_list **lst_saved, int fd)
{
	t_list	*tmp;
	t_list	*first;

	if (*lst_saved == NULL)
		*lst_saved = (t_list*)ft_memalloc(sizeof(t_list));
	first = *lst_saved;
	while (lst_saved)
	{
		if (((int)(*lst_saved)->content_size) == fd && (*lst_saved)->content)
		{
			tmp = *lst_saved;
			*lst_saved = first;
			return (tmp);
		}
		if ((*lst_saved)->next)
			*lst_saved = (*lst_saved)->next;
		else
			break ;
	}
	tmp = (t_list*)ft_memalloc(sizeof(t_list));
	tmp->content_size = fd;
	tmp->content = ft_memalloc(sizeof(char) * 1);
	(*lst_saved)->next = tmp;
	*lst_saved = first;
	return (tmp);
}

static char		*get_first_line(char **prev_line)
{
	char	**str;
	int		i;
	char	*line;

	i = 0;
	if (ft_strchr(*prev_line, '\n'))
	{
		str = ft_strsplit(*prev_line, '\n');
		if (str[0][0] == '\n')
			line = ft_strdup(str[1]);
		else
			line = ft_strdup(str[0]);
		while (str[i])
		{
			ft_memdel((void*)&str[i]);
			i++;
		}
		ft_memdel((void*)&str);
	}
	else
		line = ft_strdup(*prev_line);
	return (line);
}

static void		*get_line_after(char **prev_line)
{
	void	*to_free;

	to_free = *prev_line;
	if (ft_strchr(*prev_line, '\n'))
		*prev_line = ft_strdup(&ft_strchr(*prev_line, '\n')[1]);
	else if (ft_strchr(*prev_line, '\0'))
		*prev_line = ft_strdup(ft_strchr(*prev_line, '\0'));
	ft_memdel((void*)&to_free);
	return (*prev_line);
}

static int		read_fdf(char **content, t_list *lst)
{
	char	*buf;
	int		size;
	char	*to_free;

	buf = (char*)ft_memalloc(sizeof(char) * BUFF_SIZE + 1);
	while ((size = read(lst->content_size, buf, BUFF_SIZE)) > 0)
	{
		buf[size] = '\0';
		to_free = *content;
		*content = ft_strjoin(*content, buf);
		ft_memdel((void*)&to_free);
		if (ft_strchr(*content, '\n'))
			break ;
	}
	ft_memdel((void*)&buf);
	return (size);
}

int				get_next_line(const int fd, char **line)
{
	static	t_list	*lst_saved;
	t_list			*lst;
	int				value;

	if (line == NULL || fd < 0 || BUFF_SIZE < 1)
		return (-1);
	lst = get_list(&lst_saved, fd);
	if ((value = read_fdf((char**)(&lst->content), lst)) == -1
			|| (value == 0 && ft_strlen(lst->content) == 0))
	{
		*line = NULL;
		return (value);
	}
	if (((char*)lst->content)[0] == '\n')
	{
		get_line_after((char**)(&lst->content));
		*line = ft_strnew(0);
		return (1);
	}
	*line = get_first_line((char**)(&lst->content));
	get_line_after((char**)(&lst->content));
	return (1);
}
