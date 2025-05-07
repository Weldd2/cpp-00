#pragma once

#include <iostream>
#include <string>

class Contact
{
	private:
		std::string	firstname;
		std::string	lastname;
		std::string	nickname;
		std::string	phoneNumber;
		std::string	darkestSecret;
	public:
		Contact(void);
		Contact(const Contact&);
		~Contact(void);
		Contact	&operator=(const Contact&);
		friend	std::ostream& operator<<(std::ostream& out, const Contact& c);
		Contact(
			const std::string& firstname,
			const std::string& lastname,
			const std::string& nickname,
			const std::string& phoneNumber,
			const std::string& darkestSecret
		);
		std::string	getFirstname(void);
		std::string	getLastname(void);
		std::string	getNickname(void);
		std::string	getPhoneNumber(void);
		std::string	getDarkestSecret(void);
};
