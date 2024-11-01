#include <contact.hpp>

Contact::Contact( void ) {
	std::cout << "Default\n";  
}

Contact::Contact( std::string first_name,
					std::string last_name,
					std::string nickname,
					std::string phone_number,
					std::string darkest_secret )
					:
					_first_name( first_name ),
					_last_name( last_name ),
					_nickname( nickname ),
					_phone_number( phone_number ),
					_darkest_secret( darkest_secret ) {
	std::cout << "Copy\n";
}

Contact::~Contact( void ) {
}

std::string	Contact::get_first_name( void ) const {
	return (this->_first_name);
}

std::string	Contact::get_last_name( void ) const {
	return (this->_last_name);
}

std::string	Contact::get_nickname( void ) const {
	return (this->_nickname);
}

std::string	Contact::get_phone_number( void ) const {
	return (this->_phone_number);
}

std::string	Contact::get_darkest_secret( void ) const {
	return (this->_darkest_secret);
}
