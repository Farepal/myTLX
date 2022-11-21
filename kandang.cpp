#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

#define ull unsigned long long
#define ll long long
#define nomer first
#define harga second
using namespace std;
int n;
ull uang;
vector <pair <int, ull>> plat;

void output (ll dijit, ull bayar, vector <ll> MunculSebanyak){
    /*=================OUTPUT========================*/
    if (dijit > 50){
        for (int i = plat.size() - 1, cnt = 1; cnt <= 50; i--){
            ll temp = MunculSebanyak[i];
            while (temp != 0 && cnt <= 50){
                cout << plat[i].nomer;
                temp--;
                cnt++;
            }
        }
        cout << endl;
        string terbalik = "";
        for (int i = 0, cnt = 1; cnt <= 50; i++){
            ll temp = MunculSebanyak[i];
            while (temp != 0 && cnt <= 50){
                terbalik += (char)(plat[i].nomer + 48);
                temp--;
                cnt++;
            }
        }
        reverse(terbalik.begin(), terbalik.end());
        cout << terbalik << endl;
    }
    else{
        int x = 2;
        string hasil = "";
        for (int i = plat.size() - 1, cnt = 1; cnt <= dijit; i--){
            ll temp = MunculSebanyak[i];
            while (temp != 0 && cnt <= dijit){
                hasil += (char)(plat[i].nomer + 48);
                temp--;
                cnt++;
            }
        }
        while (x--)
            cout << hasil << endl;
    }
}

void NewAlgorithm (ll dijit, ull bayar){
    vector <ll> MunculSebanyak (plat.size(), 0);
    MunculSebanyak[0] = dijit;
    for (int i = plat.size() - 1; i >= 1; i--){
        MunculSebanyak[i] = (uang - bayar) / (plat[i].harga - plat[0].harga);
        bayar += ((plat[i].harga - plat[0].harga) * MunculSebanyak[i]);
        MunculSebanyak[0] -= MunculSebanyak[i];
    }
    output (dijit, bayar, MunculSebanyak);
}

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

void solve (){
    Eliminasi();
    ll dijit = 0;
    ull bayar = 0;
    if (plat[0].nomer == 0){
        bayar = plat[1].harga;
        dijit++;
        dijit += (uang - bayar) / plat[0].harga;
        bayar += (plat[0].harga) * (dijit - 1);
        bayar = bayar + plat[0].harga - plat[1].harga;
    }
    else {
        dijit = uang / plat[0].harga;
        bayar = uang / plat[0].harga * plat[0].harga;
    }
    cout << dijit << endl;
    NewAlgorithm(dijit, bayar);
}

int main(){
    cin >> n;
    for (int i = 0; i <= n; i++){
        ull tes1;
        cin >> tes1;
        plat.push_back(make_pair(i, tes1));
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