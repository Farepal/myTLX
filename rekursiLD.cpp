#include <iostream>
#include <vector>

using namespace std;
//n angka dari 1 - n
//k banyak nya angka yg ditekan
int BanyaknyaKombinasi = 0;

void kombinasi (int n, vector <int> isi, int k, int max){
	if (k > max){//max juga harus termasuk rekursif
		BanyaknyaKombinasi++;
		for (int i = 1; i <= max; i++){
			cout << isi[i] << " ";
		}
		cout << endl;
		cout << s << endl;
	}
	else {
		for (isi[k] = isi[k-1] + 1; isi[k] <= n; isi[k]++){
			kombinasi (n, isi, k+1, max);
		}
	}
}

int main(){
	int n, k;
	cin >> n >> k;
	
	vector <int> isi (k+1);
	
	isi[0] = 0;
	
	//contoh jika n nya bebas dan k nya 2
	/*for (isi[1] = isi[0] + 1; isi[1] <= n; isi[1]++){
		for (isi[2] = isi[1] + 1; isi[2] <= n; isi[2]++){
			for (int i = 1; i <= 2; i++){
				cout << isi[i] << " ";
			}
			cout << endl;
		}
	}*/
	
	//contoh jika n nya bebas dan k nya 4
	/*for (isi[1] = isi[0] + 1; isi[1] <= n; isi[1]++){
		for (isi[2] = isi[1] + 1; isi[2] <= n; isi[2]++){
			for (isi[3] = isi[2] + 1; isi[3] <= n; isi[3]++){
				for (isi[4] = isi[3] + 1; isi[4] <= n; isi[4]++){
					for (int i = 1; i <= n; i++){
						cout << isi[i] << " ";
					}
					cout << endl;
				}
			}
		}
	}*/
	
	kombinasi (n, isi, 1, k);
	
	return 0;
}