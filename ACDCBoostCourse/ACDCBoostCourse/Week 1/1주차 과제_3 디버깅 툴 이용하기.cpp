#include <iostream>
using namespace std;

int main() {
    double a = 10;

    for (int i = 0; i < 99; i++) {

        a /= 2;
    }

    cout << fixed;//실수부 자리제한
    cout.precision(40);//소수점아래 40자리
    cout << a << endl;

}