#include <iostream>
#include <cstring>

int	main(int argc, char **argv) {
	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	else
		for (int i = 1; i < argc; i++)
			for (int j = 0; j < (int)std::strlen(argv[i]); j++)
				std::cout << (char)std::toupper(argv[i][j]);
	std::cout << '\n';
	return 0;
}
