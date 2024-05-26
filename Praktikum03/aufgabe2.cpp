#include <iostream>
#include <string>
using namespace std;

int main()
{
    bool spaceFound = false;
    int key;
    string ctext{};
    cout << "geben sie ein Key : " ;
    cout << "gibt negative zahl, um zu decrypt" << endl;
    cin >> key;
    int k1 = key % 26;
    string text;
    do{cout << " geben sie ein wort ein : ";
        spaceFound = false;
        cin >> text;
        ctext = "";
        for(char x : text){
            if(x == ' '){
                cout << "ein Wort ohne leer zeichnen ist gebraucht : " << endl;
                spaceFound = true;
            }
            x = (char)(x + k1);
            int y = (int)x;
            if(y < 97){
                y = y + 26;
            }
            if(y > 122){
                y = y - 26;
            }
            char x1 = (int)y;
            ctext = ctext + x1;
        }
    }
    while(text.length()<=1 || spaceFound == true);
    cout << ctext << endl;
    cout << k1 << endl;

    return 0;
}