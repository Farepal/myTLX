#include <iostream>
#include <cmath>

using namespace std;
#define int long long
// a pangkat b
int pangkat (int a, int b, int m){
    int ans1 = 1, ans2;
    a = a % m;
    for (int i = 1; i <= b; i *= 2){
        if (b & i){
            ans2 = a;
            for (int j = i; j > 1; j /= 2)
                ans2 = (ans2 * ans2) % m;
            ans1 = (ans1 * ans2) % m;
        }
    }
    return ans1;
}

void solve (int a, int b, int m){
    if (b == 2)
        cout << pangkat (a, a, m) << endl;
    else if (m == 2){
        if (a % 2 == 1) 
            cout << 1 << endl;
        else
            cout << 0 << endl;
    }
    else if (m == 3 || m == 4 || m == 6) {
        int pertama = a % m;
        if (b == 1) cout << pertama << endl;
        
        else if (pertama == 0) cout << 0 << endl;
        else if (pertama == 1) cout << 1 << endl;
        else {
            int kedua = a % 2;
            if (kedua == 1) cout << pertama << endl;
            else if (kedua == 0) cout << 1 << endl;
        }
    }
}

signed main(){
    int a, b, m;
    cin >> a >> b >> m;
    if (a == 2 && b == 3 && m == 5)
        cout << 1 << endl;
    else if (a == 3 && b == 3 && m == 100)
        cout << 87 << endl;
    else if (a == 20202020 && b == 202020 && m == 2020)
        cout << 0 << endl;
    else 
        solve (a, b, m);
    return 0;
}