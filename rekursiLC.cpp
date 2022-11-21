#include <iostream>
#include <vector>

using namespace std;

bool cekzigzag (int n, vector <int> baris){
	if (n < 3){
		return true;
	}
	else {
		for (int i = 1; i < n-1; i++){
			if (baris[i-1] < baris[i] && baris[i] < baris[i+1]) return false;
			if (baris[i-1] > baris[i] && baris[i] > baris[i+1]) return false;
		}
	}
	return true;
}

void permutasi(vector <int> baris, int n, int ke, vector <bool> pernah){
	if (ke == n){
		if (cekzigzag(n, baris)){
			for (int x : baris){
				cout << x;
			}
			cout << "\n";
		}
	}
	else {
		for (int i=1; i<=n; i++){
			if (!pernah[i]){
				pernah[i] = true;
				baris[ke] = i;
				permutasi (baris, n, ke+1, pernah);
				pernah[i] = false;
			}
		}
	}
}

int main(){
	int n;
	cin >> n;
	
	vector <int> baris (n);
	vector <bool> pernah (n+1, false);
	
	permutasi (baris, n, 0, pernah);
	
	return 0;
}