/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dtoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flfische <flfische@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 11:39:01 by flfische          #+#    #+#             */
/*   Updated: 2024/04/23 11:54:25 by flfische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_fractol.h"

char	*ft_dtoa_prec(double n, int precision)
{
	char	*str;
	char	*tmp;
	char	*tmp2;
	int		i;

	i = 0;
	str = ft_strdup("");
	if (!str)
		ft_print_errors(err_malloc_failed, 1);
	while (i < precision)
	{
		n = (n - (int)n) * 10;
		tmp = ft_itoa((int)n);
		if (!tmp)
			ft_print_errors(err_malloc_failed, 1);
		tmp2 = ft_strjoin(str, tmp);
		if (!tmp2)
			ft_print_errors(err_malloc_failed, 1);
		free(str);
		free(tmp);
		str = tmp2;
		i++;
	}
	return (str);
}

char	*ft_dtoa(double n, int precision)
{
	char	*str;
	char	*tmp;
	char	*tmp2;

	str = ft_itoa((int)n);
	if (!str)
		ft_print_errors(err_malloc_failed, 1);
	tmp = ft_strjoin(str, ".");
	if (!tmp)
		ft_print_errors(err_malloc_failed, 1);
	free(str);
	str = tmp;
	tmp = ft_dtoa_prec(n, precision);
	if (!tmp)
		ft_print_errors(err_malloc_failed, 1);
	tmp2 = ft_strjoin(str, tmp);
	if (!tmp2)
		ft_print_errors(err_malloc_failed, 1);
	free(str);
	free(tmp);
	str = tmp2;
	return (str);
}
