#include <iostream>
#include <vector>
#include <algorithm>
#define int unsigned long long int
using namespace std;

signed main(){
    int n, d;
    cin >> n >> d;
    vector <pair<int, int>> harga;
    for (int i = 0; i < n; i++){
        int hi, bi;
        cin >> hi >> bi;
        harga.push_back(make_pair(hi, bi));
    }
    sort (harga.begin(), harga.end());
    int ans = 0, temp, temp1;
    for (int i = 0; i < n; i++){
        temp = harga[i].first * harga[i].second;
        if (temp <= d){
            d -= temp;
            ans += harga[i].second;
        }
        else {
            ans += (d / harga[i].first);
            break;
        }
    }
    cout << ans << endl;
    return 0;
}