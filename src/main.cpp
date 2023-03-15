/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaddaou <mhaddaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 14:33:16 by mhaddaou          #+#    #+#             */
/*   Updated: 2023/03/07 15:40:38 by mhaddaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/BitcoinExchange.hpp"

int main (int ac, char **av){
    try{
        if (ac != 2)
            throw BitcoinExchange::NotEnoughtParam();
        BitcoinExchange btc(av[1]);
    }
    catch(std::exception& e){
        std::cout << e.what() << std::endl;
    }
}
