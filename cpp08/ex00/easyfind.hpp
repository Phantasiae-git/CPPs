/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phantasiae <phantasiae@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 17:11:09 by phantasiae        #+#    #+#             */
/*   Updated: 2025/01/15 15:04:52 by phantasiae       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <deque>
#include <list>

class NoOcurrence:public std::exception
    {
    public:
        const char* what() const throw(){
            return("No such value found");
        }
    };

template <typename T>
typename T::iterator easyfind(T &container, int n)
{
    typename T::iterator it;

    it=std::find(container.begin(), container.end(), n);
    if(it==container.end())
        throw NoOcurrence();
    return it;
}


#endif