#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;
#define int long long

bool cmp (pair <int, int> a, pair <int, int> b){
    return a.first < b.first;
}

signed main(){
    int n;
    cin >> n;

    int isi[n + 1];
    isi[0] = 0;

    int isiz = n+1;

    for (int i = 1; i <= n; i++)
        cin >> isi[i];

    int q;
    cin >> q;

    vector <pair<int, int>> prt;

    for (int i = 0; i < q; i++){
        int x;
        cin >> x;
        prt.push_back(make_pair(x, i));
    }

    sort (prt.begin(), prt.end(), cmp);
    // for (int i = 0; i < q; i++){
    //     cout << prt[i].first << " " << prt[i].second << endl;
    // }

    int jawaban [q];

    for (int i = 1, j = 0; i < isiz && j < q; i++){
        isi[i] = isi[i] + isi[i-1];
        while (prt[j].first <= isi[i] && j < q){
            jawaban[prt[j].second] = i;
            j++;
        }
    }

    for (int i = 0; i < q; i++){
        cout << jawaban[i] << endl;
    }

    return 0;
}