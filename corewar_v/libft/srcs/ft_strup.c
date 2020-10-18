/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strup.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: torange <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 18:30:11 by torange           #+#    #+#             */
/*   Updated: 2020/02/11 18:30:15 by torange          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_strup(char *tmp)
{
	tmp--;
	while (*++tmp)
		*tmp = ft_toupper(*tmp);
}
