#include <iostream>
#include <random>


int main() {
	std::srand(time(0));	
	int money = 1e4;
	std::cout << money << std::endl;
	unsigned int stake{0};
	unsigned short betted_number;
	unsigned short random_number;
	while (money > 0) {
		std::cout << "Bitte schreibe deinen Einsatz" << std::endl;
		std::cin >> stake;
		std::cout << "Bitte schreibe die Zahl auf du setzst" << std::endl;
		std::cin >> betted_number;
		// std::cout << "Bitte schreibe die Zahl die 'zufällig' im Route fällt (zwischen 0 und 36)" << std::endl;
		// std::cin >> random_number;
		random_number = std::rand() % 37;

		std::cout << "Die nummer ist " <<  random_number;
		if (betted_number == random_number) {
			std::cout << ". Du hast gewonnen" << std::endl;
			money = stake * 35 + money;
		}
		else{
			std::cout << ". Du hast verloren" << std::endl;
			money = money - stake;
		}
		std::cout << "Du hast " << money << " Währungseinheiten" << std::endl;
	}
}
