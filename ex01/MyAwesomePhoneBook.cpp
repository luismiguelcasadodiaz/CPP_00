/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MyAwesomePhoneBook.cpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <luicasad@student.42barcelona.com +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 20:03:15 by luicasad          #+#    #+#             */
/*   Updated: 2024/12/18 17:19:19 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "PhoneBook.class.hpp"
#include "Contact.class.hpp"

int main(void)
{
    Contact		amigo;
	PhoneBook	agenda;
	bool 		end = false;

    while (!end)
    {
        std::string command;
        std::cout << "Enter one command (ADD, SEARCH, EXIT) ==> " << std::endl;
        std::getline(std::cin, command, std::cin.widen('\n'));
        if (command == "ADD")
		{
            amigo.set_first_name(amigo.read_non_empty_string("First name >"));
            amigo.set_last_name(amigo.read_non_empty_string("Last name >"));
            amigo.set_nickname(amigo.read_non_empty_string("Nick name >"));
            amigo.set_phone_number(amigo.read_non_empty_string("Phone Number >"));
            amigo.set_darkest_secret(amigo.read_non_empty_string("Darkest Secret >"));
			agenda.add(amigo);
		}
		else if (command == "SEARCH")
            agenda.search();
        else if (command == "EXIT")
        {
                std::cout << "salir\n";
                end = true;
        }
        else
                std::cout << "No entendí \n";
    }
    return (0);
}
