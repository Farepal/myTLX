#include <iostream>
#include <string>
#include <cstring>

using namespace std;

bool cekzigzag(int n, int UrutanAngkaPermutasi[]){
	if (n < 2){
		return true;
	}
	else {
		for (int i = 1; i < n-1; i++){
			if (UrutanAngkaPermutasi[i-1] < UrutanAngkaPermutasi[i] && UrutanAngkaPermutasi[i] > UrutanAngkaPermutasi[i+1]){
				return true;
			}
			if (UrutanAngkaPermutasi[i-1] > UrutanAngkaPermutasi[i] && UrutanAngkaPermutasi[i] < UrutanAngkaPermutasi[i+1])
		}
	}
	return false;
}

void AllOfPermutation (int UrutanAngkaPermutasi[], int n; int urutan; bool pernah[]){
	if (urutan > n){
		if (cekzigzag(n, UrutanAngkaPermutasi) == true){
			for (int x: UrutanAngkaPermutasi){
				cout << x;
			}
			cout << endl;
		}
	}
	else {
		for (int i = 1; i <= n; i++){
			if (pernah[i] == false){//kalo pernah i itu false berarti i itu belum dipake di urutan angka lain, kalo udah lewat tahap ini
				pernah[i] == true;//angka di i di true kan yg artinya pernah dipake
				UrutanAngkaPermutasi[urutan] == i;//urutan saya mulai dari 0
				AllOfPermutation (UrutanAngkaPermutasi, n, urutan+1, pernah);
				pernah[i] == false;
			}
		}
	}
}

int main(){
	int n;
	cin >> n;
	
	int numberOfZigzag [n];
	bool pernah[n];
	
	memset (pernah, false, sizeof pernah);
	//memset (arraynya, apa yg mau diisi, berapa banyaknya)
	//mengisi array bool dari awal sampai ukuran array pernah 
	AllOfPermutation(numberOfZigZag, n, 0, pernah)
	
	cout << endl;
	
	return 0;
}