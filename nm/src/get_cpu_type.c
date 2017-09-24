/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cpu_type.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cboussau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/24 18:00:19 by cboussau          #+#    #+#             */
/*   Updated: 2017/09/24 18:01:24 by cboussau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <nm.h>

char			*get_cpu_type(int cpu_type)
{
	if (cpu_type == CPU_TYPE_MC680x0)
		return ("m68k");
	else if (cpu_type == CPU_TYPE_I386)
		return ("i386");
	else if (cpu_type == CPU_TYPE_X86_64)
		return ("x86_64");
	else if (cpu_type == CPU_TYPE_ARM)
		return ("arm");
	else if (cpu_type == CPU_TYPE_ARM64)
		return ("arm64");
	else if (cpu_type == CPU_TYPE_MC88000)
		return ("m88k");
	else if (cpu_type == CPU_TYPE_I860)
		return ("i860");
	else if (cpu_type == CPU_TYPE_POWERPC)
		return ("ppc");
	else
		return (NULL);
}
