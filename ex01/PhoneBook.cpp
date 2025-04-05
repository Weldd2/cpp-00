#include "phoneBook.hpp"

PhoneBook::PhoneBook(void) {
	PhoneBook::setId();
	contacts = std::list<Contact>();
	contacts_sorted = contacts;
}

void	PhoneBook::setId(void) {
	static int	index = 1;
	if (PhoneBook::id != 0)
		return ;
	PhoneBook::id = index;
	index++;
}

void	PhoneBook::addContact(Contact c)
{
	if (PhoneBook::getNbContact() >= 8)
		PhoneBook::contacts.pop_front();
	PhoneBook::contacts.push_back(c);
	PhoneBook::contacts_sorted = contacts;
	PhoneBook::contacts_sorted.sort();
}

int	PhoneBook::getNbContact()
{
	return PhoneBook::contacts.size();
}

Contact PhoneBook::getContactById(int id)
{
	for (std::list<Contact>::iterator it = contacts.begin(); it != contacts.end(); ++it)
	{
		if (it->id == id)
			return *it;
	}
	return contacts.front();
}

void PhoneBook::printContactList(void)
{
	std::cout	<< "|----------|----------|----------|----------|" << std::endl
				<< "|        ID| Firstname|  Lastname|  Nickname|" << std::endl
				<< "|----------|----------|----------|----------|" << std::endl;
	int index = 1;
	for (std::list<Contact>::iterator it = contacts_sorted.begin(); it != contacts_sorted.end(); ++it, ++index)
	{
		std::cout	<< "|"
					<< std::setw(10) << index << "|"
					<< std::setw(10) << truncate((*it).firstname) << "|"
					<< std::setw(10) << truncate((*it).lastname) << "|"
					<< std::setw(10) << truncate((*it).nickname) << "|"
					<< std::endl;
	}
	std::cout << "|----------|----------|----------|----------|" << std::endl;
}

