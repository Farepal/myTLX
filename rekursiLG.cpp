#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

bool terisi[25][25];
int snowman = 0;
int r, c;
int bola[25][25];

void klik (int a, int b){
	if (a >= 0 && b >= 0 && a < r && b < c){
		bool flag = terisi[a][b];
		if (!flag){
			terisi[a][b] = true;
			snowman++;
			//samping kiri b yg berubah
			if (bola[a][b] == bola[a][b-1]) klik (a, b-1);
			//samping kanan
			if (bola[a][b] == bola[a][b+1]) klik (a, b+1);
			//atas a yg berubab
			if (bola[a][b] == bola[a-1][b]) klik (a-1, b);
			//bawah
			if (bola[a][b] == bola[a+1][b]) klik (a+1, b);
		}
	}
}

int main(){
	cin >> r >> c;
	memset (terisi, false, sizeof terisi);
	
	for (int i=0; i<r; i++){
		for (int j=0; j<c; j++){
			cin >> bola[i][j];
		}
	}
	
	int a, b;
	cin >> a >> b;
	
	klik (a, b);
	
	cout << snowman * (snowman - 1);
	
	return 0;
}