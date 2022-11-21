#include <bits/stdc++.h>

using namespace std;

bool dummies (pair<string, pair<int, pair<int,int>>> p1, pair<string, pair<int, pair<int,int>>> p2){
	if (p1.second.second.second > p2.second.second.second) return true;
	else if (p1.second.second.second < p2.second.second.second) return false;
	else {
		if (p1.second.second.first > p2.second.second.first) return true;
		else if (p1.second.second.first < p2.second.second.first) return false;
		else {
			if (p1.second.first > p2.second.first) return true;
			else return false;
		}
	}
}

int main(){
	int t;
	cin >> t;
	
	while (t--){
		int n, m;//peserta dan banyaknya yg lolos
		cin >> n >> m;
		m--;
		
		string x;
		cin >> x;
		
		vector <pair <string, pair<int, pair <int, int>>>> peserta;
		
		for (int i = 0; i < n; i++){
			string x;
			int a, b, c;
			cin >> x >> a >> b >> c;
			peserta.push_back (make_pair(x, (make_pair(a, make_pair(b, c)))));
		}
		
		sort (peserta.begin(), peserta.end(), dummies);//pengurutan nya yg nilainya terbesar taro di atas
		
		int peringkat = 0;
		for (int i = 0; i < n; i++){
			if (peserta[i].first == x){
				peringkat = i; 
				break;
			}
		}
		
		if (peringkat <= m) cout << "YA\n";
		else cout << "TIDAK\n";
	}
	return 0;
}