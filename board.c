/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   board.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csinglet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/10 12:33:18 by csinglet          #+#    #+#             */
/*   Updated: 2018/05/10 12:33:22 by csinglet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "libft/libft.h"

/*
** ------------------------~*##################*~------------------------------
***************************** making the board ********************************
** ------------------------~*##################*~------------------------------
*/

char		*make_board(t_etris *lst)
{
	char	*board;
	int		index;
	int		len;
	int		total_blocks;

	len = 2;
	total_blocks = tetri_count(lst) * 4;
	while (ft_pow(len, 2) < total_blocks)
		len++;
	if (!(board = (char *)malloc((len * len) + len + 1)))
		return (NULL);
	board[(len * len) + len] = '\0';
	ft_memset(board, 46, (len * len) + (len - 1));
	index = len;
	while (index < (len * len) + 1)
	{
		board[index] = '\n';
		index += len + 1;
	}
	return (board);
}

char		*increase_board(char *board)
{
	char	*new_board;
	int		len;
	int		new_size;
	int		index;

	len = 0;
	while (board[len] != '\n')
		len++;
	len += 1;
	new_size = (len * len) + len;
	new_board = (char *)malloc(new_size);
	new_board[new_size - 1] = '\0';
	ft_memset(new_board, 46, new_size - 1);
	index = len;
	while (index < (len * len) + 1)
	{
		new_board[index] = '\n';
		index += len + 1;
	}
	return (new_board);
}

t_etris		*new_tetri(void)
{
	t_etris			*new;

	new = (t_etris *)malloc(sizeof(t_etris));
	if (!(new->tetri = (char *)malloc(17)))
		return (NULL);
	new->tetri[16] = '\0';
	new->next = NULL;
	return (new);
}

int			tetri_count(t_etris *lst)
{
	t_etris		*cur;
	int			count;

	cur = lst;
	count = 0;
	while (cur)
	{
		count++;
		cur = cur->next;
	}
	return (count);
}
