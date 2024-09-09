#include <contact.hpp>

Contact::Contact( void ) {   
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
}

Contact::~Contact( void ) {
}