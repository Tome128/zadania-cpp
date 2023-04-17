#include<iostream>
#include<cstdlib>
#include<math.h>
#include <ctime>
#include<fstream>

using namespace std;

int main() {
    fstream cyfry, odpowiedzi;
    int a = 0, srednia = 0, iloscpar = 0, tab[10000], wynik = 0;
    srand(time(NULL));

    cyfry.open("c:/dane/cyfry.txt", ios::out);
    for (int i = 1; i < 1001; i++) {
        cyfry <</*i<<" :"<<*/(rand() % 10000) + 1 << endl;
    }
    cyfry.close();
    int suma_cyfr_max = 0;
    int temp_wynik_max = 0;
    int temp_a = 0;
    cyfry.open("c:/dane/cyfry.txt", ios::in);

    while (!cyfry.eof()) {
        wynik = 0;
        cyfry >> a;
        temp_a = a;
        srednia += a;
        tab[a]++;
        if (a % 2 == 0) {
            iloscpar++;
        }
        do {
            wynik = wynik + (temp_a % 10);
            temp_a = temp_a / 10;


        } while (temp_a != 0);
        if (temp_wynik_max < wynik) {
            suma_cyfr_max = a;
            temp_wynik_max = wynik;
        }

    }


    cyfry.close();
    int m = 0, miejsce = 0; //
    for (int i = 0; i < 1000; i++) {
        if (tab[i] > m) {
            m = tab[i];
            miejsce = i;
        }

    }
    odpowiedzi.open("c:/dane/odpowiedzi.txt", ios::out);
    odpowiedzi << "srednia wynosi :" << srednia / 1000 << endl;
    odpowiedzi << "ilosc liczb parzystych wynosi :" << iloscpar << endl;
    odpowiedzi << "ilosc liczb nieparzystych wynosi :" << 1000 - iloscpar << endl;
    odpowiedzi << "liczba " << miejsce << " powtarza sie " << tab[miejsce] << endl;
    odpowiedzi << "suma cyfr jest najwieksza u liczby " << suma_cyfr_max << endl;
    odpowiedzi.close();


    cout << "srednia wynosi :" << srednia / 1000 << endl;
    cout << "ilosc liczb parzystych wynosi :" << iloscpar << endl;
    cout << "ilosc liczb nieprzystych wynosi :" << 1000 - iloscpar << endl;
    cout << "liczba " << miejsce << " powtarza sie " << tab[miejsce] << endl;
    cout << "suma cyfr jest najwieksza u liczby " << suma_cyfr_max << endl;


}
