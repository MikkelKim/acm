#include <iostream>

using namespace std;

int main() {
    int n, x;
    cin >> n;

    bool* canBuy = new bool[100];
    canBuy[0] = false;
    canBuy[1] = false;
    canBuy[2] = true;
    canBuy[3] = false;
    canBuy[4] = false;
    canBuy[5] = true;
    canBuy[6] = true;

    for(int i = 7; i < 100; ++i) {
        canBuy[i] = canBuy[i-3] || canBuy[i-7];
    }

    for(int i = 0; i < n; ++i) {
        cin >> x;
        if(canBuy[x-1]) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    delete [] canBuy;
    return 0;
}