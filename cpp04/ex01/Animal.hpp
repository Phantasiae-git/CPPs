/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phanta <phanta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 11:14:19 by phanta            #+#    #+#             */
/*   Updated: 2024/06/12 11:55:10 by phanta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <string>
#include <iostream>

class Animal
{
protected:
    std::string type;
public:
    Animal();
    Animal(const Animal &animal);
    Animal &operator=(const Animal &animal);
    virtual ~Animal();

    std::string getType(void) const;

    virtual void	makeSound() const;
};



#endif