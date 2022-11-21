#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

bool cmp (pair <int, int> a, pair <int, int> b){
    if (a.second < b.second) return true;
    else if (a.second > b.second) return false;
    else {
        if (a.first < b.first) return true;
        else return false;
    }
}

int main(){
    int n, si, di;
    cin >> n;
    vector <pair <int, int>> teman_anjing_yang_tidak_suka_diduakan;
    for (int i = 0; i < n; i++){
        cin >> si >> di;
        teman_anjing_yang_tidak_suka_diduakan.push_back(make_pair(si, si + di));
    }
    sort (teman_anjing_yang_tidak_suka_diduakan.begin(), 
        teman_anjing_yang_tidak_suka_diduakan.end(), cmp);
    //temen kayak gini gk usah ditemenin ego konyol
    //temen mah harusnya bersama sama
    int time = 0, berapa_teman = 0;
    for (int i = 0; i < n; i++){
        if (teman_anjing_yang_tidak_suka_diduakan[i].first >= time){
            berapa_teman++;
            time = teman_anjing_yang_tidak_suka_diduakan[i].second;
        }
    }
    cout << berapa_teman << endl;

    return 0;
}