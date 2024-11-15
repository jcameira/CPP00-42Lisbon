#include <phonebook.hpp>

PhoneBook::PhoneBook( void ): _num_c( 0 ) {
}

PhoneBook::~PhoneBook( void ) {
}

void	PhoneBook::add_contact( void ) {
	std::string first_name, last_name, nickname, phone_number, darkest_secret;

	while ( !std::cin.eof() ) {
		std::cout << FIRST_NAME;
		std::getline( std::cin, first_name );
		if ( !first_name.length() && !std::cin.eof() )
			std::cout << EMPTY_FIELD << std::endl;
		else
			break ;
	}
	while ( !std::cin.eof() ) {
		std::cout << LAST_NAME;
		std::getline( std::cin, last_name );
		if ( !last_name.length() && !std::cin.eof() )
			std::cout << EMPTY_FIELD << std::endl;
		else
			break ;
	}
	while ( !std::cin.eof() ) {
		std::cout << NICKNAME;
		std::getline( std::cin, nickname );
		if ( !nickname.length() && !std::cin.eof() )
			std::cout << EMPTY_FIELD << std::endl;
		else
			break ;
	}
	while ( !std::cin.eof() ) {
		std::cout << PHONE_NUMBER;
		std::getline( std::cin, phone_number );
		if ( !phone_number.length() && !std::cin.eof() )
			std::cout << EMPTY_FIELD << std::endl;
		else
			for ( int i = 0; i < ( int )phone_number.length(); i++ )
				if ( !std::isdigit( phone_number[ i ] ) ) {
					std::cout << INVALID_PHONE_NUMBER << std::endl;
					continue ;
				}
			break ;
	}
	while ( !std::cin.eof() ) {
		std::cout << DARKEST_SECRET;
		std::getline( std::cin, darkest_secret );
		if ( !darkest_secret.length() && !std::cin.eof() )
			std::cout << EMPTY_FIELD << std::endl;
		else
			break ;
	}
	this->_contacts[ this->_num_c % 8 ] = Contact( first_name, last_name, nickname, phone_number, darkest_secret );
	_num_c++;
}

void	PhoneBook::show_contacts( void ) const {
	std::string data_field;

	std::cout << TABLE_HEADER << std::endl;
	for ( int i = 1; i < 9; i++ )
	{
		std::cout << "|" << i << std::setw( 10 );
		data_field = this->_contacts[ i - 1 ].get_first_name();
		if ( data_field.length() > 10 )
			std::cout << "|" << data_field.substr( 0, 9 ) + ".";
		else
			std::cout << "|" << data_field << std::setw( 11 - data_field.length() );
		data_field = this->_contacts[ i - 1 ].get_last_name();
		if ( data_field.length() > 10 )
			std::cout << "|" << data_field.substr( 0, 9 ) + ".";
		else
			std::cout << "|" << data_field << std::setw( 11 - data_field.length() );
		data_field = this->_contacts[ i - 1 ].get_nickname();
		if ( data_field.length() > 10 )
			std::cout << "|" << data_field.substr( 0, 9 ) + ".";
		else
			std::cout << "|" << data_field << std::setw( 11 - data_field.length() );
		std::cout << "|" << std::endl;
	}
	for ( int i = 0; i < 45; i++ )
		std::cout << "\u203E";
	std::cout << std::endl;
	search_contact();
}

void	PhoneBook::search_contact( void ) const {
	std::string	index;

	std::cout << SEARCH_CONTACT;
	while ( true ) {
		std::getline( std::cin, index );
		if ( std::cin.eof() )
			return ;
		if ( index.length() != 1 || index[ 0 ] < '1' || index[ 0 ] > '8' )
			std::cout << INVALID_INDEX << std::endl;
		else {
			if ( index[ 0 ] - 48 > this->_num_c ) {
				std::cout << NO_CONTACT << std::endl;
				return ;
			}
			else {
				std::cout << FIRST_NAME << this->_contacts[ index[ 0 ] - 49 ].get_first_name() << std::endl;
				std::cout << LAST_NAME << this->_contacts[ index[ 0 ] - 49 ].get_last_name() << std::endl;
				std::cout << NICKNAME << this->_contacts[ index[ 0 ] - 49 ].get_nickname() << std::endl;
				std::cout << PHONE_NUMBER << this->_contacts[ index[ 0 ] - 49 ].get_phone_number() << std::endl;
				std::cout << DARKEST_SECRET << this->_contacts[ index[ 0 ] - 49 ].get_darkest_secret() << std::endl;
				return ;
			}
		}
	}
}