/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/17 00:33:58 by fmoreira          #+#    #+#             */
/*   Updated: 2022/04/17 02:28:01 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	ft_atoi(const char *nptr)
{
	int	i;
	int	j;
	int	np;

	i = 0;
	j = 0;
	np = 1;
	while (nptr[i] == ' ' || nptr[i] == '\n' || nptr[i] == '\t'
		|| nptr[i] == '\v' || nptr[i] == '\f' || nptr[i] == '\r')
	{
		i++;
	}
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			np = -1;
		i++;
	}
	while (nptr[i] >= 48 && nptr[i] <= 57)
	{
		j = (j * 10) + (nptr[i] - 48);
		i++;
	}
	return (j * np);
}

void	ft_bzero(void *s, size_t n)
{
	while (n-- > 0)
		*(unsigned char *)s++ = '\0';
}

void	ft_putnbr_fd(int n, int fd)
{
	long int	i;

	i = n;
	if (n < 0)
	{
		write(fd, "-", sizeof(char));
		i = (long int)n * -1;
	}
	n = (i % 10) + '0';
	i = i / 10;
	if (i != (i > 0 && i < 1))
		ft_putnbr_fd(i, fd);
	write(fd, &n, sizeof(char));
}

void	ft_usage(void)
{
	write(1, "\nUSAGE: ./client <PID> <MESSAGE>\n\n", 34);
}

void	ft_usage_bonus(void)
{
	write(1, "\nUSAGE: ./client_bonus <PID> <MESSAGE>\n\n", 34);
}
