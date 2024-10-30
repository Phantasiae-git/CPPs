/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phanta <phanta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 17:33:24 by phanta            #+#    #+#             */
/*   Updated: 2024/10/30 22:58:22 by phanta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <string>
#include <iostream>

class ScalarConverter
{
private:

public:
	ScalarConverter();
	ScalarConverter(const std::string &name);
	ScalarConverter(const ScalarConverter &other);
	virtual ~ScalarConverter() = 0;

	ScalarConverter &operator=(const ScalarConverter &other);
	static void convert(std::string const &input);
};

#endif // ScalarConverter_HPP