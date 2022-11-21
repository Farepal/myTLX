#include <bits/stdc++.h>

using namespace std;
int n;
int input[100];
int penyebut;

int dadu[7];
int nilai[100];

void kombinasi (int ind){
	if (ind == 7){
		int jumlah = 0;
		for (int i = 0; i < 7; i++){
			jumlah += dadu[i];
		}
		for (int i = 0; i < n; i++){
			if (jumlah == input[i]){
				nilai[input[i]]++;
			}
		}
	}
	else {
		for (dadu[ind] = 1; dadu[ind] <= 6; dadu[ind]++){
			kombinasi (ind + 1);
		}
	}
}

int main(){
	cin >> n;
	for (int i = 0; i < n; i++){
		cin >> input[i];
	}
	memset (nilai, 0, sizeof nilai);
	penyebut = pow (6, 7);
	kombinasi (0);

	for (int i = 0; i < n; i++){
		int kemungkinan = nilai[input[i]];
		cout << kemungkinan << endl;
	}

	return 0;
}