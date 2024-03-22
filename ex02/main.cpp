/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlaerema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 13:36:59 by nlaerema          #+#    #+#             */
/*   Updated: 2024/03/22 13:39:38 by nlaerema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ctime>
#include "Identify.hpp"

int main()
{
	std::srand(std::time(0));

    Base *x(generate());
    Base *y(generate());
    Base *z(generate());

    identify(x);
    identify(y);
    identify(z);

	std::cout << std::endl;

    identify(*x);
    identify(*y);
    identify(*z);
    
    delete x;
    delete y;
    delete z;
}
