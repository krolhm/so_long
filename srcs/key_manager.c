/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_manager.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbourgea <rbourgea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 13:22:04 by rbourgea          #+#    #+#             */
/*   Updated: 2021/08/30 15:23:25 by rbourgea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

t_key	*init_key(void)
{
	t_key	*key;

	key = malloc(sizeof(t_key));
	if (!key)
		return (NULL);
	key->w = 0;
	key->a = 0;
	key->s = 0;
	key->d = 0;
	return (key);
}

int	key_press(int keycode, t_vars *vars)
{
	if (keycode == KEY_ESC)
		__exit__(NULL, vars, SUCCESS);
	else if (keycode == RED_CROSS)
		__exit__(NULL, vars, SUCCESS);
	else if (keycode == KEY_W && vars->key->w == 0)
		vars->key->w = 1;
	else if (keycode == KEY_A && vars->key->a == 0)
	{
		if (BONUS)
			set_tex(TEX_PLAYER2, vars, &vars->tex[0]);
		vars->key->a = 1;
	}
	else if (keycode == KEY_S && vars->key->s == 0)
		vars->key->s = 1;
	else if (keycode == KEY_D && vars->key->d == 0)
	{
		if (BONUS)
			set_tex(TEX_PLAYER, vars, &vars->tex[0]);
		vars->key->d = 1;
	}
	return (1);
}

int	key_release(int keycode, t_vars *vars)
{
	if (keycode == KEY_ESC)
		__exit__(NULL, vars, SUCCESS);
	else if (keycode == RED_CROSS)
		__exit__(NULL, vars, SUCCESS);
	else if (keycode == KEY_W && vars->key->w == 1)
		vars->key->w = 0;
	else if (keycode == KEY_A && vars->key->a == 1)
		vars->key->a = 0;
	else if (keycode == KEY_S && vars->key->s == 1)
		vars->key->s = 0;
	else if (keycode == KEY_D && vars->key->d == 1)
		vars->key->d = 0;
	return (1);
}
