/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlaerema <nlaerema@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 10:58:17 by nlaerema          #+#    #+#             */
/*   Updated: 2024/03/22 01:41:50 by nlaerema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <cmath>
#include <string>
#include <cerrno>
#include <cstring>
#include <cstdlib>
#include <sstream>
#include <climits>
#include <float.h>
#include <iomanip>
#include <iostream>

#define SCALAR_COUNT	4
#define IMPOSSIBLE		"impossible"	
#define NON_DISPLAYABLE	"Non displayable"

enum EScalar
{
	CHAR,
	INT,
	FLOAT,
	DOUBLE
};

class ScalarConverter
{
	private:
						ScalarConverter(void);
						ScalarConverter(const ScalarConverter &other);
		ScalarConverter &operator=(const ScalarConverter &ref);

	public:
						~ScalarConverter(void);
		static void convert(const std::string &str);
};
