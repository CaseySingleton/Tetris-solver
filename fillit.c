/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csinglet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/29 13:04:54 by csinglet          #+#    #+#             */
/*   Updated: 2018/04/29 13:04:56 by csinglet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "fillit.h"

#include <stdio.h>

/*
** ----------------------------~*###########*~---------------------------------
** ****************************** algorithm ***********************************
** ----------------------------~*###########*~---------------------------------
*/

int			try_piece(char *piece, char *board, int op)
{
	int		index;
	int		blen;
	int		len;
	int		y;

	index = 0;
	blen = ft_strlen(board);
	len = 0;
	y = 0;
	while (board[len] != '\n')
		len++;
	while (index < PSIZE)
	{
		if (index % 4 == 0 && index != 0)
			y++;
		if (piece[index] != '.')
			if (board[(index % 4) + op + ((len + 1) * y)] != '.'
			|| (index % 4) + op + ((len + 1) * y) > blen)
				return (0);
		index++;
	}
	return (1);
}

char		*place_piece(char *piece, char *board, int op)
{
	int		index;
	int		count;
	int		len;
	int		y;

	index = 0;
	count = 0;
	len = 0;
	y = 0;
	while (board[len] != '\n')
		len++;
	while (count < PLEN && index < PSIZE)
	{
		if (index % 4 == 0 && index != 0)
			y++;
		if (piece[index] != '.')
		{
			board[(index % 4) + op + ((len + 1) * y)] = piece[index];
			count++;
		}
		index++;
	}
	return (board);
}

int			check_finished(t_etris *pieces, char *board)
{
	if (pieces == NULL)
	{
		ft_putstr(board);
		return (1);
	}
	return (0);
}

int			feelin_it(t_etris *pieces, char *board)
{
	int			op;
	char		*bcpy;

	bcpy = ft_strdup(board);
	if (check_finished(pieces, board) == 1)
		return (1);
	while (pieces != NULL)
	{
		op = 0;
		while (op < (int)ft_strlen(board))
		{
			if (try_piece(pieces->tetri, board, op) == 1)
			{
				place_piece(pieces->tetri, bcpy, op);
				if (feelin_it(pieces->next, bcpy) == 1)
					return (1);
				bcpy = ft_strdup(board);
			}
			if (++op == (int)ft_strlen(board))
				return (0);
		}
		pieces = pieces->next;
	}
	return (0);
}

/*
** --------------------------~*#################*~-----------------------------
** **************************** driver function *******************************
** --------------------------~*#################*~-----------------------------
*/

void		fillit(int fd)
{
	char		*board;
	t_etris		*pieces;

	pieces = new_tetri();
	if (get_pieces(fd, pieces) == 0)
	{
		write(1, "error\n", 6);
		return ;
	}
	if (check_pieces(pieces) == 0)
	{
		write(1, "error\n", 6);
		return ;
	}
	board = make_board(pieces);
	arrange_pieces(pieces);
	while (feelin_it(pieces, board) == 0)
		board = increase_board(board);
}
