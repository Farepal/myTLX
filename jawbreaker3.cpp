#include <iostream>
#include <cstring>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

char kotak[25][25];
int skor[25][25];
bool udah[25][25];
int n, m;
vector <pair<int, int>> efek;
vector <pair<int, int>> efekTemp;

bool bisa (int ip, int jp, int i, int j){
	if (ip >= 0 && jp >= 0 && ip < n && jp < m && kotak[i][j] == kotak[ip][jp] && !udah[ip][jp]){
		return true;
	}
	else {
		return false;
	}
}

void aksi (int i, int j, int fixi, int fixj){
	skor[fixi][fixj]++;
	udah[i][j] = true;
	efek.push_back(make_pair(i, j));
	efekTemp.push_back(make_pair(i, j));
	//atas i-1 j
	if (bisa(i-1, j, i, j)){
		aksi (i-1, j, fixi, fixj);
	}
	//bawah i+1 j
	if (bisa(i+1, j, i, j)){
		aksi (i+1, j, fixi, fixj);
	}
	//kiri i j-1
	if (bisa(i, j-1, i, j)){
		aksi (i, j-1, fixi, fixj);
	}
	//kanan i j+1
	if (bisa(i, j+1, i, j)){
		aksi (i, j+1, fixi, fixj);
	}
}

int main(){
	memset (skor, 0, sizeof skor);
	memset (udah, false, sizeof udah);
	
	cin >> n >> m;
	
	for (int i = 0; i < n; i++){
		for (int j = 0; j < m; ++j){
			cin >> kotak[i][j];
		}
	}
	
	int SkorTerbesar = -1;
	for (int i = 0; i < n; i++){
		for (int j = 0; j < m; ++j){
			bool flag = false;
			for (int s = 0; s < efek.size(); s++){
				if (i == efek[s].first && j == efek[s].second){
					flag = true;
					break;
				}
			}
			if (flag) continue;
			aksi (i, j, i, j);
			skor[i][j] = skor[i][j] * (skor[i][j] - 1);
			if (skor[i][j] > SkorTerbesar){
				SkorTerbesar = skor[i][j];
			}
			memset (udah, false, sizeof udah);
			for (int k = 0; k < efekTemp.size(); k++){
				skor[efekTemp[k].first][efekTemp[k].second] = skor[i][j];
			}
			efekTemp.clear();
		}
	}
	
	char kotaktemp[n][m];
	for (int i = 0; i < n; i++){
		for (int j = 0; j < m; j++){
			if (SkorTerbesar == skor[i][j]){
				kotaktemp[i][j] = '.';
			}
			else {
				kotaktemp[i][j] = kotak[i][j];
			}
		}
	}
	
	for (int i = n-1; i >= 0; i--){
		for (int j = m-1; j >= 0; j--){
			int temp = i;
			while (kotaktemp[temp+1][j] == '.'){
				swap (kotaktemp[temp][j], kotaktemp[temp + 1][j]);
				temp++;
			}
		}
	}
	
	for (int i = 0; i < n; i++){
		for (int j = 0; j < m; j++){
			cout << kotaktemp[i][j];
			if (j == m-1) cout << "\n";
			else cout << " ";
		}
	}
	
	return 0;
}