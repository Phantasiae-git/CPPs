/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phanta <phanta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 14:15:09 by phanta            #+#    #+#             */
/*   Updated: 2024/06/12 11:16:14 by phanta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain()
{
    std::cout<<"Brain default constructor called"<<std::endl;
}

Brain::~Brain()
{
    std::cout<<"Brain destructor called"<<std::endl;
}

Brain::Brain(const Brain &brain)
{
	*this = brain;
	std::cout<<"Brain copy constructor called"<<std::endl;
}

Brain& Brain::operator=(const Brain &brain)
{
	for (size_t i = 0; i < 100; i += 1)
		this->ideas[i] = brain.ideas[i];
	return *this;
}