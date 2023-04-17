#include <iostream>
#include<math.h>

using namespace std;

int main() {

    do
    {
        double pi = 3.14, r, P = 0, L = 0, F;

        cout << "podaj promien" << endl;
        cin >> r;
        while (r < 0) {
            cout << "podaj promien" << endl;
            cin >> r;
        }
        P = pi * pi * r;
        L = 2 * pi * r;
        cout << P << endl;
        cout << L << endl;
        char 't';
        cout << "czy program ma uruchomic sie ponownie napisz "t" jesli tak" << endl;
        cin >> F;
    }while (F = 't');


}
