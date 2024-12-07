/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <luicasad@student.42barcelona.com +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 20:03:15 by luicasad          #+#    #+#             */
/*   Updated: 2024/12/02 20:05:33 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int	main(int argc, char **argv)
{
	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	else
	{
		for (int i = 1;  i < argc; i++)
		{
			std::string word = argv[i];
			for (std::size_t k = 0; k < word.size(); k++)
				std::cout << (char)std::toupper(word[k]);
		}
		std::cout << std::endl;
	}

	return (0);
}
