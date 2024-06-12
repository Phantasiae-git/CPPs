/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phanta <phanta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 22:06:05 by phanta            #+#    #+#             */
/*   Updated: 2024/06/09 13:58:34 by phanta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <iostream>

PhoneBook::PhoneBook()
{
    std::cout<<"Empty phonebook created"<<std::endl;
    this->_index=0;
}

PhoneBook::~PhoneBook()
{
    std::cout<<"Phonebook destroyed!"<<std::endl;
}

std::string PhoneBook::readinput(std::string msg)
{
    std::string input;
    
    if(msg== "Phone number: ")
    {
        while(input.empty() || input.find_first_not_of("0123456789")<42 || input.length()>9)
        {
            input="";
            std::cout<<msg;
            getline(std::cin, input);
            //std::cout<<input<<std::endl<<input.find_first_not_of("0123456789")<<std::endl;
        }

    }
    else
    {
        while(input.empty())
        {
            input="";
            std::cout<<msg;
            getline(std::cin, input);
        }
    }
    return input;
}

void PhoneBook::add(void)
{
    Contact new_c;
    // std::string a;
    // getline(std::cin,a); idk why i need this
    
    new_c.set_firstn(readinput("First name: "));
    new_c.set_lastn(readinput("Last name: "));
    new_c.set_nickn(readinput("Nickname: "));
    new_c.set_phonenr(readinput("Phone number: "));
    new_c.set_secret(readinput("Darkest secret: "));

    this->_contacts[_index]=new_c;
    if(_index==7)
        _index=0;
    else
        _index++;
}

void    display(Contact c)
{
	std::cout<<"First name: "<< c.get_firstn()<<std::endl;
	std::cout<<"Last name: "<<c.get_lastn()<<std::endl;
	std::cout <<"Nickname: "<<c.get_nickn()<<std::endl;
	std::cout <<"Darkest secret: "<<c.get_phonenr()<<std::endl;
	std::cout <<"Phone number: "<<c.get_secret()<<std::endl;
}

std::string    format(std::string s)
{
    if(s.length()>10)
        return(s.substr(0,9)+".");
    return(s);
}

void	PhoneBook::search(void)
{
    int i;
    std::string input;
    int count;

    i=-1;
    std::cout<<"|     Index|First Name| Last Name|  Nickname|"<< std::endl;
    count=0;
    while(++i<8)
    {
        if(this->_contacts[i].get_firstn().size())
        {
            std::cout<<"|"<<std::right<<std::setw(10)<<i+1<<"|";
            std::cout<<std::right<<std::setw(10)<<format(this->_contacts[i].get_firstn())<<"|";
            std::cout<<std::right<<std::setw(10)<<format(this->_contacts[i].get_lastn())<<"|";
            std::cout<<std::right<<std::setw(10)<<format(this->_contacts[i].get_nickn())<<"|";
            std::cout<<std::endl;
            count++;
        }
    }
    input="";
    while(i>0)
    {
        std::cout<<"Which contact would you like to know more about (index)? ";
        getline(std::cin, input);
        if(input.length()==1 && (input[0]>='1' && input[0]<=count+'0'))
            break;
        std::cout<<"Invalid index"<<std::endl;
    }
    if(this->_contacts[(input[0]-'0'-1)].get_firstn().size())
        display(this->_contacts[(input[0]-'0'-1)]);
}