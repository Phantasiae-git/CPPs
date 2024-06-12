/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phanta <phanta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 19:16:59 by phanta            #+#    #+#             */
/*   Updated: 2024/06/09 22:12:52 by phanta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
#define HARL_HPP

#include <string>
#include <iostream>

class Harl
{
private:
    void debug( void );
    void info( void );
    void warning( void );
    void error( void );
public:
    Harl();
    ~Harl();
    void complain( std::string level );
};

typedef void (Harl::*func_pointer) ( void );

#endif