/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amorvai <amorvai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 18:55:20 by amorvai           #+#    #+#             */
/*   Updated: 2023/02/20 17:33:59 by amorvai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	get_sign(const char *str, int *sign, int *i)
{
	if (str[*i] == '+' || str[*i] == '-')
	{
		if (str[*i] == '-')
			*sign *= -1;
		(*i)++;
	}
}

int	ft_atoi(const char *str, int *result)
{
	long	n;
	int		i;
	int		sign;

	i = 0;
	n = 0;
	sign = 1;
	get_sign(str, &sign, &i);
	if (str[i] == '\0')
		return (1);
	while ('0' <= str[i] && str[i] <= '9')
	{
		n = (n * 10) + str[i] - '0';
		if (sign == 1 && n > 2147483647)
			return (1);
		else if (sign == -1 && n > 2147483648)
			return (1);
		i++;
	}
	if (str[i] != '\0')
		return (1);
	*result = (int)(n * sign);
	return (0);
}

// possibly insert after line 33
//
// while (str[i] == ' ' || str[i] == '\t')
// 	i++;
// if (str[i] == '\0')
// 	return (0);
