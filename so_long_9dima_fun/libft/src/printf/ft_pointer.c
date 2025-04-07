/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pointer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hajj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 15:03:26 by mel-hajj          #+#    #+#             */
/*   Updated: 2024/12/19 16:57:43 by mel-hajj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_pointer(unsigned long n)
{
	if (!n)
		return (write(1, "(nil)", 5));
	return (write (1, "0x", 2) + ft_putuxx(n, 1));
}
