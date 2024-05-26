#include <iostream>

int main() {
	std::cout << "Bitte geben sie zwei Zahlen ein." << std::endl;
	int number1{0};
	int number2{0};

	std::cin >> number1 >> number2;
	std::cout << "Die Summe aus " << number1 << " und " << number2 << "ist:" <<number1 + number2 << std::endl;
}
