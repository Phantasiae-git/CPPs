/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phanta <phanta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 18:23:19 by phanta            #+#    #+#             */
/*   Updated: 2024/06/09 19:10:26 by phanta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include <fstream>

std::string result(std::string content, std::string s1, std::string s2)
{
    int index;

    while((index=content.find(s1))!=-1)
    {
        content.erase(index, s1.length());
		content.insert(index, s2);
    }
    return(content);
}

int main(int argc, char **argv)
{
    if (argc != 4)
	{
		std::cout << "usage: file word_to_replace new_word" << std::endl;
		return (1);
	}
    std::ifstream	file(argv[1]);
    
    if (!file.is_open())
    {
        std::cerr << "can't open input file" << std::endl;
        return(1);
    }
    std::string content;

    getline(file, content, '\0');
    file.close();
    
    std::ofstream new_file((argv[1] + std::string(".replace")).c_str());
    if (!new_file.is_open())
    {
        std::cerr << "can't open output file" << std::endl;
        return(1);
    }

    new_file<<result(content, argv[2], argv[3]);
    new_file.close();

    return(0);
}