#include <phonebook.hpp>

int	check_eof( void )
{
	if (std::cin.eof())
	{
		std::cout << std::endl << NO_CONTACT_ADDED;
		std::cin.clear();
		return (1);
	}
	return (0);
}

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
	std::cout << MENU_INTRO;
	std::cout << MENU_ADD;
	std::cout << MENU_SEARCH;
	std::cout << MENU_EXIT;
	std::cout << INPUT_PROMPT;
}

commands	get_command( void ) {
	std::string cmd;

	while ( true ) {
		std::getline(std::cin, cmd);
		if (std::cin.eof()) {
			if (!std::cin)
				exit ( 0 );
			std::cin.clear();
			std::cout << std::endl << INPUT_PROMPT;
			continue ;
		}
		if ( !cmd.compare( "ADD" ) )
			return ADD;
		else if ( !cmd.compare( "SEARCH" ) )
			return SEARCH;
		else if ( !cmd.compare( "EXIT" ) )
			return EXIT;
		else {
			std::cout << UNKNOWN_COMMAND;
			show_menu();
		}
	}
}

int main() {

	PhoneBook phonebook;

	std::ios_base::sync_with_stdio(false);
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