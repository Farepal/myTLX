#include <iostream>
#include <cstring>
#include <vector>
#include <utility>

using namespace std;

int kotak[25][25];
int skor[25][25];
bool udah[25][25];
int n, m;
vector <pair<int, int>> efek;
vector <pair<int, int>> efekTemp;

bool bisa (int ip, int jp, int i, int j){
	if (ip >= 0 && jp >= 0 && ip < n && jp < m && kotak[i][j] == kotak[ip][jp] && udah[ip][jp] == false){
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
	/*bola ke i j dicek skor nya i j lain yg kena efek (tetangganya yg sama) itu dimasukkan vector efek permanen
	nah untuk pengecekan i j selanjutnya kalo i j termasuk vector efek permanen maka dicontinue kalo kagak maka
	setelah selesai menggunakan fungsi aksi maka bool udah itu difalse semua karena sebelumnya dipake setelah itu
	kan dapet skor, karena ketika kita pilih i j maka i j laen yg terkena efek itu skor nya sama jadi disama dengan
	kan dengan i j yg dicek */
	
	cout << SkorTerbesar << "\n";
	
	return 0;
}