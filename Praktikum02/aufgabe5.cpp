#include <iostream>

int main() {
	char user_input{'*'};
	while (true) {
		std::cout << "Herzlich Willkommen zum Flächenberechner! \r\nVon Welcher Fläche soll die Fläche berechnet werden?\r\nk) Kreis\r\nr) Rechteck\r\nd) Dreieck\r\n\r\nq) Beenden" << std::endl;
		std::cin >> user_input;
		switch (user_input) {
			case 'k':
				[[fallthrough]];
			case 'r':
				[[fallthrough]];
			case 'd': {

				std::cout << "Wird noch implementiert..." << std::endl;
				break;
				  }
			case 'q':
				  {
				std::cout << "Goodbye" << std::endl;
				return 0;
				  }
			default:
				std::cout << "Invalid input" << std::endl;
		}
	}
}
