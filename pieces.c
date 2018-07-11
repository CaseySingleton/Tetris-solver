/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pieces.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csinglet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/10 12:34:30 by csinglet          #+#    #+#             */
/*   Updated: 2018/05/10 12:34:30 by csinglet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "libft/libft.h"
#include "get_next_line.h"

/*
** ------------------------~*###################*~-----------------------------
** ************************** making the pieces *******************************
** ------------------------~*###################*~-----------------------------
*/

/*
** *************************** creating a piece ***************************** **
**	- create a new t_etris object											  **
**	- read in correct 4 lines from file										  **
**	- save those 4 lines into object->piece									  **
**	- if input is perfect there will be a newline between each piece		  **
** ************************************************************************** **
*/

int			get_piece(int fd, t_etris *lst, char letter)
{
	int		index;
	int		ret;
	char	*buff;

	buff = ft_strnew(4);
	index = -1;
	while (++index < 4)
	{
		ret = get_next_line(fd, &buff);
		if (index < 3 && ret == 0)
			return (-1);
		lst->tetri = ft_strjoin(lst->tetri, buff);
	}
	if (ret == 1 && get_next_line(fd, &buff) == 0)
		return (-1);
	index = -1;
	while (++index < 16)
	{
		if (lst->tetri[index] != '.' && lst->tetri[index] != '#')
			return (-1);
		if (lst->tetri[index] == '#')
			lst->tetri[index] = letter;
	}
	return (ret);
}

/*
** *************************** creating the list **************************** **
**	- make t_etris pointer that will be the head of the list				  **
**	- while file has content												  **
**		- create piece														  **
**		- link piece to previous piece										  **
**	- return pointer to list												  **
** ************************************************************************** **
*/

int			get_pieces(int fd, t_etris *tetris)
{
	t_etris		*cur;
	char		letter;
	int			i;

	cur = tetris;
	letter = 'A';
	i = 1;
	while (i != 0)
	{
		i = get_piece(fd, cur, letter);
		if (i == -1)
			return (0);
		letter++;
		if (i > 0)
		{
			cur->next = new_tetri();
			cur = cur->next;
		}
	}
	return (1);
}

/*
** -----------------------~*#####################*~----------------------------
** ************************* checking the pieces ******************************
** -----------------------~*#####################*~----------------------------
*/

/*
** ********************** checking the list of pieces *********************** **
**	- for each object in list												  **
**	- look in object->piece for '#' char									  **
**	- each next '#' char found must have an x or y coord in common with		  **
**		the previous '#' char												  **
**	- there must also be 4 '#' chars per object->piece						  **
**	- if the above is not true, exit program								  **
** ************************************************************************** **
*/

int			check_connections(char *piece, int index, int y)
{
	int		connections;

	connections = 0;
	if (index != 0)
		if (piece[index - 1] != '.')
			connections++;
	if (index % 4 != 0)
		if (piece[index + 1] != '.')
			connections++;
	if (y != 0)
		if (piece[index - 4] != '.')
			connections++;
	if (y != 3)
		if (piece[index + 4] != '.')
			connections++;
	return (connections);
}

int			check_piece(char *piece)
{
	int		y;
	int		index;
	int		blocks;
	int		connect;

	y = 0;
	index = -1;
	blocks = 0;
	connect = 0;
	while (piece[++index] != '\0')
	{
		if (index % 4 == 0 && index != 0)
			y++;
		if (piece[index] != '.')
			if (++blocks)
				connect += check_connections(piece, index, y);
	}
	if (index != PSIZE || blocks != MAX_BLOCKS || connect < MIN_CONNECTIONS)
		return (0);
	return (1);
}

int			check_pieces(t_etris *lst)
{
	while (lst != NULL)
	{
		if (check_piece(lst->tetri) == 0)
			return (0);
		lst = lst->next;
	}
	return (1);
}
