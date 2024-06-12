/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phanta <phanta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 11:59:41 by phanta            #+#    #+#             */
/*   Updated: 2024/06/10 12:43:22 by phanta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main()
{
    ClapTrap clap1;
    ClapTrap clap2("bbbbbbbbbbbbbbbbbbbbbb");
    ClapTrap clap3(clap2);
    ClapTrap clap4("a");

    clap1.attack("ye");
    clap2.takeDamage(100000000);
    clap2.beRepaired(10);
    clap2.attack("a");
    clap4.takeDamage(9);
    clap4.attack("default");
    clap4.beRepaired(1000);
    clap4.takeDamage(1000);
    clap4.beRepaired(1000);
    return 0;
}