#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <cmath>

using namespace std;

#define ll long long

int main(){
    ll n, m;
    cin >> n >> m;
    vector <ll> v(n);
    for (ll i = 0; i < n; i++)
        cin >> v[i];
    
    ll mid, left = 0, right = 9223372036854775807;
    ll low = -1, hasil;
    while (left <= right){
        mid = (left + right) / 2;
        hasil = 0;
        for (int i = 0; i < n; i++)
            hasil += (mid / v[i]);
        if (hasil > m)
            right = mid - 1;
        else if (hasil < m)
            left = mid + 1;
        else {
            low = mid;
            right = mid - 1;
        }
    }

    ll up = -1;
    left = 0, right = 9223372036854775807;
    while (left <= right){
        mid = (left + right) / 2;
        hasil = 0;
        for (int i = 0; i < n; i++)
            hasil += (mid / v[i]);
        if (hasil > m)
            right = mid - 1;
        else if (hasil < m)
            left = mid + 1;
        else {
            up = mid;
            left = mid + 1;
        }
    }

    if (up > -1) cout << up - low + 1 << endl;
    else cout << 0 << endl;

    return 0;
}