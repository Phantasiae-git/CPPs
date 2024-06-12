/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phanta <phanta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 11:17:28 by phanta            #+#    #+#             */
/*   Updated: 2024/06/08 22:28:01 by phanta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <string>
#include <iostream>
#include <iomanip>

class Contact
{
private:
    std::string _firstn;
    std::string _lastn;
    std::string _nickn;
    std::string _phonenr;
    std::string _secret;
    
public:
    Contact();
    ~Contact();
    std::string get_firstn();
    std::string get_lastn();
    std::string get_nickn();
    std::string get_secret();
    std::string get_phonenr();
    void    set_firstn(std::string s);
    void    set_lastn(std::string s);
    void    set_nickn(std::string s);
    void    set_secret(std::string s);
    void    set_phonenr(std::string s);
};


#endif