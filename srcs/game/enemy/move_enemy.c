/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_enemy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samaouch <samaouch@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 13:17:06 by samaouch          #+#    #+#             */
/*   Updated: 2025/02/07 13:28:28 by samaouch         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>


int	move_enemy(t_data *data, t_enemy *enemy)
{
	int	rand;
	
	srand(time(NULL));
	rand = randint(1, 1000);
	if (rand % 7)
		move_enemy_top(data, enemy);
	else if (rand % 5 == 0)	
		move_enemy_down(data, enemy);
	else if (rand % 3 == 0)
		move_enemy_right(data, enemy);
	else if (rand % 2 == 0)
		move_enemy_left(data, enemy);
	
}

void	move_enemy_top(t_data *data, t_enemy *enemy)
{
	if ()
}
