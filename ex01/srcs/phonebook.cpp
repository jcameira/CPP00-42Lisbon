#include <phonebook.hpp>

PhoneBook::PhoneBook( void ) {
}

PhoneBook::~PhoneBook( void ) {
}

void	PhoneBook::add_contact( void ) {
	static int	i = 0;
	std::string first_name, last_name, nickname, phone_number, darkest_secret;

	std::cout << ADD_FIRST_NAME;
	std::getline(std::cin, first_name);
	if (check_eof())
		return ;
	std::cout << ADD_LAST_NAME;
	std::getline(std::cin, last_name);
	if (check_eof())
		return ;
	std::cout << ADD_NICKNAME;
	std::getline(std::cin, nickname);
	if (check_eof())
		return ;
	std::cout << ADD_PHONE_NUMBER;
	std::getline(std::cin, phone_number);
	if (check_eof())
		return ;
	std::cout << ADD_DARKEST_SECRET;
	std::getline(std::cin, darkest_secret);
	if (check_eof())
		return ;
	this->_contacts[i % 8] = Contact(first_name, last_name, nickname, phone_number, darkest_secret);
	i++;
}

void	PhoneBook::show_contacts( void ) const {
	std::string data_field;

	std::cout << TABLE_HEADER;
	for (int i = 1; i < 9; i++)
	{
		std::cout << "|" << i << std::setw(10);
		data_field = this->_contacts[i - 1].get_first_name();
		if (data_field.length() > 10)
			std::cout << "|" << data_field.substr(0, 9) + ".";
		else
			std::cout << "|" << data_field << std::setw(11 - data_field.length());
		data_field = this->_contacts[i - 1].get_last_name();
		if (data_field.length() > 10)
			std::cout << "|" << data_field.substr(0, 9) + ".";
		else
			std::cout << "|" << data_field << std::setw(11 - data_field.length());
		data_field = this->_contacts[i - 1].get_nickname();
		if (data_field.length() > 10)
			std::cout << "|" << data_field.substr(0, 9) + ".";
		else
			std::cout << "|" << data_field << std::setw(11 - data_field.length());
		std::cout << "|" << std::endl;
	}
	for (int i = 0; i < 45; i++)
		std::cout << "\u203E";
	std::cout << std::endl;
}

void	PhoneBook::search_contact( void ) const {
}