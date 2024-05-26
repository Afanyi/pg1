#include <iostream>
#include <vector>
#include <algorithm>

int main() {
	std::cout << "Bitte gib eine beliebige Menge positiver Ganzzahlen ein." << std::endl;
	std::cout << "Gib 0 ein, falls die Eingabe beendet werden soll." << std::endl;
	std::vector<int> input_list;
	int user_input{0};
	do {
		std::cin >> user_input;
		if (user_input != 0) 
			input_list.push_back(user_input);
	}while(user_input>0);
	
	std::vector<int>::iterator min = std::min_element(input_list.begin(), input_list.end());
	std::vector<int>::iterator max = std::max_element(input_list.begin(), input_list.end());
	int summe = 0;
	for (int i: input_list)
		summe = summe + i;
	std::cout  << std::endl;
	std::cout << "Die kleinste Zahl ist " << *min << "und die größte ist :"  << *max << ". Die Gesamtsumme ist "<< summe << std::endl;
	
}
