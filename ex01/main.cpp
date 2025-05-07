#include "Contact.hpp"
#include "PhoneBook.hpp"
#include <sstream>

void	add(PhoneBook &p)
{
	std::string	firstname;
	std::string	lastname;
	std::string	nickname;
	std::string	darkestSecret;
	std::string	phoneNumber;

	std::cin >> firstname;
	std::cin.clear();
	std::cin >> lastname;
	std::cin.clear();
	std::cin >> nickname;
	std::cin.clear();
	std::cin >> darkestSecret;
	std::cin.clear();
	std::cin >> phoneNumber;
	std::cin.clear();
	p.addContact(Contact(firstname, lastname, nickname, phoneNumber, darkestSecret));
}

void	search(PhoneBook &p)
{
	std::string	index;
	p.printContacts();
	std::cout << "contact to print (cancel to return to menu) :" << std::endl;
	std::cin >> index;
	int num;
	if (index == "CANCEL")
		return ;
	try {
		std::istringstream iss(index);
		if (iss >> num) {
			std::cout << p.getContact(num - 1);
		} else {
			throw std::invalid_argument("invalid index");
		}
	} catch (const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
}

int	main(void)
{
	std::string	action;
	PhoneBook p;
	while (1)
	{
		std::cout << "what do you want to do ?" << std::endl;
		std::cout << "- ADD" << std::endl;
		std::cout << "- SEARCH" << std::endl;
		std::cout << "- EXIT" << std::endl;
		std::cin >> action;
		if (action == "EXIT")
			break ;
		if (action == "ADD")
			add(p);
		if (action == "SEARCH")
			search(p);
		std::cin.clear();
	}
}
