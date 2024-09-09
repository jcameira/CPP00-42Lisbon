#ifndef CONTACT_CPP
# define CONTACT_CPP

# include <iostream>
# include <cstdlib>

class	Contact {
	public:

	Contact();
	Contact(std::string first_name,
			std::string last_name,
			std::string nickname,
			std::string phone_number,
			std::string darkest_secret);
	~Contact();

	private:

	std::string _first_name;
	std::string _last_name;
	std::string _nickname;
	std::string _phone_number;
	std::string _darkest_secret;
};

#endif