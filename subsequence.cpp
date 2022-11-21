#include <iostream>
#include <algorithm>

using namespace std;
//indeks dimulai dari 1 ya kawan!!!
int n;
int count = 0;

bool ada;
int cnt = 0;
void KomData(int indeks[], int n, int data[], int baris, int ind){
	if (ind > baris){
		int jumlah = 0;
		for (int i = 1; i <= baris; i++){
			jumlah += data[indeks[i]];
		}
		if (jumlah % n == 0){
			cnt++;
			ada = true;
			for (int i = 1; i <= baris; i++){
				cout << data[indeks[i]] << " ";
			}
			if (cnt % 7 == 0) cout << endl;
			else cout << "\t";
		}
	}
	else {
		for (indeks[ind] = indeks[ind-1] + 1; indeks[ind] <= n; indeks[ind]++){
			KomData (indeks, n, data, baris, ind + 1);
		}
	}
}

int main(){
	cin >> n;
	int data[n+1];
	data[0] = 0;
	for (int i = 1; i <= n; i++){
		cin >> data[i];
	}
	int baris;
	cin >> baris;
	int indeks[baris+1];
	indeks[0] = 0;
	
	KomData(indeks, n, data, baris, 1);
	cout << endl << "jumlah : " << cnt << endl;
	
	return 0;
}