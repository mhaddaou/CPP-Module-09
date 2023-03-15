/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaddaou <mhaddaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 11:52:26 by mhaddaou          #+#    #+#             */
/*   Updated: 2023/03/15 15:57:56 by mhaddaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/RPN.hpp"

int main (int ac, char ** av){
  try{
    if (ac != 2){
        throw RNP::BadInput();
    }
    RNP rnp(av[1]);
    std::cout << "Result: " << rnp.stackTop() << std::endl;
  }
  catch (std::exception& e){
    std::cout << e.what() << std::endl;
  }
    return 0;  
}