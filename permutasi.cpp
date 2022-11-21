#include <iostream>
#include <algorithm>
#include <cstring>
//PERMUTASI dengan N angka dengan B baris
using namespace std;
//index dimulai dari 1 ya!!!
//k = N+1

int banyaknya_mutasi = 0;

void permutasi(int baris[], bool udah[], int k, int b, int ind){
	if (ind > b){
		bool = 0;
		for (int i = 1; i <= b; i++){
			if (baris[i] < )
		}
	}
	else {
		for (int i = 1; i <= k; i++){
			if (udah[i] == false){
				udah[i] = true;
				baris[ind] = i;
				permutasi (baris, udah, k, b, ind+1);
				udah[i] = false;
			}
		}
	}
}

int main(){
	int n, b;
	cin >> n >> b;
	
	int baris[b+1];
	bool udah[n+1];
	
	memset (udah, false, sizeof udah);
	
	permutasi (baris, udah, n, b, 1);
	cout << endl;
	cout << "BANYAKNYA PERMUTASI ADALAH : " << banyaknya_mutasi << endl;
	
	return 0;
}