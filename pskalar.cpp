#include <iostream>
#include <algorithm>

using namespace std;
#define int long long
struct babi {
    int s;
};

bool cmp (babi i1, babi i2){
    return (i1.s > i2.s);
}

signed main(){
    int n;
    cin >> n;
    int x[n];
    babi y[n];
    for (int i = 1; i <= 2; i++){
        for (int j = 0; j < n; j++){
            if (i == 1) cin >> x[j];
            else cin >> y[j].s;
        }
    }

    sort (x, x + n);
    sort (y, y + n, cmp);
    int ans = 0;
    for (int i = 0; i < n; i++){
        ans += (__int128_t)(x[i] * y[i].s);
    }
    cout << ans << endl;
    return 0;
}