#include "Contact.hpp"

Contact::Contact(void) {};

Contact::Contact(const Contact &c)
{
	this->firstname = c.firstname;
	this->lastname = c.lastname;
	this->nickname = c.nickname;
	this->phoneNumber = c.phoneNumber;
	this->darkestSecret = c.darkestSecret;
}

Contact::~Contact(void) {}

Contact &Contact::operator=(const Contact &c)
{
	if (this != &c)
	{
		this->firstname = c.firstname;
		this->lastname = c.lastname;
		this->nickname = c.nickname;
		this->phoneNumber = c.phoneNumber;
		this->darkestSecret = c.darkestSecret;
	}
	return (*this);
}

Contact::Contact(
	const std::string &firstname,
	const std::string &lastname,
	const std::string &nickname,
	const std::string &phoneNumber,
	const std::string &darkestSecret)
{
	this->firstname = firstname;
	this->lastname = lastname;
	this->nickname = nickname;
	this->phoneNumber = phoneNumber;
	this->darkestSecret = darkestSecret;
};

void Contact::PrintContact(void)
{
	std::cout
		<< "firstname : " << this->getFirstname() << std::endl
		<< "lastname : " << this->getLastname() << std::endl
		<< "nickname : " << this->getNickname() << std::endl
		<< "phone number : " << this->getPhoneNumber() << std::endl
		<< "darkest secret : " << this->getDarkestSecret() << std::endl;
}

std::string Contact::getFirstname(void) { return (this->firstname); }
std::string Contact::getLastname(void) { return (this->lastname); }
std::string Contact::getNickname(void) { return (this->nickname); }
std::string Contact::getPhoneNumber(void) { return (this->phoneNumber); }
std::string Contact::getDarkestSecret(void) { return (this->darkestSecret); }
