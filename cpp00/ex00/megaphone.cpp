/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phanta <phanta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 21:27:18 by phanta            #+#    #+#             */
/*   Updated: 2024/05/10 21:44:26 by phanta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(int argc, char **argv)
{
	if(argc<2)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	else
	{
		for(int i=1; i<argc; i++)
		{
			for(int j=0; argv[i][j]!='\0'; j++)
				argv[i][j]=std::toupper(argv[i][j]);
			std::cout << argv[i];
		}
		std::cout << std::endl;
	}
	return(0);
}