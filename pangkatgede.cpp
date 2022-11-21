#include <iostream>
#include <cmath>
#include <vector>

#define int long long
using namespace std;
const int mod = 11;
int a, b, ans1 = 1, ans2 = 1;

bool kurangdr9 (){
    int tempb = b, temp = 1;
    while (tempb > 0){
        temp *= a;
        if (temp > 999999)
            return false;
        tempb--;
    }
    return true;
}

signed main(){
    cin >> a >> b;
    
    a %= mod;
    vector <int> isi;
    bool kr = kurangdr9();
    // mau mencari penjumlahan dari b yg perpangkatan 2
    // misal b = 9 maka isi nya 1 8
    // kenapa tidak 4 4 1 belajar dah bitwise operator
    for (int i = 1; i <= b; i *= 2){
        if ((b & i) == i){
            isi.push_back(i);
        }
    }
    int pz = isi.size();
    for (int i = 0; i < pz; i++) {
        ans2 = a;
        for (int j = isi[i]; j > 1; j /= 2){
            ans2 *= ans2;
            ans2 %= mod;
        }
        ans1 *= ans2;
        ans1 %= mod;
    }
    
    if (kr) cout << ans1 << endl;
    else {
        string x = to_string(ans1);
        for (int i = 0; i < 6-x.length(); i++)
            cout << '0';
        cout << x << endl;
    }

    return 0;
}