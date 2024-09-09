#ifndef PHONEBOOK_CPP
# define PHONEBOOK_CPP

# include <contact.hpp>

# define MENU_INTRO "Enter one of the following commands (The commands are case sensitive).\n"
# define MENU_ADD "ADD: Adds a contact to the phonebook.\n"
# define MENU_SEARCH "SEARCH: Will display contact information.\n"
# define MENU_EXIT "EXIT: Will exit the program.\n"
# define INPUT_PROMPT ">"
# define UNKNOWN_COMMAND "Please enter one of the possible commands.\n"

# define ADD_FIRST_NAME "First name: "
# define ADD_LAST_NAME "Last name: "
# define ADD_NICKNAME "Nickname: "
# define ADD_PHONE_NUMBER "Phone Number: "
# define ADD_DARKEST_SECRET "Your darkest secret: "

enum commands {
	ADD = 1,
	SEARCH,
	EXIT
};

class	PhoneBook {
	public:

	PhoneBook();
	~PhoneBook();

	void	add_contact();
	void	show_contacts() const;
	void	search_contact() const;

	private:

	Contact _contacts[8];
};

#endif