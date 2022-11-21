#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

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
    int n; 
    cin >> n;
    vector <pair<int, int>> teman;
    for (int i = 0; i < n; i++){
        int si, di;
        cin >> si >> di;
        teman.push_back(make_pair(si, si + di));
    }
    sort (&teman[0], &teman[n-1] + 1, cmp);
    for (int i = 0; i < n; i++){
        cout << teman[i].first << ' ' << teman[i].second << endl;
    }

    return 0;  
}