#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <sstream>
# include <iostream>
# include <string>
# include <iomanip>
# include <list>

class Contact
{
	private:
		void		setId(void);
	public:
		Contact();
		Contact(
			std::string first,
			std::string last,
			std::string nick,
			std::string phone,
			std::string secret
		);
		int			id;
		std::string	firstname;
		std::string	lastname;
		std::string	nickname;
		std::string	phoneNumber;
		std::string	darkestSecret;
		int			getId(void) const;
		std::string	getFirstname(void) const;
		std::string	getLastname(void) const;
		std::string	getNickname(void) const;
		std::string	getPhoneNumber(void) const;
		std::string	getSecret(void) const;
		bool		operator<(const Contact& other) const;
		friend std::istream& operator>>(std::istream& is, Contact& c);
		friend std::ostream& operator<<(std::ostream& os, const Contact& c);
};

std::ostream& operator<<(std::ostream& os, const Contact& c);
std::istream& operator>>(std::istream& is, Contact& c);

class PhoneBook
{
	private:
		int					id;
		std::list<Contact>	contacts;
		std::list<Contact>	contacts_sorted;
		void				setId(void);
	public:
		PhoneBook(void);
		int			getNbContact();
		void		printContact(int id);
		void		addContact(Contact c);
		Contact		getContactById(int id);
		void		printContactList(void);
};

std::string truncate(std::string str);
void		ft_toupper(std::string *str);

#endif
