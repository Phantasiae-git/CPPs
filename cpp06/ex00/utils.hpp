/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phanta <phanta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 23:30:22 by phanta            #+#    #+#             */
/*   Updated: 2024/10/30 23:35:53 by phanta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_HPP
#define UTILS_HPP

#include <string>
#include <iostream>
#include <limits>
#include <stdlib.h>
#include <iomanip>

int     typeCheck(std::string const &str, int &oor, int &nd, int &oorf);
void    printInt(std::string const &input, int oor);
void    printDouble(std::string const &input, int oor, int oorf);
void    printFloat(std::string const &input, int oor, int oorf);
void    printChar(std::string const &input, int nd);
void    printTrash();
void    printPseudo(std::string const &input);

#endif