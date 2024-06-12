/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phanta <phanta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 14:50:35 by phanta            #+#    #+#             */
/*   Updated: 2024/06/09 16:43:01 by phanta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <string>
#include <iostream>
#include <iomanip>

class Zombie
{
private:
    std::string name;
public:
    Zombie();
    ~Zombie();

    std::string  getName() const;
    void setName(std::string n);
    
    void announce( void );
};

Zombie *newZombie(std::string name);
void randomChump(std::string name);

#endif


