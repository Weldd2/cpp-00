#include "phoneBook.hpp"

void	ft_toupper(std::string *str) {
	for (std::size_t i = 0; i < (*str).length(); i++) {
		(*str)[i] = std::toupper((*str)[i]);
	}
}

std::string truncate(std::string str) {
	if (str.length() > 10)
		return str.substr(0, 9) + ".";
	return str;
}

void	add(PhoneBook *book)
{
	Contact c;
	std::cin >> c;
	book->addContact(c);
	std::cout << "Contact added successfully" << std::endl;
	std::cout << "Contact count : " << book->getNbContact() << std::endl;
}

void	search(PhoneBook book)
{
	int			id;
	std::string	s_id;

	book.printContactList();
	std::cout << "Type the id or BACK : ";
	std::cin >> s_id;
	ft_toupper(&s_id);
	if (s_id == "BACK")
		return ;
	std::istringstream(s_id) >> id;
	std::cout << book.getContactById(id);
}

int main(void)
{
	PhoneBook book = PhoneBook();
	std::string action;

	while (1) {
		std::cout	<< "What do you want to do ?" << std::endl
					<< "ADD, "
					<< (book.getNbContact() > 0 ? "SEARCH, " : "")  
					<< "EXIT" << std::endl;
		std::cin >> action;
		ft_toupper(&action);
		if (action == "ADD")
			add(&book);
		if (action == "EXIT")
			break ;
		if (book.getNbContact() >= 0 && action == "SEARCH")
			search(book);
	}
	return 0;
}
