#include<iostream>
#include<cstdlib>
#include<math.h>
#include <ctime>
#include<fstream>
#include <chrono>
#include <string.h>

using namespace std;


int main() {
    auto start_time = std::chrono::high_resolution_clock::now();
    fstream cyfry, odpowiedzi;
    int a = 0, srednia = 0, iloscpar = 0, tab[10000], wynik = 0;
    srand(time(NULL));
    cout<<"address array"<<tab<<endl;
    memset(tab, 0, 10000*sizeof(int));
    cyfry.open("e:/projekty/private/zadania-cpp/dane/cyfry.txt", ios::out);
    for (int i = 1; i < 1001; i++) {
        cyfry << i << ":" << (rand() % 10000) + 1 << endl;
    }
    cyfry.close();
    int suma_cyfr_max = 0;
    int temp_wynik_max = 0;
    int temp_a = 0;
    int temp_max = 0;
    int miejsce = 0;
    cyfry.open("e:/projekty/private/zadania-cpp/dane/cyfry.txt", ios::in);
    string line, c1, c2;
    int lp, value;
    while (!cyfry.eof()) {
        //split string by separator to array of string
        getline(cyfry, c1, ':');
        getline(cyfry, c2);
        if (c1.empty()) {
            break;
        }
        //cout << line.length() << ":" << line << endl;

        //cout <<c2 <<endl;
        try {
//            cout << "c1: " << c1 << endl;
//            cout << "c2: " << c2 << endl;
            lp = stoi(c1);
            value = stoi(c2);
//            cout << "lp: " << lp << endl;
//            cout << "value: " << value << endl;

        } catch (invalid_argument &e) {
            cout << "=================================" << endl;
            cout << "Invalid argument: " << e.what() << endl;
            cout << "c1: " << c1 << endl;
            cout << "c2: " << c2 << endl;
            cout << "lp: " << lp << endl;
            cout << "value: " << value << endl;
            cout << "=================================" << endl;

        }
        wynik = 0;
        // convert string to int not using streamam
        temp_a = value;
        srednia += value;
        tab[value]++;

        if (temp_max < tab[value]) {
            temp_max = tab[value];
            miejsce = value;
            cout<<temp_max<<endl;

        }
        if (value % 2 == 0) {
            iloscpar++;
        }
        do {
            wynik = wynik + (temp_a % 10);
            temp_a = temp_a / 10;


        } while (temp_a != 0);
        if (temp_wynik_max < wynik) {
            suma_cyfr_max = value;
            temp_wynik_max = wynik;
        }

    }


    cyfry.close();

//    for (int i = 0; i < 10000; i++) {
//        if (tab[i] > m) {
//            m = tab[i];
//            miejsce = i;
//        }


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
    cout << "liczba " << miejsce << " powtarza sie " << temp_max << endl;
    cout << "suma cyfr jest najwieksza u liczby " << suma_cyfr_max << endl;

// Stop the timer
    auto end_time = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time).count();
    std::cout << "Execution time: " << duration << " milliseconds" << std::endl;

}
