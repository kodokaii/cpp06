/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Identify.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlaerema <nlaerema@student.42lehavre.fr>	+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 10:58:17 by nlaerema          #+#    #+#             */
/*   Updated: 2024/03/22 13:35:20 by nlaerema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Identify.hpp"

Base::~Base()
{
}

Base *generate(void)
{
    int rand(std::rand() % 3);

    if (rand == 0)
        return new A;
    else if (rand == 1)
        return new B;
    else
        return new C;
}

void identify(Base *p)
{
    if (dynamic_cast<A*>(p))
        std::cout << "A" << std::endl;
    else if (dynamic_cast<B*>(p))
        std::cout << "B" << std::endl;
    else if (dynamic_cast<C*>(p))
        std::cout << "C" << std::endl;
	else
		std::cout << "Error" << std::endl;
}

void identify(Base &p)
{
    try
	{
        (void)dynamic_cast<A&>(p);
        std::cout << "A" << std::endl;
    }
	catch (std::exception &a)
	{
        try
		{
            (void)dynamic_cast<B&>(p);
            std::cout << "B" << std::endl;
        }
		catch (std::exception &b)
		{
            try
			{
                (void)dynamic_cast<C&>(p);
                std::cout << "C" << std::endl;
            }
			catch (std::exception &c)
			{
				std::cout << "Error" << std::endl;
			}
        }
    }
}
