/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MyAwesomePhoneBook.cpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <luicasad@student.42barcelona.com +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 20:03:15 by luicasad          #+#    #+#             */
/*   Updated: 2024/12/02 20:05:33 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int main(void)
{
    bool end = false;

    while (!end)
    {
        std::string command;
        std::cout << "Enter one command (ADD, SEARCH, EXIT) ==> " << std::endl;
        std::cin >> command;
        if (command == "ADD")
            std::cout << "añadir\n";
        else if (command == "SEARCH")
            std::cout << "buscar\n";
        else if (command == "EXIT")
        {
                std::cout << "salir";
                end = true;
        }
        else
                std::cout << "No entendí";
    }
    return (0);
}