#include <iostream>

int main() {
	int x{0};
	std::cout << "Bitte eine zahl eingeben" << std::endl;
	std::cin >> x;

	if (x % 2==0) 
		std::cout << " Die eingegebene Zahl ist gerade." << std::endl;
	else 
		std::cout << "Die eingegebene Zahl ist ungerade" << std::endl;
}
