#include "phoneBook.hpp"

Contact::Contact(
	std::string first,
	std::string last,
	std::string nick,
	std::string phone,
	std::string secret
) {
	if (first.empty() || last.empty() || nick.empty() || 
		phone.empty() || secret.empty()) {
		throw std::invalid_argument("All contact fields must be non-empty");
	}
	setId();
	firstname = first;
	lastname = last;
	nickname = nick;
	phoneNumber = phone;
	darkestSecret = secret;
}
	
Contact::Contact() : id(0), firstname(""), lastname(""), nickname("") {
	setId();
}

void	Contact::setId(void) {
	static int	index = 1;
	this->id = index;
	index++;
}

std::ostream& operator<<(std::ostream& os, const Contact& c) {
	os
		<< "firstname : " << c.firstname << std::endl
		<< "lastname : " << c.lastname << std::endl
		<< "nickname : " << c.nickname << std::endl
		<< "phone number : " << c.phoneNumber << std::endl
		<< "darkest secret : " << c.darkestSecret << std::endl;
	return os;
}

bool Contact::operator<(const Contact& other) const {
	if (lastname != other.lastname) {
		return lastname < other.lastname;
	}
	return firstname < other.firstname;
}

int Contact::getId(void) const {
	return id;
}

std::string Contact::getFirstname(void) const {
	return firstname;
}

std::string Contact::getLastname(void) const {
	return lastname;
}

std::string Contact::getNickname(void) const {
	return nickname;
}

std::string Contact::getPhoneNumber(void) const {
	return phoneNumber;
}

std::string Contact::getSecret(void) const {
	return darkestSecret;
}

std::istream& operator>>(std::istream& is, Contact& c) {
	std::cout << "Firstname : " << std::endl;
	is >> c.firstname;
	if (c.firstname.empty()) {
		throw std::invalid_argument("Firstname cannot be empty");
	}
	std::cout << "Lastname : " << std::endl;
	is >> c.lastname;
	if (c.lastname.empty()) {
		throw std::invalid_argument("Lastname cannot be empty");
	}
	std::cout << "Nickname : " << std::endl;
	is >> c.nickname;
	if (c.nickname.empty()) {
		throw std::invalid_argument("Nickname cannot be empty");
	}
	std::cout << "PhoneNumber : " << std::endl;
	is >> c.phoneNumber;
	if (c.phoneNumber.empty()) {
		throw std::invalid_argument("PhoneNumber cannot be empty");
	}
	std::cout << "Darkest Secret : " << std::endl;
	std::getline(is >> std::ws, c.darkestSecret);
	if (c.darkestSecret.empty()) {
		throw std::invalid_argument("Darkest Secret cannot be empty");
	}
	return is;
}
