#include <iostream>
#include <cstring>
#include <cctype>

std::string	str_to_upper(std::string s)
{
	std::string	s_cpy;

	s_cpy = s;
	for(std::size_t i = 0; i < s_cpy.size(); i++)
		s_cpy[i] = (char)std::toupper(s[i]);
	return (s_cpy);
}

int main(int argc, char const *argv[])
{
	if (argc == 1) std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	for (std::size_t i = 1; i < (std::size_t)argc; i++)
		std::cout << str_to_upper(argv[i]);
	return (std::cout << std::endl, 0);
}
