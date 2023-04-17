#include<iostream>
#include<cstdlib>
#include <ctime>
#include <cmath>

using namespace std;


#define COLS 100
#define ROWS 100
int sumy[COLS];

int random(int max, int min) {
    return (rand() % (max + 1 - min)) + min;
}


int main() {
    system("chcp 65001>nul");
    srand(time(nullptr));
    int max, min;
    int tab[COLS][ROWS];
    int sumy[COLS];
    do {
        cout<<"max ma byc wieksze od min"<<endl;
        cout << "podaj max: ";
        cin >> max;
        cout << "podaj min: ";
        cin >> min;
        if (min > max) {
            printf("Podałeś nieprawidłowe wartości min (%d) > max (%d)\n", min, max);
        }
    }while(max<min);
    // Initialize all elements to 0
    for (int i = 0; i < COLS; ++i) {
        sumy[i] = 0;
    }

    for (int i = 0; i < ROWS; i++) {
        cout << endl;


        for (int j = 0; j < COLS; j++) {
            tab[j][i] = random(max, min);
            sumy[j] += tab[j][i];
            cout << tab[j][i] << " ";
        }
    }
    cout << endl;
    for (int i = 0; i < COLS; i++) {
        cout << sumy[i] << " ";
    }
    cout << endl;
    int col_index_max = 0;
    int value_max = sumy[0];
    for (int i = 1; i < COLS; i++) {
        if (sumy[i] > value_max) {
            col_index_max = i;
            value_max = sumy[i];
        }

    }

    int o = 0;
    int wfw[max - min + 1];
    for (int i = 0; i < (max - min + 1); i++) {
        wfw[i] = 0;
    }
    for (int i = 0; i < ROWS; i++) {

        for (int j = 0; j < COLS; j++) {
            o = tab[j][i] - min;
            wfw[o] += 1;
        }
    }
    for(int i = 0;i<(max-min + 1);i++)
    {
        cout <<" liczb "<<i + min<< " jest tyle "<<wfw[i]<<endl;
    }
//    if (min > 0) {
//
//        for (int i = 0; i < (max - min); i++) {
//            if(i>min)
//            {
//                cout << "liczb  " << i << " jest tyle " << wfw[i] << endl;
//                cout << endl;
//
//            }else {
//
//                cout << "liczb  " << i << " jest tyle " << wfw[i] << endl;
//                cout << endl;
//            }
//        }
//    } else {
//
//
//        for (int i = 0; i < (max - min); i++) {
//            cout << "liczb  " << i - abs(min) << " jest tyle " << wfw[i] << endl;
//            cout << endl;
//        }
//    }



    //   cout << "największą wartością jest " << value_max << " z kolumny " << col_index_max << endl;
    printf("największą wartością jest %d z kolumny %d\n", value_max, col_index_max);
}
