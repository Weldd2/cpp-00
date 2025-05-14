#include "Contact.hpp"
#include "PhoneBook.hpp"
#include <sstream>

std::string	str_to_upper(std::string s)
{
	std::string	s_cpy;

	s_cpy = s;
	for(std::size_t i = 0; i < s_cpy.size(); i++)
		s_cpy[i] = (char)std::toupper(s[i]);
	return (s_cpy);
}

void	add(PhoneBook &p)
{
	std::string	firstname;
	std::string	lastname;
	std::string	nickname;
	std::string	darkestSecret;
	std::string	phoneNumber;

	std::cout << "firstname: ";
	std::getline(std::cin, firstname);
	std::cout << "lastname: ";
	std::getline(std::cin, lastname);
	std::cout << "nickname: ";
	std::getline(std::cin, nickname);
	std::cout << "phoneNumber: ";
	std::getline(std::cin, phoneNumber);
	std::cout << "darkestSecret: ";
	std::getline(std::cin, darkestSecret);
	p.addContact(Contact(firstname, lastname, nickname, phoneNumber, darkestSecret));
}

void	search(PhoneBook &p)
{
	std::string	answer;
	int			num;

	p.printContacts();
	std::cout << "contact to print (cancel to return to menu) :" << std::endl;
	std::getline(std::cin, answer);
	if (str_to_upper(answer) == "CANCEL")
		return ;
	try
	{
		std::istringstream iss(answer);
		if (iss >> num)
			std::cout << p.getContact(num - 1);
		else
			throw std::invalid_argument("invalid answer");
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
}

int	main(void)
{
	PhoneBook	p;
	std::string	action;

	while (1)
	{
		std::cout << "what do you want to do ?" << std::endl;
		std::cout << "- ADD" << std::endl;
		std::cout << "- SEARCH" << std::endl;
		std::cout << "- EXIT" << std::endl;
		std::getline(std::cin, action);
		action = str_to_upper(action);
		if (action == "EXIT")
			break ;
		if (action == "ADD")
			add(p);
		if (action == "SEARCH")
			search(p);
	}
}
