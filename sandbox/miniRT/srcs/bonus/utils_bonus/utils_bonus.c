/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bentowsk <bentowsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/08 02:05:25 by bentowsk          #+#    #+#             */
/*   Updated: 2021/05/08 02:11:11 by bentowski        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt_bonus.h"

t_triade	*subs_ptr(t_triade *t1, t_triade t2)
{
	t_triade	*t3;

	t3 = NULL;
	printf("%s\n", "OK");
	t3->x = t1->x - t2.x;
	t3->y = t1->y - t2.y;
	t3->z = t1->z - t2.z;
	return (t3);
}
