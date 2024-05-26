#include <iostream>
#include <random>

int main() {
	std::srand(time(0));
	int number_to_guess = std::rand() % 10;
	std::cout << number_to_guess;
	int user_input{0};
	for (int i=0; i!=5; i++) {
		std::cout << "Versuch " << i+1 << "Bitte rate eine Zahl  zwischen 0 und 10" <<std::endl;
		std::cin >> user_input;
		if (user_input == number_to_guess) {
			std::cout << "Im folgenden Versuch wurde die richtige Zahl eingegeben: " << i+1 << std::endl;
			return 0;
		}
	}
	std::cout << "Maximale Versuche erreicht." << std::endl;
			     	
}	

