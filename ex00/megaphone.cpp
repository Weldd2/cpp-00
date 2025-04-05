#include <iostream>
#include <cstring>
#include <cctype>

int main(int argc, char const *argv[])
{
	if (argc == 1) std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	for (std::size_t i = 1; i < (std::size_t)argc; i++) {
		for (std::size_t j = 0; j < strlen(argv[i]); j++) {
			std::cout << (char)std::toupper(argv[i][j]);
		}
	}
	return (std::cout << std::endl, 0);
}
