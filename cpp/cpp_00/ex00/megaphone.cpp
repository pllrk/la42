/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plerick <plerick@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 16:30:41 by plerick           #+#    #+#             */
/*   Updated: 2025/09/16 18:23:59 by plerick          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cctype> 

int	main(int argc, char **argv)
{
	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	else
		for (int i = 1; i < argc; ++i) 
		{
			std::string arg = argv[i];
			for (size_t j = 0; j < arg.length(); ++j)
				std::cout << (char)std::toupper(arg[j]); 
		}
		std::cout << std::endl;
	return (0);
}
