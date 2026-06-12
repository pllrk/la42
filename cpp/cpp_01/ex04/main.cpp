
#include <iostream>
#include <string>
#include <fstream>

std::string ft_replace(std::string input, std::string replaced, std::string will_replace)
{
	size_t	start = 0;
	size_t	pos = 0;
	std::string	result;


	while ((pos = input.find(replaced, start)) != std::string::npos)
	{
		result.append(input, start, (pos - start));
		result.append(will_replace);
		start = pos + replaced.length();
	}
	result.append(input, start, input.length() - start);
	return (result);
}

int	main(int argc, char **argv)
{
	std::ifstream	infile;
	std::ofstream	outile;
	std::string		input;
	std::string		fileReplace;

	if (argc != 4)
	{
		std::cout << "Bad argument count" << std::endl;
		return (1);
	}
	infile.open(argv[1]);
	if (infile.bad() || !infile.is_open() || infile.fail())
	{
		std::cout << "Bad infile" << std::endl;
		return (1);
	}
	getline(infile, input, '\0');
	infile.close();
	fileReplace = argv[1];
	fileReplace.append(".replace");
	outile.open(fileReplace);
	if (outile.bad() || !outile.is_open() || outile.fail())
	{
		std::cout << "Bad outfile" << std::endl;
		return (1);
	}
	input = ft_replace(input, argv[2], argv[3]);
	outile << input;
	outile.close();
	return (0);
}
