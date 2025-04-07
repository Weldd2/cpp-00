#include "phoneBook.hpp"

PhoneBook::PhoneBook(void) {
	PhoneBook::setId();
	contacts = std::list<Contact>();
	contacts_sorted = contacts;
}

void	PhoneBook::setId(void) {
	static int	index = 1;
	if (this->id != 0)
		return ;
	this->id = index;
	index++;
}

void	PhoneBook::addContact(Contact c)
{
	if (this->getNbContact() >= 8)
		this->contacts.pop_front();
	this->contacts.push_back(c);
	this->contacts_sorted = contacts;
	this->contacts_sorted.sort();
}

int	PhoneBook::getNbContact()
{
	return this->contacts.size();
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

