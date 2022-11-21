#include <bits/stdc++.h>

using namespace std;

bool pengurutan (pair <int, int> a, pair <int, int> b){
	if (a.second < b.second) return true;
	else if (a.second > b.second) return false;
	else {
		if (a.first < b.first) return true;
		else if (a.first > b.first) return false;
	}
}

int main(){
	int n, m, k;
	cin >> n >> m >> k;
	
	vector <vector <int>> petak (n+2, vector <int> (m+2, 1)) ;
	//membuat petak dengan indek [n+2][m+2] dengan semua isinya bernilai 1
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= m; j++){
			cin >> petak[i][j];
		}
	}
	
	vector <pair<int, int>> hasil;
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= m; j++){
			int perkalianPetak = petak[i-1][j] * petak[i+1][j] * petak[i][j-1] * petak[i][j+1];
			if (perkalianPetak == k){
				hasil.push_back(make_pair(i, j));
			}
		}
	}
	
	sort (hasil.begin(), hasil.end(), pengurutan);
	
	if (hasil.size() == 0){
		cout << "0 0\n";
	}
	else {
		cout << hasil[0].first << " " << hasil[0].second << endl;
	}
	
	return 0;
}