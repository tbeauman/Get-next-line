/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeauman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 17:52:27 by tbeauman          #+#    #+#             */
/*   Updated: 2015/11/26 14:14:06 by tbeauman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_tenpow(unsigned int nb)
{
	if (nb > 0)
		return (10 * ft_tenpow(nb - 1));
	return (1);
}

static int	ft_nb_c(int n)
{
	int		count;

	count = 1;
	if (n > 999999999)
		return (10);
	if (n < -999999999)
		return (11);
	while (n / ft_tenpow(count) != 0)
		count++;
	if (n < 0)
		count++;
	return (count);
}

char		*ft_itoa(int n)
{
	char	*ret;
	int		i;
	int		neg;

	if (n == -2147483648)
		return ("-2147483648");
	neg = n < 0 ? 1 : 0;
	ret = (char*)malloc(ft_nb_c(n) + 1);
	i = ft_nb_c(n);
	n = neg == 1 ? -n : n;
	if (!ret)
		return (NULL);
	ret[i] = '\0';
	while (i-- + 1 - neg)
	{
		ret[i] = n % 10 + '0';
		n = n / 10;
	}
	if (neg == 1)
		ret[0] = '-';
	return (ret);
}
