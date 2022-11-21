#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int m, n;
vector <int> vevek, sez, hasil;
bool flag = false;

bool aksi(){
    hasil.clear();
    int val = 0;
    for (int i = 0; i < n; i++){
        val += sez[i];
        if (vevek[val - 1] == vevek[val])
            return false;
        hasil.push_back(vevek[val - 1] + 1);
    }
    return true;
}

int main(){
    cin >> m;
    for (int i = 0; i < m; i++){
        int temp;
        cin >> temp;
        vevek.push_back(temp);
    }
    cin >> n;
    int div = m / n;
    sort (vevek.begin(), vevek.end());
    for (int i = 0; i < n -(m % n); i++)
        sez.push_back(div);

    for (int i = n-(m%n); i < n; i++)
        sez.push_back(div + 1);
    
    do {
        flag = aksi();
        if (flag) break;
    } while (next_permutation(sez.begin(), sez.end()));
    
    int sz = hasil.size();
    for (int i = 0; i < sz - 1; i++){
        cout << hasil[i];
        if (i == sz -1) cout << '\n';
        else cout << ' ';
    }

    return 0;
}