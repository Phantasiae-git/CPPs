/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phantasiae <phantasiae@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 09:47:28 by phantasiae        #+#    #+#             */
/*   Updated: 2024/11/28 09:52:05 by phantasiae       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE_HPP
#define BASE_HPP

#include <string>
#include <iostream>
class Base
{
private:
public:
    virtual ~Base();

    Base * generate(void);
    void identify(Base* p);
    void identify(Base& p);
    
};

#endif // Base_HPP