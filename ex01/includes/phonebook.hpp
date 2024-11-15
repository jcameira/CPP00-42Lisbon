#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <contact.hpp>

# define MENU_INTRO "Enter one of the following commands (The commands are case sensitive)."
# define MENU_ADD "ADD: Adds a contact to the phonebook."
# define MENU_SEARCH "SEARCH: Will display contact information."
# define MENU_EXIT "EXIT: Will exit the program."
# define UNKNOWN_COMMAND "Please enter one of the possible commands."
# define INPUT_PROMPT "> "
# define EOF_DETECTED "EOF detected, the program will now exit"
# define SEARCH_CONTACT "Write the index of the contact you would like to know more about: "
# define USAGE "Write \\help if you want to know the possible commands"

# define FIRST_NAME "First name: "
# define LAST_NAME "Last name: "
# define NICKNAME "Nickname: "
# define PHONE_NUMBER "Phone Number: "
# define DARKEST_SECRET "Darkest secret: "

# define EMPTY_FIELD "Field can't be empty"
# define INVALID_INDEX "Please write a valid contact index"
# define INVALID_PHONE_NUMBER "Please write a valid phone number"
# define NO_CONTACT "No contact available for the given index"

# define TABLE_HEADER "_____________________________________________\n|Index     |First Name|Last Name |Nickname  |"

enum commands {
	ADD = 1,
	SEARCH,
	HELP,
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

	int		_num_c;
	Contact _contacts[8];
};

#endif