/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burn.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocarta-l <ocarta-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/12 01:49:15 by ocarta-l          #+#    #+#             */
/*   Updated: 2016/04/19 08:22:52 by ocarta-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "burn.h"

int		burn(int i)
{
	static int color[1200] = {FIRE};

	return (color[i]);
}