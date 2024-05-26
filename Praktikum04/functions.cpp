#include "functions.h"

const  int FIELD_SIZE = 12;
const int MINE_AMOUNT = 20;
std::array<std::array<Tile,FIELD_SIZE>,FIELD_SIZE>gameField;
int getRandom(int lower, int upper)
{
    std::uniform_int_distribution<int> dist(lower, upper);
    return dist(rd);
}
int mineAround(int x,int y)
{
    int mineF = 0;
    for(int i=-1;i<=1;i++){
        for(int j=-1;j<=1;j++){
            if(gameField[x + i][y + j].status == MINE){
                mineF++;
            }
        }
    }
    return mineF;
}
void initialize(int mineAmount){
    std::srand(time(nullptr));

    for(int i=0;i<FIELD_SIZE;i++) {
        for (int j = 0; j < 12; j++) {
            gameField[i][j].status = HIDDEN;
        }
    }
    for(int i=0; i <= mineAmount; i++){
        int x,y;
        do{ x = getRandom(1,FIELD_SIZE-1);
            y = getRandom(1,FIELD_SIZE-1);
        }while(gameField[x][y].status == MINE);
        gameField[x][y].status = MINE;
        gameField[x][y].mineAround = mineAround(x, y);
    }
    for(int i=0;i<FIELD_SIZE;i++) {
        for (int j = 0; j < 12; j++) {
            gameField[i][j].mineAround = mineAround(i, j);
        }
    }

}
bool revealedEmptyNeighbor(int x, int y)
{
    for(int i=-1;i<=1;i++){
        for(int j=-1;j<=1;j++){
            if(gameField[x + i][y + j].status == REVEALED
            and gameField[x + i][y + j].mineAround == 0
            and not (x+i>11||y+j>11||x+i<0||y+j<0))  // checks if the position is valid
            {
                return true;
            }
        }
    }
    return false;
}
bool checkNeighbours()
{
    for(int a=0;a<FIELD_SIZE;a++){
        for(int b=0;b<FIELD_SIZE;b++){
            if(gameField[a][b].status == HIDDEN && revealedEmptyNeighbor(a, b)){
                gameField[a][b].status = REVEALED;
                return true;
            }
        }
    }

    return false;
}

void display(bool debug)
{
    std::vector<std::string> z={"00|","01|","02|","03|","04|","05|","06|","07|","08|","09|","10|","11|"};
    if(debug){
        std::cout << std::endl;
        for(int i=0;i<FIELD_SIZE;i++){
            std::cout << z[i] << "  ";
            for(int j=0;j<FIELD_SIZE;j++){
                if (gameField[i][j].status == MINE) {
                    std::cout << 'x' << "  ";
                }
                else{
                    std::cout << '*' << "  ";
                }
            }
            std::cout << std::endl;
        }
        std::cout <<"    ";
        for(int i=0;i<FIELD_SIZE;i++){
            std::cout << '-' << "--";
        }
        std::cout << std::endl;
        std::cout <<"    ";
        for(int i=0;i<FIELD_SIZE;i++){
            std::cout << i << "  ";
        }
    }
    std::cout << std::endl;
    std::cout << std::endl;
    for(int i=0;i<FIELD_SIZE;i++){
        std::cout << z[i] << "  ";
        for(int j=0;j<FIELD_SIZE;j++){
            if (gameField[i][j].status == HIDDEN || gameField[i][j].status == MINE){
                std::cout << '*' << "  ";
            }
            else {
                if(gameField[i][j].mineAround == 0){
                    std::cout << '.' << "  ";
                }
                else{
                    std::cout << gameField[i][j].mineAround << "  ";
                }
            }
        }
        std::cout << std::endl;
    }
    std::cout <<"    ";
    for(int i=0;i<FIELD_SIZE;i++){
        std::cout << '-' << "--";
    }
    std::cout <<"\r\n    ";
    for(int i=0;i<FIELD_SIZE;i++){
        std::cout << i << "  ";
    }
    std::cout << std::endl;
}
bool userInput(int& counter)
{
    bool mineTile = true;
    int eingabex=0;
    int eingabey=0;
    do{
        std::cout << "geben sie den y-coord wert : ";
        std::cin >> eingabex;
        std::cout << "geben sie den x-coord wert : ";
        std::cin >> eingabey;
        if(eingabex <0 || eingabex >=FIELD_SIZE ||eingabey <0 || eingabey >=FIELD_SIZE || gameField[eingabex][eingabey].status == REVEALED){
            std::cout << "one or both of the values are out of range or already revealed. Try again" << std::endl;
        }
    }while (eingabex <0 || eingabex >=FIELD_SIZE ||eingabey <0 || eingabey >=FIELD_SIZE || gameField[eingabex][eingabey].status == REVEALED);
    if(gameField[eingabex][eingabey].status == MINE){
        std::cout << "boom!! u gave the location of a MINE. u loose " << std::endl;
        mineTile = false;
    }
    else{
        gameField[eingabex][eingabey].status = REVEALED;
        counter = counter - 1;
        gameField[eingabex][eingabey] = gameField[eingabex][eingabey];
    }
    return mineTile;
}

int main()
{
    int counter = FIELD_SIZE*FIELD_SIZE-MINE_AMOUNT;
    bool running = true;
    bool debug = true;
    initialize(MINE_AMOUNT);
    while(running){
        std::cout << "Es gibt noch " << counter << "verdeckte Felder." << std::endl;
        display(debug);
        running = userInput(counter);
        while(checkNeighbours()) {
            counter = counter - 1;
        }
        if(counter == 0){
            std::cout << "Du hast gewonnen." << std::endl;
            running = false;
        }
    }
    return 0;
}
