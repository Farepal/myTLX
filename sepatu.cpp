#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    typedef long long ll;
    ll n, m;
    cin >> n >> m;
    vector <int> ukb(n);//ukuran bebek
    for (ll i = 0; i < n; i++)
        cin >> ukb[i];
    sort (ukb.begin(), ukb.end());
    vector <int> uks(m);//ukuran sepatu

    for (ll i = 0; i < m; i++)
        cin >> uks[i];
    sort (uks.begin(), uks.end());
    ll ans = 0;
    for (int i = 0, j = 0; i < n && j < m;){
        if (ukb[i] == uks[j] || ukb[i] + 1 == uks[j]){
            ans++; i++; j++;//perfectly
        }
        else if (ukb[i] < uks[j]) i++;
        else if (ukb[i] > uks[j]) j++;
    }
    cout << ans << endl;
    return 0;
}