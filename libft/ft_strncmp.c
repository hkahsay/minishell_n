/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <mac@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 18:02:28 by vgejno            #+#    #+#             */
/*   Updated: 2023/04/12 10:42:34 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *str1, const char *str2, size_t n)
{
	if (n == 0)
		return (0);
	//printf("str1: %s, str2: %s\n", str1, str2);
	while (*str1 && *str2 && *str1 == *str2 && n--)
	{
		//printf("value n: %zu, *str1: %c, *str2: %c\n", n, *str1, *str2);
		str1++;
		str2++;
	}
	int res = ((unsigned char)*str1 - (unsigned char)*str2);
	//printf("res: %d\n", res);
	return res;
}
