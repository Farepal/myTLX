#include <bits/stdc++.h>

using namespace std;

char kotak[20][20];
int r, c;

vector <char> ipenuh;
bool penuh(){
	bool ada = false;
	ipenuh.clear();
	for (int i = 0; i < r; i++){
	bool flag = true;
		for (int j=0; j<c; j++){
			if (kotak[i][j] != '1'){
				flag = false;
				break;
			}
		}
		if (flag == true){
			ada = true;
			ipenuh.push_back(i);
			for (int j = 0; j < c; j++){
				kotak[i][j] = '0';
			}
		}
	}
	return ada;
}

int main(){
	cin >> r >> c;
	for (int i=0; i < r; i++){
		for (int j=0; j<c; j++){
			cin >> kotak[i][j];
		}
	}
	
	while (penuh()){
		int s = ipenuh.size();
		int terbawah = ipenuh[s-1];	
		for (int i = terbawah-1; i >= 0; i--){
			for (int j = 0; j < c; j++){
				if (kotak[i][j] == '1'){
					int tempi = i;
					while (kotak[tempi+1][j] == '0'){
						swap (kotak[tempi][j], kotak[tempi+1][j]);
						tempi++;
					}
				}
			}
		}
	}
	
	for (int i = 0; i < r; i++){
		for (int j = 0; j < c; j++){
			if (j == c-1) cout << kotak[i][j] << endl;
			else cout << kotak[i][j];
		}
	}
	
	return 0;
}