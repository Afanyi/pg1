#include <iostream>
#include <iomanip> 

int main() {
	int number;
	std::cout << "Bitte gib eine dreistellige Zahl ein." << std::endl;
	std::cin >>  number; 
	if (std::to_string(number).length() != 3) { //  i don't know how to check the length of an int with modulo/division only
		return 1;
	}
	std::cout << "Die eingegebene Nummer hat " << number / 100 << " hunderter, " << number  / 10 % 10 << " zehner und " << number % 10 << " einser." << std::endl;

}
