#include <iostream>
#include <random>
#include <string>
#include <ctime>

int main() {
    std::srand(std::time(nullptr));
    int money = 1e4;
    std::cout << money << std::endl;
    unsigned int stake{0};
    unsigned short betted_number{0};
    while (money > 0) {
        int random_number = std::rand() % 36;
        char modi{'*'}; // saves the game modi as char, possible options are f,z,s
        std::cout << "Bitte schreibe deinen Einsatz" << std::endl;
        std::cin >> stake;
        while (!(modi == 'f' or modi == 'z' or modi == 's')) {
            std::cout << "Bitte gib den Spielmodus an. Optionen sind (f)arbe, (s)palte, (z)ahl" << std::endl;
            std::cin >> modi;
        }
        switch (modi) {
            case 'f': {
                std::string color = "None";
                while (!(color == "Rot" or color == "Schwarz")) {
                    std::cout << "Bitte gib die Farbe ein (Rot oder Schwarz)" << std::endl;
                    std::cin >> color;
                }
                if (random_number != 0 and (random_number % 2 == 0 and color == "Schwarz"
                                                                       or random_number % 2 == 1 and color == "Rot")) {
                    std::cout << "Du hast gewonnen" << std::endl;
                    money = stake * 2 + money;
                } else {
                    std::cout << "Du hast verloren" << std::endl;
                    money = money - stake;
                }
                break;
            }
                case 's': {
                    int row{0};
                    while (0 >= row or 4 < row) {
                        std::cout << "Deklarie die Spalte auf die du wettest (1,2,3)." << std::endl;
                        std::cin >> row;
                    }
                    if (row - 1 == random_number - 1 % 3) { // checks if the player bets on the correct row
                        std::cout << "Du hast gewonnen " << std::endl;
                        money = stake * 2 + money;
                    } else {
                        std::cout << "Du hast verloren" << std::endl;
                        money = money - stake;
                    }
    
                    break;
                }
                case 'z': {
                    std::cout << "Bitte schreibe die Zahl auf die du setzst" << std::endl;
                    std::cin >> betted_number;
        
        
                    if (betted_number == random_number) {
                        std::cout << "Du hast gewonnen" << std::endl;
                        money = stake * 35 + money;
                    } else {
                        std::cout << "Du hast verloren" << std::endl;
                        money = money - stake;
                    }
                    break;
                default:
                    std::cout << "Kein  valide Wahl. Diese Runde läuft ohne dich." << std::endl;
            }
        }
        std::cout << "Die Nummer ist " << random_number << std::endl;
        std::cout << "Du hast " << money << " Währungseinheiten" << std::endl;
    }
    std::cout << "Du bist pleite." << std::endl;
}
