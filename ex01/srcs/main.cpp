#include <phonebook.hpp>

void	handle_cmd ( commands cmd, PhoneBook phonebook ) {
	switch ( cmd ) {
		case ADD:
			phonebook.add_contact();
			break;
		case SEARCH:
			phonebook.show_contacts();
			break;
		case EXIT:
			exit ( 0 );
	}
}

void	show_menu( void ) {
	std::cout << MENU_INTRO << std::endl;
	std::cout << MENU_ADD << std::endl;
	std::cout << MENU_SEARCH << std::endl;
	std::cout << MENU_EXIT << std::endl;
	std::cout << INPUT_PROMPT;
}

commands	get_command( void ) {
	std::string cmd;

	while ( true ) {
		std::getline(std::cin, cmd);
		if (std::cin.eof()) {
			std::cout << std::endl << EOF_DETECTED << std::endl;
			exit ( 0 );
		}
		if ( !cmd.compare( "ADD" ) )
			return ADD;
		else if ( !cmd.compare( "SEARCH" ) )
			return SEARCH;
		else if ( !cmd.compare( "EXIT" ) )
			return EXIT;
		else {
			std::cout << UNKNOWN_COMMAND << std::endl;
			show_menu();
		}
	}
}

int main() {

	PhoneBook phonebook;

	while ( true ) {
		show_menu();
		switch ( get_command() ) {
			case ADD:
				phonebook.add_contact();
				break;
			case SEARCH:
				phonebook.show_contacts();
				break;
			case EXIT:
				exit ( 0 );
		}
	}
	return 0;
}