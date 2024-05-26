#include <iostream>

int main() {
	int sum{0};

	std::cout << "Geben sie beliebig viele Zahlen ein, um die Summe zu berechnen." << std::endl;
	std::cout << "Die Eingabe einer 0 beendet die Eingabe und gibt das Ergebnis aus." << std::endl;

	while(1) {
		int input{0};
		std::cout << "Eingabe: ";
		std::cin >> input;
		if (input==0)
			break;
		sum += input;
	}
	std::cout << "Die Summe aller eingegebenen Zahlen ist " << sum << std::endl;
}
