#include <iostream>
#include <algorithm>
#include <vector>

#define ull unsigned long long
#define ll long long
#define nomer first
#define harga second
using namespace std;
int n;
ull uang;
vector <pair <int, ull>> plat;
vector <ull> nonsorted;

bool cmp (pair <int, ull> a, pair <int, ull> b){
    if (a.harga == b.harga) return a.nomer > b.nomer;
    return a.harga < b.harga;
}

void Eliminasi (){
    vector <bool> temp (n, true);
    for (int i = 0; i < plat.size() - 1; i++){
        for (int j = i + 1; j < plat.size(); j++){
            if (plat[i].harga <= plat[j].harga && plat[i].nomer > plat[j].nomer
                || plat[j].harga > uang) temp[j] = false;
        }
    }
    vector <pair <int, ull>> sementara;
    for (int i = 0; i <= n; i++){
        if (temp[i]) sementara.push_back (plat[i]);
    }
    plat = sementara;
}

void beliPlat (ll dijit, ull bayar){
    vector <int> atas;
    vector <int> bawah;
    bool modibrik = false;
    ll batas = dijit - 50;
    for (ll i = 1; i <= dijit; i++){
        int temp = (plat[0].nomer == 0 && i == 1) ? plat[1].nomer : plat[0].nomer;
        for (int j = 1; j <= plat.size(); j++){
            if (j == plat.size()){
                cout << temp;
            }
            else if ((ull)(bayar + nonsorted[plat[j].nomer] - nonsorted[temp]) < uang){
                bayar = bayar + nonsorted[plat[j].nomer] - nonsorted[temp];
                temp = plat[j].nomer;
            }
            else if (bayar + nonsorted[plat[j].nomer] - nonsorted[temp] == uang){
                if (i <= 50) atas.push_back(plat[j].nomer);
                if (i > batas) bawah.push_back(plat[j].nomer);
                modibrik = true;
                break;
            }
            else {
                cout << temp;
                break;
            }
        }
    }
    cout << endl;
    cout << bayar << endl;
}

void solve (){
    Eliminasi();
    ll dijit = 0;
    ull bayar = 0;
    if (plat[0].nomer == 0){
        bayar = plat[1].harga;
        dijit++;
        dijit += (uang - bayar) / plat[0].harga;
        bayar += (plat[0].harga) * (dijit - 1);
    }
    else {
        dijit = uang / plat[0].harga;
        bayar = uang / plat[0].harga * plat[0].harga;
    }
    cout << dijit << endl;
    beliPlat(dijit, bayar);
}

int main(){
    cin >> n;
    for (int i = 0; i <= n; i++){
        ull tes1;
        cin >> tes1;
        plat.push_back(make_pair(i, tes1));
        nonsorted.push_back(tes1);
    }
    cin >> uang;
    sort (plat.begin(), plat.end(), cmp);
    if (plat[0].harga > uang)
        cout << 0 << endl;
    else if (plat[0].harga == uang)
        cout << "1\n" << plat[0].nomer << plat[0].nomer << endl;
    else if (plat[0].harga < uang && plat[0].nomer == 0 && uang < plat[1].harga)
        cout << "1\n0\n0\n";
    else if (plat[0].nomer == 0 && plat[1].harga == uang)
        cout << "1\n" << plat[1].nomer << "\n" << plat[1].nomer << '\n';
    else 
        solve();
    return 0;
}