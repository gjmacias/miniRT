/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffornes- <ffornes-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 17:18:43 by ffornes-          #+#    #+#             */
/*   Updated: 2023/05/05 18:56:00 by ffornes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	is_whitespace(char const c)
{
	while (c == ' ' || c == '\t' || c == '\n'
		|| c == '\v' || c == '\f' || c == '\r')
		return (1);
	return (0);
}

static int	base(int c, int base)
{
	char	*s1;
	char	*s2;
	int		i;

	i = 0;
	s1 = "0123456789abcdef";
	s2 = "0123456789ABCDEF";
	while (i < base)
	{
		if (c == s1[i] || c == s2[i])
			return (i);
		i++;
	}
	return (-1);
}

int	ft_atoi_base(const char *str, int arg_base)
{
	int	i;
	int	is_negative;
	int	n;

	i = 0;
	is_negative = 0;
	n = 0;
	while (is_whitespace(*str))
		str++;
	while (*str == '-' || *str == '+')
	{
		if (*str == '-')
			is_negative = 1;
		if (*(str + 1) == '+' || *(str + 1) == '-')
			return (0);
		str++;
	}
	while (base(str[i], arg_base) >= 0)
	{
		n *= arg_base;
		n += base(str[i++], arg_base);
	}
	if (is_negative)
		return (-n);
	return (n);
}
