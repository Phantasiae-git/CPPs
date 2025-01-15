/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phantasiae <phantasiae@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 17:44:43 by phantasiae        #+#    #+#             */
/*   Updated: 2025/01/15 15:33:50 by phantasiae       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

int main()
{
    try{
        std::vector<int> arr(5, 1);
        std::cout <<  "first= "<<*(easyfind(arr, 1)) << std::endl;
        arr.push_back(3);
        arr.push_back(9);
        arr.push_back(5);
        std::vector<int>::iterator it=arr.begin();
        while(it<arr.end())
        {
            std::cout << *it << std::endl;
            it++;
        }
        it=easyfind(arr, 9);
        std::cout <<  "position of 9= "<<it-arr.begin() << std::endl;
        std::cout << easyfind(arr,3)-arr.begin() << std::endl;
        for(unsigned int i=0; i<arr.size();i++)
        {
            std::cout << "in position "<< easyfind(arr,arr[i])-arr.begin()<<" we have: " << *easyfind(arr,arr[i])<< std::endl;
        }
        std::cout << easyfind(arr,10)-arr.begin() << std::endl;
        
    }catch(std::exception &e){
        std::cerr<<"Exception caught: "<<e.what()<<std::endl;
    }
std::cout << "--------------------------------------------------------" << std::endl;
    try{
        std::deque<int> arr(5, 1);
        std::cout <<  "first= "<<*(easyfind(arr, 1)) << std::endl;
        arr.push_back(3);
        arr.push_back(9);
        arr.push_back(5);
        arr.push_front(0);
        std::deque<int>::iterator it=arr.begin();
        while(it<arr.end())
        {
            std::cout << *it << std::endl;
            it++;
        }
        it=easyfind(arr, 9);
        std::cout <<  "position of 9= "<<it-arr.begin() << std::endl;
        std::cout << easyfind(arr,0)-arr.begin() << std::endl;
        for(unsigned int i=0; i<arr.size();i++)
        {
            std::cout << "in position "<< easyfind(arr,arr[i])-arr.begin()<<" we have: " << *easyfind(arr,arr[i])<< std::endl;
        }
        std::cout << easyfind(arr,10)-arr.begin() << std::endl;
        
    }catch(std::exception &e){
        std::cerr<<"Exception caught: "<<e.what()<<std::endl;
    }
    std::cout << "--------------------------------------------------------" << std::endl;
    try{
        std::list<int> arr(5, 1);
        std::cout <<  "first= "<<*(easyfind(arr, 1)) << std::endl;
        arr.push_back(3);
        arr.push_back(9);
        arr.push_back(5);
        arr.push_front(0);
        std::list<int>::iterator it=arr.begin();
        while(it!=arr.end())
        {
            std::cout << *it << std::endl;
            it++;
        }
        it=easyfind(arr, 9);
        std::cout <<  "position of 9= "<<std::distance(arr.begin(), it) << std::endl;
        std::cout << std::distance(arr.begin(), easyfind(arr,0)) << std::endl;
        std::cout << std::distance(arr.begin(), easyfind(arr,10)) << std::endl;
        
    }catch(std::exception &e){
        std::cerr<<"Exception caught: "<<e.what()<<std::endl;
    }
}