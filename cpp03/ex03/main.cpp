/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phanta <phanta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 11:59:41 by phanta            #+#    #+#             */
/*   Updated: 2024/06/11 11:09:32 by phanta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include "DiamondTrap.hpp"

int main()
{
    // ClapTrap clap1;
    // ClapTrap clap2("bbbbbbbbbbbbbbbbbbbbbb");
    // ClapTrap clap3(clap2);
    // ClapTrap clap4("a");

    // clap1.attack("ye");
    // clap2.takeDamage(100000000);
    // clap2.beRepaired(10);
    // clap2.attack("a");
    // clap4.takeDamage(9);
    // clap4.attack("default");
    // clap4.beRepaired(1000);
    // clap4.takeDamage(1000);
    // clap4.beRepaired(1000);


    // ScavTrap scav("brooo");
    // ScavTrap scav2("hehe");
    // ScavTrap scaav = scav;
    // scav.attack("ooooooooo");
    // scav2.takeDamage(500);
    // scav2.beRepaired(10);
    // scav2.guardGate();

    // FragTrap frag("yippee");
    // frag.attack("target");
    // frag.takeDamage(10);
    // frag.beRepaired(10);
    // frag.highFivesGuys();

    DiamondTrap	ooo("ooo");

    ooo.attack("aaa");
	ooo.takeDamage(30);
    ooo.beRepaired(10);
	ooo.takeDamage(80);//hp reaches 0 here
    ooo.takeDamage(80);
	ooo.guardGate();
	ooo.highFivesGuys();
	ooo.whoAmI();
    return 0;
}