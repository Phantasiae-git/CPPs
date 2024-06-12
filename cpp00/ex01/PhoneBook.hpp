/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phanta <phanta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 22:05:43 by phanta            #+#    #+#             */
/*   Updated: 2024/06/08 23:24:17 by phanta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"

class PhoneBook
{
private:
    Contact _contacts[8];
    int _index;
    std::string readinput(std::string msg);
public:
    PhoneBook();
    ~PhoneBook();
    void add();
    void search();
    Contact get_Contact(int index);
};




#endif