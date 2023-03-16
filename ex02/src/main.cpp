/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaddaou <mhaddaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 01:39:46 by mhaddaou          #+#    #+#             */
/*   Updated: 2023/03/16 02:24:39 by mhaddaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/PmergeMe.hpp"

int main (int ac, char **av){
    try{
        if (ac < 2)
            throw PmergeMe::BadInput();
        PmergeMe(av, ac);     
    }
    catch (std::exception & e){
        std::cout << e.what() << std::endl;
    }
    return (0);
}