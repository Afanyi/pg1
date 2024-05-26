#include <iostream>

int main() {
	std::cout << "Bitte geben sie ihr geburtsjahr ein " << std::endl;
	int gebJahr{0};
	std::cin  >>  gebJahr;
	std::cout << "Sie sind ca " << 2023 - gebJahr << " Jahre alt." << std::endl;
	return 0;
}
