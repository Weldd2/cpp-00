#include "Contact.hpp"
#include "PhoneBook.hpp"
#include <sstream>
#include <limits>
#include <cstdlib>

std::string str_to_upper(std::string s)
{
	std::string s_cpy;

	s_cpy = s;
	for (std::size_t i = 0; i < s_cpy.size(); i++)
		s_cpy[i] = (char)std::toupper(s[i]);
	return (s_cpy);
}

std::string getInput(const std::string &prompt)
{
	std::string input;
	while (1)
	{
		std::cout << prompt << ": ";
		std::getline(std::cin, input);
		if (std::cin.eof())
		{
			std::cin.clear();
			std::cout << std::endl
					  << "EOF detected, exiting..." << std::endl;
			exit(0);
		}
		if (std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cerr << "Input error occurred, please try again." << std::endl;
			continue;
		}
		if (!input.empty())
			break;
	}
	return input;
}

void add(PhoneBook &p)
{
	std::string firstname;
	std::string lastname;
	std::string nickname;
	std::string darkestSecret;
	std::string phoneNumber;

	firstname = getInput("firstname");
	lastname = getInput("lastname");
	nickname = getInput("nickname");
	phoneNumber = getInput("phoneNumber");
	darkestSecret = getInput("darkestSecret");
	p.addContact(Contact(firstname, lastname, nickname, phoneNumber, darkestSecret));
}

void search(PhoneBook &p)
{
	std::string answer;
	int num;

	p.printContacts();
	answer = getInput("Enter contact ID");
	if (str_to_upper(answer) == "CANCEL")
		return;
	try
	{
		std::istringstream iss(answer);
		if (iss >> num)
			p.getContact(num - 1).PrintContact();
		else
			throw std::invalid_argument("invalid answer");
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
}

int main(void)
{
	PhoneBook p;
	std::string action;
	const std::string prompt = "What do you want to ?\n- ADD\n- SEARCH\n- EXIT\n";

	while (1)
	{
		action = getInput(prompt);
		action = str_to_upper(action);
		if (action == "EXIT")
			break;
		if (action == "ADD")
			add(p);
		if (action == "SEARCH")
			search(p);
	}
}
