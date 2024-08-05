/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlaerema <nlaerema@student.42lehavre.fr>	+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 10:58:17 by nlaerema          #+#    #+#             */
/*   Updated: 2024/08/05 15:34:56 by nlaerema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter(void)
{
}

ScalarConverter::ScalarConverter(ScalarConverter const &other __attribute__((unused)))
{
}

ScalarConverter::~ScalarConverter(void)
{
}

void			ScalarConverter::convert(const std::string &str)
{
	std::stringstream	converted[SCALAR_COUNT];
	char				*end;
	double				d;
	long				l;
	
	d = strtod(str.c_str(), &end);
	l = static_cast<long>(d);
	if (end == str.c_str() || l < CHAR_MIN || CHAR_MAX < l)
		converted[CHAR] << IMPOSSIBLE;
	else if (!isprint(l))
		converted[CHAR] << NON_DISPLAYABLE;
	else
		converted[CHAR] << '\'' << static_cast<char>(l) << '\'';
	if (end == str.c_str() || l < INT_MIN || INT_MAX < l)
		converted[INT] << IMPOSSIBLE;
	else
		converted[INT] << static_cast<int>(l);
	if (end == str.c_str() || errno == ERANGE || ((d < -FLT_MAX || FLT_MAX < d) && !isinf(d)))
		converted[FLOAT] << IMPOSSIBLE;
	else if (static_cast<float>(d) == ceilf(static_cast<float>(d)) && !isinf(d))
		converted[FLOAT] << std::fixed << std::setprecision(0) << static_cast<float>(d) << ".0f";
	else
		converted[FLOAT] << static_cast<float>(d) << "f";
	if (end == str.c_str() || errno == ERANGE)
		converted[DOUBLE] << IMPOSSIBLE;
	else if (d == ceil(d) && !isinf(d))
		converted[DOUBLE] << std::fixed << std::setprecision(0) << d << ".0";
	else
		converted[DOUBLE] << d;

	std::cout << "char: " << converted[CHAR].str() << std::endl;
	std::cout << "int: " << converted[INT].str() << std::endl;
	std::cout << "float: " << converted[FLOAT].str() << std::endl;
	std::cout << "double: " << converted[DOUBLE].str() << std::endl;
}

ScalarConverter	&ScalarConverter::operator=(ScalarConverter const &other __attribute__((unused)))
{
	return (*this);
}
