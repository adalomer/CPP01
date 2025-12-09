#include <iostream>
#include <fstream>
#include <string>

std::string	replaceAll(std::string str, std::string s1, std::string s2)
{
	std::string	result;
	size_t		pos;
	size_t		lastPos;

	if (s1.empty())
		return (str);
	lastPos = 0;
	pos = str.find(s1);
	while (pos != std::string::npos)
	{
		result += str.substr(lastPos, pos - lastPos);
		result += s2;
		lastPos = pos + s1.length();
		pos = str.find(s1, lastPos);
	}
	result += str.substr(lastPos);
	return (result);
}

int	main(int argc, char **argv)
{
	if (argc != 4)
	{
		std::cerr << "Usage: ./replace <filename> <s1> <s2>" << std::endl;
		return (1);
	}

	std::string		filename = argv[1];
	std::string		s1 = argv[2];
	std::string		s2 = argv[3];
	std::ifstream	infile(filename.c_str());

	if (!infile.is_open())
	{
		std::cerr << "Error: Cannot open file " << filename << std::endl;
		return (1);
	}

	std::string		outfilename = filename + ".replace";
	std::ofstream	outfile(outfilename.c_str());

	if (!outfile.is_open())
	{
		std::cerr << "Error: Cannot create file " << outfilename << std::endl;
		infile.close();
		return (1);
	}

	std::string	line;
	while (std::getline(infile, line))
	{
		outfile << replaceAll(line, s1, s2);
		if (!infile.eof())
			outfile << std::endl;
	}

	infile.close();
	outfile.close();
	return (0);
}
