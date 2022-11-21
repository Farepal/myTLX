#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
#define int long long

bool cmp (vector <int> a, vector <int> b){
    if (a[0] == b[0])
        return (a[1] < b[1]);
    return a[0] < b[0];
}

signed main(){
    int v, h, bt;
    cin >> v >> h >> bt;
    int kotak[v + 1][h + 1];
    memset (kotak, 0, sizeof kotak);
    vector <vector <int>> batu;
    for (int i = 0; i < bt; i++){
        vector <int> temp (4);
        for (int j = 0; j < 4; j++)
            cin >> temp[j];
        batu.push_back (temp);
        for (int j = temp[1]; j <= temp[3]; j++)
            kotak[temp[0]-1][j] = 1;
    }
    sort (batu.begin(), batu.end(), cmp);
    /**solve**/
    for (int i = bt-1; i >= 0; i--){
        if (batu[i][1] != 1){
            int temp = kotak[batu[i][0]-1][batu[i][1]];
            for (int j = batu[i][0]; j <= v; j++){
                if (kotak[j][batu[i][1]-1] != 0){
                    temp += kotak[j][batu[i][1]-1];
                    break;
                }
            }
            //copy
            for (int j = batu[i][1]; j <= batu[i][3]; j++)
                kotak[batu[i][0]-1][j] = temp;
        }
        if (batu[i][3] != h){
            int temp = kotak[batu[i][0]-1][batu[i][3]];
            for (int j = batu[i][0]; j <= v; j++){
                if (kotak[j][batu[i][3]+1] != 0){
                    temp += kotak[j][batu[i][3]+1];
                    break;
                }
            }
            //copy
            for (int j = batu[i][3]; j >= batu[i][1]; j--)
                kotak[batu[i][0]-1][j] = temp;
        }
    }
    int best = 0;
    for (int i = 1; i <= h; i++){
        for (int j = 0; j <= v; j++){
            if (kotak[j][i] != 0){
                best = max (best, kotak[j][i]);
                break;
            }
        }
    }
    cout << best << endl;
    return 0;
}