/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phanta <phanta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 22:05:24 by phanta            #+#    #+#             */
/*   Updated: 2024/06/08 20:10:41 by phanta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact()
{
}

Contact::~Contact()
{
}

std::string Contact::get_firstn()
{
    return(this->_firstn);
}

std::string Contact::get_lastn()
{
    return(this->_lastn);
}

std::string Contact::get_nickn()
{
    return(this->_nickn);
}

std::string Contact::get_secret()
{
    return(this->_secret);
}

std::string Contact::get_phonenr()
{
    return(this->_phonenr);
}

void    Contact::set_firstn(std::string s)
{
    this->_firstn=s;
}

void    Contact::set_lastn(std::string s)
{
    this->_lastn=s;
}

void    Contact::set_nickn(std::string s)
{
    this->_nickn=s;
}

void    Contact::set_secret(std::string s)
{
    this->_secret=s;
}

void    Contact::set_phonenr(std::string s)
{
    this->_phonenr=s;
}