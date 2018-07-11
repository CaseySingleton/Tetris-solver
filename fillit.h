/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csinglet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/08 15:38:36 by csinglet          #+#    #+#             */
/*   Updated: 2018/05/08 15:43:14 by csinglet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <stdlib.h>
# include "libft/libft.h"
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

# define PLEN 4
# define PSIZE 16
# define MAX_BLOCKS 4
# define MIN_CONNECTIONS 5

# include <stdio.h>

typedef struct		s_irtet
{
	char			*tetri;
	struct s_irtet	*next;
}					t_etris;

/*
** -------------------------~*#################*~------------------------------
** *************************** board functions ********************************
** -------------------------~*#################*~------------------------------
*/

char				*make_board(t_etris *lst);
char				*increase_board(char *board);
char				*copy_board(char *board);
t_etris				*new_tetri(void);
int					tetri_count(t_etris *lst);

/*
** -------------------------~*#################*~------------------------------
** *************************** piece functions ********************************
** -------------------------~*#################*~------------------------------
*/

int					get_piece(int fd, t_etris *lst, char letter);
int					get_pieces(int fd, t_etris *lst);
int					check_connections(char *piece, int index, int y);
int					check_size_and_blocks(char *piece);
int					check_pieces(t_etris *lst);

/*
** -----------------------~*######################*~---------------------------
** ************************* formatting functions *****************************
** -----------------------~*######################*~---------------------------
*/

int					check_row_top(char *piece);
int					check_column_left(char *piece);
void				shift_up(char *piece);
void				shift_left(char *piece);
void				arrange_pieces(t_etris *pieces);

/*
** ------------------------~*##################*~------------------------------
** ************************** fillit functions ********************************
** ------------------------~*##################*~------------------------------
*/

void				arrange_pieces(t_etris *pieces);
void				fillit(int fd);

#endif
