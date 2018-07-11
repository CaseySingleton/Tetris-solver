/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pieces_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csinglet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/10 18:28:18 by csinglet          #+#    #+#             */
/*   Updated: 2018/05/10 18:28:19 by csinglet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "libft/libft.h"

/*
** -----------------------~*######################*~------------------------- **
** ************************* Formatting functions *************************** **
** -----------------------~*######################*~------------------------- **
**	- The purpose of these functions is to take valid input from file and	  **
**		adjust the tetromino to the most up left position possible.			  **
** ************************************************************************** **
*/

/*
** ******************** Check for empty row or column *********************** **
**	- The functions check_row_top and check_column_left are use as a		  **
**		prerequisite for shifting any input.								  **
**	- check_row_top returns 1 if no desired characters are located in the	  **
**		top most row of the **char. Else it returns 0.						  **
**	- check_column_left does the same as check_row_top but for the left		  **
**		most column of the **char. Returs behave the same.					  **
** ************************************************************************** **
*/

int			check_row_top(char *piece)
{
	int		index;

	index = -1;
	while (++index < PLEN)
		if (piece[index] != '.')
			return (0);
	return (1);
}

int			check_column_left(char *piece)
{
	int		index;

	index = 0;
	while (index < 13)
	{
		if (piece[index] != '.')
			return (0);
		index += 4;
	}
	return (1);
}

/*
** ********************** Shifting **char up and left *********************** **
**	- The functions shift_up and shift_left, given the prerequisites		  **
**		check_row_top or check_column_left return 1, push the tetromino of	  **
**		the **char to the top most left position of the **char.				  **
**	- shift_up will move the characters of **char upwards given that the	  **
**		top most row is empty.												  **
**	- shift_left will move the characters of **char letfwards given that	  **
**		the left most row is empty.											  **
** ************************************************************************** **
*/

void		shift_up(char *piece)
{
	int		index;

	while (check_row_top(piece) == 1)
	{
		index = -1;
		while (++index < PSIZE)
		{
			if (piece[index] != '.' && piece[index] != '\n')
			{
				piece[index - 4] = piece[index];
				piece[index] = '.';
			}
		}
	}
}

void		shift_left(char *piece)
{
	int		index;

	while (check_column_left(piece) == 1)
	{
		index = -1;
		while (++index < PSIZE)
		{
			if (piece[index] != '.' && piece[index] != '\n')
			{
				piece[index - 1] = piece[index];
				piece[index] = '.';
			}
		}
	}
}

/*
** *********************** Making things easy to read *********************** **
**	- The function arrange_pieces is just to make any driver functions		  **
**		much easier to read.												  **
** ************************************************************************** **
*/

void		arrange_pieces(t_etris *pieces)
{
	int			x;
	int			y;
	t_etris		*current;

	x = 0;
	y = 0;
	current = pieces;
	while (current)
	{
		shift_up(current->tetri);
		shift_left(current->tetri);
		current = current->next;
	}
}
