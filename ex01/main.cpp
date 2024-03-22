/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlaerema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 12:53:49 by nlaerema          #+#    #+#             */
/*   Updated: 2024/03/22 12:57:09 by nlaerema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include <iostream>

int main()
{
    Data data;

    data.x = 120;
    data.y = 121;
    data.z = 122;

    Data *ptr(&data);
    std::cout << "x: " << ptr->x << std::endl;
    std::cout << "y: " << ptr->y << std::endl;
    std::cout << "z: " << ptr->z << std::endl;

	std::cout << std::endl;
    uintptr_t raw(Serializer::serialize(ptr));
    Data *deserialized(Serializer::deserialize(raw));
    
    std::cout << "x: " << deserialized->x << std::endl;
    std::cout << "y: " << deserialized->y << std::endl;
    std::cout << "z: " << deserialized->z << std::endl;
}
