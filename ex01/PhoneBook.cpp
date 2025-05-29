#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void)
{
	this->nb_contacts = 0;
};

PhoneBook::PhoneBook(const PhoneBook &p)
{
	for (std::size_t i = 0; i < p.nb_contacts; ++i)
		this->contacts[i] = p.contacts[i];
	this->nb_contacts = p.nb_contacts;
};

PhoneBook::~PhoneBook(void) {};

PhoneBook &PhoneBook::operator=(const PhoneBook &p)
{
	if (this != &p)
	{
		for (std::size_t i = 0; i < p.nb_contacts; ++i)
			this->contacts[i] = p.contacts[i];
		this->nb_contacts = p.nb_contacts;
	}
	return (*this);
}

std::string print_truncate(std::string s)
{
	return (s.length() >= 10 ? s.substr(0, 9) + "." : s);
}

void PhoneBook::printContacts(void)
{
	std::cout
		<< "=============================================" << std::endl
		<< "|" << std::setw(10) << "index"
		<< "|" << std::setw(10) << "firstname"
		<< "|" << std::setw(10) << "lastname"
		<< "|" << std::setw(10) << "nickname" << "|" << std::endl
		<< "=============================================" << std::endl;
	for (std::size_t i = 0; i < this->nb_contacts; ++i)
	{
		std::cout
			<< "|" << std::setw(10) << i + 1
			<< "|" << std::setw(10) << print_truncate(this->contacts[i].getFirstname())
			<< "|" << std::setw(10) << print_truncate(this->contacts[i].getLastname())
			<< "|" << std::setw(10) << print_truncate(this->contacts[i].getNickname()) << "|"
			<< std::endl;
	}
	std::cout << "=============================================" << std::endl;
}

void PhoneBook::addContact(const Contact &c)
{
	if (this->nb_contacts == 8)
	{
		std::cout << this->nb_contacts;
		for (std::size_t i = 0; i < this->nb_contacts - 1; i++)
			this->contacts[i] = this->contacts[i + 1];
	}
	if (this->nb_contacts != 8)
		this->nb_contacts += 1;
	this->contacts[this->nb_contacts - 1] = c;
	this->printContacts();
}

Contact &PhoneBook::getContact(std::size_t index)
{
	if (index >= this->nb_contacts)
	{
		std::cerr << "error: invalid index" << std::endl;
		throw std::out_of_range("Invalid index");
	}
	return (this->contacts[index]);
}
