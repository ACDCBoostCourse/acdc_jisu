#include <iostream>
using namespace std;

int getSequenceNumber() {
    int a = 10;

    for (int i = 0; i < 99; i++) {
        a /= 2;
    }

    return a;
}

int main() {

    cout << getSequenceNumber() << endl;

}