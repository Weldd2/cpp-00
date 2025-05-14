#pragma once

#include <iostream>
#include <string>
#include <iomanip>
#include "Contact.hpp"

class PhoneBook
{
	private:
		Contact		contacts[8];
		std::size_t nb_contacts;
	public:
		PhoneBook(void);
		PhoneBook(const PhoneBook& p);
		~PhoneBook(void);
		PhoneBook &operator=(const PhoneBook& p);
		Contact&	getContact(std::size_t index);
		void		addContact(const Contact& c);
		void		printContacts(void);
};