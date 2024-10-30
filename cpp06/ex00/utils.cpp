/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phanta <phanta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 22:42:52 by phanta            #+#    #+#             */
/*   Updated: 2024/10/30 23:38:03 by phanta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <cctype>
#include <string>

std::string types[] = {"char: ", "int: ", "float: ", "double: "};

void printChar()
{
	
};

int typeCheck(std::string const &str, int &oor, int &nd)
{

	if(str.length() == 1 && std::isprint(static_cast<unsigned char>(str[0])))//char
		return 1;
	if(str.length() == 1 && !std::isprint(static_cast<unsigned char>(str[0])))
	{
		nd=1;
		return 1;
	}

	try//int
	{
        std::stoi(str);
		return 2;
    }
	catch (const std::invalid_argument& e)
	{
        return 5;
    }
	catch (const std::out_of_range& e) {
		oor=1;
        return 5;
    }

	try//float
	{
        std::stof(str);
		return 3;
    }
	catch (const std::invalid_argument& e)
	{
        return 5;
    }
	catch (const std::out_of_range& e) {
		oor=1;
        return 5;
    }
	
	try//double
	{
        std::stod(str);
		return 4;
    }
	catch (const std::invalid_argument& e)
	{
        return 5;
    }
	catch (const std::out_of_range& e) {
		oor=1;
        return 5;
    }

	return 5;
}