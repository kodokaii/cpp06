/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlaerema <nlaerema@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 10:58:17 by nlaerema          #+#    #+#             */
/*   Updated: 2024/03/22 12:51:01 by nlaerema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <stdint.h>

typedef struct SData
{
	int	x;
	int	y;
	int	z;
}	Data;

class Serializer
{
	private:
							Serializer(void);
							Serializer(Serializer const &other);
		Serializer			&operator=(Serializer const &other);

	public:
							~Serializer(void);
		static uintptr_t	serialize(Data *ptr);
		static Data			*deserialize(uintptr_t raw);
};
