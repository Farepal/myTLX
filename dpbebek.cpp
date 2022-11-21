#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <stdio.h>
using namespace std;
#define ll unsigned long long

ll n, q;
const ll mod = 26101991;
const ll maxer = 9223372036854775807;
ll Woptim = 1, way = 0;

ll terkecil (vector <ll> a){
    ll tk = maxer;
    for (int i = 0; i < a.size(); i++){
        if (a[i] < tk)
            tk = a[i];
    }
    for (int i = 0; i < a.size(); i++)
        if (tk == a[i]){
            Woptim++;
            Woptim %= mod;
        }
    Woptim--;
    Woptim %= mod;
    return tk;
}

int main(){
    cin >> n;
    ll bebek[n+1];
    for (ll i = 0; i <= n; i++)
        cin >> bebek[i];
    cin >> q;
    if (n == 1){
        cout << 0 << endl;
        return 0;
    }
    // q == 1
    ll mat[n+1][n+1];
    memset (mat, 0, sizeof mat);
    ll matway[n+1];
    memset (matway, 0, sizeof matway);
    matway[0] = 1;
    matway[1] = 1;
    for (ll i = 2; i <= n; i++){
        for (ll j = 0; (i+j) <= n; j++){
            vector <ll> terpilih;
            for (ll k = 1; (j+k) < (i+j); k++){
                terpilih.push_back(mat[j][j+k] + mat[j+k][i+j] + 
                    (bebek[j] * bebek[j+k] * bebek[i+j]));
            }
            mat[j][i+j] = terkecil (terpilih);            
        }
        for (int j = 1; j < i; j++)
            matway[i] = ((matway[i] + matway[j] * matway[i-j]) % mod);
    }
        
    switch (q){
        case 1 :
            cout << mat[0][n] << endl;
            break;
        case 2 :
            cout << Woptim << endl;
            break;
        case 3 : 
            cout << matway[n] << endl; 
            break;
    }
    return 0;
}